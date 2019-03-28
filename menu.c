#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

SDL_Surface *loadimage(char name[]) 
{ 
	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(name);
	if( loadedImage != NULL ) 
	{ 
		optimizedImage = SDL_DisplayFormatAlpha( loadedImage ); 
		SDL_FreeSurface( loadedImage ); 
	}
	return optimizedImage; 
}

void initialiserMenu(SDL_Surface** screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface **logo,SDL_Surface **Breturn,SDL_Surface **black,Mix_Music **music,Mix_Chunk **effect, SDL_Rect *posButtons,SDL_Rect *posLevels,SDL_Rect *posLogo,SDL_Rect *posSettings,SDL_Rect *posPlayers,SDL_Rect *posBReturn,SDL_Rect *posBlack1,SDL_Rect *posBlack2)
{

	
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		printf("Unable to initialize Mix : %s\n",Mix_GetError());

	*music=Mix_LoadMUS("music.mp3");
	*effect=Mix_LoadWAV("effect.wav");	
	
	SDL_WM_SetIcon(loadimage("layer 0"),NULL);
	SDL_WM_SetCaption("PLOTTWIST","PLOTTWIST");

	*screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


	if(*screen==NULL)
		printf("Unable to set video mode: %s \n",SDL_GetError());

	bg[0] = loadimage("./layers/Layer1.gif");
	bg[1] = loadimage("./layers/Layer2.gif");
	bg[2] = loadimage("./layers/Layer3.gif");
	bg[3] = loadimage("./layers/Layer4.gif");
	bg[4] = loadimage("./layers/Layer5.gif");
	bg[5] = loadimage("./layers/Layer6.gif");
	bg[6] = loadimage("./layers/Layer7.gif");
	bg[7] = loadimage("./layers/Layer8.gif");
	bg[8] = loadimage("./layers/Layer9.gif");
	bg[9] = loadimage("./layers/Layer10.gif");
	bg[10] = loadimage("./layers/Layer11.gif");
	bg[11] = loadimage("./layers/Layer12.gif");

	*logo = loadimage("logo taille sur 1080.png");

	buttons[0] = loadimage("./buttons/0.png");
	buttons[1] = loadimage("./buttons/1.png");
	buttons[2] = loadimage("./buttons/2.png");
	buttons[3] = loadimage("./buttons/3.png");

	settings[0] = loadimage("./settings/1.png");
	settings[1] = loadimage("./settings/2.png");
	settings[2] = loadimage("./settings/3.png");
	settings[3] = loadimage("./settings/4.png");

	levels[0] = loadimage("./levels/0.png");
	levels[1] = loadimage("./levels/1.png");
	levels[2] = loadimage("./levels/2.png");
	levels[3] = loadimage("./levels/3.png");
	levels[4] = loadimage("./levels/4.png");
	levels[5] = loadimage("./levels/5.png");
	levels[6] = loadimage("./levels/6.png");

	*black = loadimage("./levels/black.png");

	players[0] = loadimage("./players/1.png");
	players[1] = loadimage("./players/2.png");
	players[2] = loadimage("./players/3.png");

	*Breturn = loadimage("return.png");

	posLogo->x=((*screen)->w/2)-((*logo)->w/2);
	posLogo->y=40;

	posButtons->x=((*screen)->w/2)-(buttons[0]->w/2);
	posButtons->y=273;

	posSettings->x=((*screen)->w/2)-(settings[0]->w/2);
	posSettings->y=((*screen)->h/2)-(settings[0]->h/2);

	posLevels->x=0;
	posLevels->y=((*screen)->h/2)-(levels[0]->h/2);

	posPlayers->x=((*screen)->w/2)-(players[0]->w/2);
	posPlayers->y=((*screen)->h/2)-(players[0]->h/2);

	posBReturn->x=14;
	posBReturn->y=7;

	posBlack1->x=408;
	posBlack1->y=256;

	posBlack2->x=758;
	posBlack2->y=256;
}

void afficherMenu(SDL_Surface* screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *logo,SDL_Surface *Breturn,SDL_Surface *black,SDL_Rect posButtons,SDL_Rect posLevels,SDL_Rect posLogo,SDL_Rect posSettings,SDL_Rect posPlayers,SDL_Rect posBReturn,SDL_Rect posBlack1,SDL_Rect posBlack2,int menu,int level,int nbg,int nbut,int nset,int nlevel,int nplayer)
{
	SDL_BlitSurface( bg[nbg] , NULL , screen , NULL);
	
	if (menu==1)	//main
	{
		SDL_BlitSurface( logo , NULL , screen , &posLogo);
		SDL_BlitSurface(buttons[nbut],NULL,screen,&posButtons);
	}

	if (menu==2) //settings
	{
		SDL_BlitSurface(settings[nset],NULL,screen,&posSettings);
	}

	if (menu==3)  //levels menu
	{		
		SDL_BlitSurface(levels[nlevel],NULL,screen,&posLevels);
		SDL_BlitSurface(Breturn,NULL,screen,&posBReturn);
		if (level==1)
		{
			SDL_BlitSurface(black,NULL,screen,&posBlack1);
			SDL_BlitSurface(black,NULL,screen,&posBlack2);
		}
		if (level==2)
			SDL_BlitSurface(black,NULL,screen,&posBlack2);
	}

	if (menu==4)  //players selection
	{		
		SDL_BlitSurface(players[nplayer],NULL,screen,&posPlayers);
		SDL_BlitSurface(Breturn,NULL,screen,&posBReturn);
	}
}

void input (int *done, int *key)
{
	SDL_Event event;
	(*key)=0;
	if(SDL_PollEvent(&event)) 
	{
	        switch (event.type) 
		{
		    case SDL_QUIT: 
				(*done)=0;
				break;

		    case SDL_KEYDOWN:

			if(event.key.keysym.sym==SDLK_ESCAPE)
			(*key)=1;//escape		
			
			if(event.key.keysym.sym==SDLK_DOWN)
			(*key)=2;//down

			if(event.key.keysym.sym==SDLK_UP)
			(*key)=3; //up
			
			if(event.key.keysym.sym==SDLK_RIGHT)
			(*key)=4;//rigth
			
			if(event.key.keysym.sym==SDLK_LEFT)
			(*key)=5;//left
			
			if(event.key.keysym.sym==SDLK_RETURN)
			(*key)=6;//return
			
			if(event.key.keysym.sym==SDLK_SPACE)
			(*key)=7;//space
			
                }//switch
        }
}


void update (int key,int *done,int *menu,int *selection,int level,int *multij,int *game,int *nbg,int *nbut,int *nset,int *nlevel,int *nplayer,Mix_Chunk *effect,int *player,int *time)
{
	int now=0;	
	
	switch (key)
	{
	case 1 : //escape
		if ((*menu)==4) //player selection
		{
			(*menu)=3; 
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
		}
 		
		else if ((*menu)==2 || (*menu)==3) 
		{
			(*menu)=1; 
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
		}

		else if ((*menu)==1) (*done)=0;
	break;
	case 2 : //down
		switch (*menu)
		{				
		case 1 : //main

		(*nbut)++;
			if ((*nbut)>=4) 
			{					
			(*nbut)=1;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			break;

		case 2 : //settings

			if ((*selection)==1) 
			{					
			(*selection) =2;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			else if ((*selection)==2) 
			{					
			(*selection) =1;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			break;
		}
	break;
	case 3 : //up
		switch (*menu)
		{				
		case 1 : //main

			(*nbut)--;
			if ((*nbut)<=0)
			{					
				(*nbut)=3;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}
			break;

		case 2 : //settings

			if ((*selection)==1) 
			{					
				(*selection) =2;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}

				else if ((*selection)==2) 
			{					
				(*selection) =1;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}
			break;
		}
	break;
	case 4 : //rigth
		if ((*menu)==3)
		{
			if (level==1)
			{
				(*nlevel)++;
				if ((*nlevel)==3) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==2)
			{
				(*nlevel)++;
				if ((*nlevel)==5) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==3)
			{
				(*nlevel)++;
				if ((*nlevel)==7) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
		}

		if ((*menu)==4)
		{
			(*nplayer)++;
			if ((*nplayer)==3) (*nplayer)=1;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}
	break;
	case 5 : //left
		if ((*menu)==3)
		{
			if (level==1)
			{
				(*nlevel)--;
				if ((*nlevel)<=0) (*nlevel)=2;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==2)
			{
				(*nlevel)--;
				if ((*nlevel)<=0) (*nlevel)=4;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==3)
			{
				(*nlevel)++;
				if ((*nlevel)<=0) (*nlevel)=6;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
		}

		if (*menu==4)
		{
			(*nplayer)--;
			if ((*nplayer)<=0) (*nplayer)=2;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}
	break;
	case 6 : //return
		switch (*menu)
		{				
		case 1 :
			if ((*nbut)==1) 
			{
				(*menu)=3; 
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);}//levels menu
			if ((*nbut)==2) 
			{
				(*menu)=2;  
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);} //settings
			if ((*nbut)==3) (*done)=0; //quit
			break;

		case 2 : 
			(*menu)=1;  
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			break;

		case 3 :
			if ((*nlevel)==1 || (*nlevel)==3 || (*nlevel)==5)
			{
				(*multij)=0;
				(*menu)=4; //choisir le joueur
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
			if ((*nlevel)==2 || (*nlevel)==4 || (*nlevel)==6)
			{
				(*multij)=1;
				(*game)=1;//le jeu commence directement
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
			break;
		case 4 :
			if ((*nplayer)==1)
				(*player)=1; //delta
				
			if ((*nplayer)==2)
				(*player)=2; //delta
			
			(*game)=1; //le jeu commence
			break;
		}
	break;
	case 7 : //space
		switch (*menu)
		{				
		case 2 :
			switch (*selection)
			{
			case 1:
				if ((*nset)==0) (*nset)=2;					
				else if ((*nset)==1) (*nset)=3;					
				else if ((*nset)==2) 
				{ 
					(*nset)=0; 
					Mix_PlayChannel(-1,effect,0);
				}				
				else if ((*nset)==3)
				{ 
					(*nset)=1; 
					Mix_PlayChannel(-1,effect,0);
				}		
			break;
			case 2:
				if ((*nset)==0) 
				{
					(*nset)=1; 
					Mix_PlayChannel(-1,effect,0);	
					Mix_PauseMusic();
				}				
				else if ((*nset)==1)	
				{
					(*nset)=0; 
					Mix_PlayChannel(-1,effect,0);	
					Mix_ResumeMusic();
				}					
				else if ((*nset)==2) {(*nset)=3;	Mix_PauseMusic();}				
				else if ((*nset)==3) {(*nset)=2;     Mix_ResumeMusic();}
			break;
			}
		break;//case2
		}// switch
	break;
	}//switch
	
	now=SDL_GetTicks();
	if((now-(*time))>250)
	{	
		(*nbg)++;
		(*time)=SDL_GetTicks();
	}
    	if((*nbg) >= 12) (*nbg) = 0;
}
