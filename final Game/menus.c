#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menus.h"

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

void initialiserMenu(SDL_Surface** screen,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,surface *logo,surface *Breturn,surface *black1,surface *black2,MenuSet *menuSet)
{

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		printf("Unable to initialize Mix : %s\n",Mix_GetError());

	menuSet->music=Mix_LoadMUS("music.mp3");
	menuSet->effect=Mix_LoadWAV("effect.wav");	
	
	SDL_WM_SetIcon(loadimage("icon.png"),NULL);
	SDL_WM_SetCaption("PLOTTWIST","PLOTTWIST");

	menuSet->running=1;
	menuSet->level=1;
	menuSet->nbrmenu=1;
	menuSet->time=0;
	menuSet->multij=0;
	menuSet->player=0;
	menuSet->game=0;
	menuSet->selection=1;

	bg->nbr=12;
	bg->num=0;
	bg->image=malloc(bg->nbr*(sizeof(SDL_Surface*)));

	buttons->nbr=4;
	buttons->num=0;
	buttons->image=malloc(buttons->nbr*(sizeof(SDL_Surface*)));

	levels->nbr=7;
	levels->num=0;
	levels->image=malloc(levels->nbr*(sizeof(SDL_Surface*)));

	players->nbr=3;
	players->num=0;
	players->image=malloc(players->nbr*(sizeof(SDL_Surface*)));

	settings->nbr=4;
	settings->num=0;
	settings->image=malloc(settings->nbr*(sizeof(SDL_Surface*)));

	logo->nbr=1;
	logo->num=0;
	logo->image=malloc(sizeof(SDL_Surface*));
	
	Breturn->nbr=1;
	Breturn->num=0;
	Breturn->image=malloc(sizeof(SDL_Surface*));

	black1->nbr=1;
	black1->num=0;
	black1->image=malloc(sizeof(SDL_Surface*));

	black2->nbr=1;
	black2->num=0;
	black2->image=malloc(sizeof(SDL_Surface*));
	
	*(bg->image) = loadimage("./layers/Layer1.gif");
	*(bg->image+1) = loadimage("./layers/Layer2.gif");
	*(bg->image+2) = loadimage("./layers/Layer3.gif");
	*(bg->image+3) = loadimage("./layers/Layer4.gif");
	*(bg->image+4) = loadimage("./layers/Layer5.gif");
	*(bg->image+5) = loadimage("./layers/Layer6.gif");
	*(bg->image+6) = loadimage("./layers/Layer7.gif");
	*(bg->image+7) = loadimage("./layers/Layer8.gif");
	*(bg->image+8) = loadimage("./layers/Layer9.gif");
	*(bg->image+9) = loadimage("./layers/Layer10.gif");
	*(bg->image+10)= loadimage("./layers/Layer11.gif");
	*(bg->image+11) = loadimage("./layers/Layer12.gif");

	*(logo->image) = loadimage("logo taille sur 1080.png");

	*(buttons->image) = loadimage("./buttons/0.png");
	*(buttons->image+1) = loadimage("./buttons/1.png");
	*(buttons->image+2) = loadimage("./buttons/2.png");
	*(buttons->image+3) = loadimage("./buttons/3.png");

	*(settings->image) = loadimage("./settings/1.png");
	*(settings->image+1) = loadimage("./settings/2.png");
	*(settings->image+2) = loadimage("./settings/3.png");
	*(settings->image+3) = loadimage("./settings/4.png");

	*(levels->image) = loadimage("./levels/0.png");
	*(levels->image+1) = loadimage("./levels/1.png");
	*(levels->image+2) = loadimage("./levels/2.png");
	*(levels->image+3) = loadimage("./levels/3.png");
	*(levels->image+4) = loadimage("./levels/4.png");
	*(levels->image+5) = loadimage("./levels/5.png");
	*(levels->image+6) = loadimage("./levels/6.png");

	*(black1->image) = loadimage("./levels/black.png");
	*(black2->image) = loadimage("./levels/black.png");

	*(players->image) = loadimage("./players/1.png");
	*(players->image+1) = loadimage("./players/2.png");
	*(players->image+2) = loadimage("./players/3.png");

	*(Breturn->image) = loadimage("return.png");

	logo->pos.x=((*screen)->w/2)-((*(logo->image))->w/2);
	logo->pos.y=40;

	buttons->pos.x=((*screen)->w/2)-((*(buttons->image))->w /2);
	buttons->pos.y=273;

	settings->pos.x=((*screen)->w/2)-((*(settings->image))->w/2);
	settings->pos.y=((*screen)->h/2)-((*(settings->image))->h/2);

	levels->pos.x=0;
	levels->pos.y=((*screen)->h/2)-((*(levels->image))->h/2);

	players->pos.x=((*screen)->w/2)-((*(players->image))->w/2);
	players->pos.y=((*screen)->h/2)-((*(players->image))->h/2);

	Breturn->pos.x=14;
	Breturn->pos.y=7;

	black1->pos.x=408;
	black1->pos.y=256;

	black2->pos.x=758;
	black2->pos.y=256;
}

void afficherMenu(SDL_Surface *screen,surface bg,surface buttons,surface settings,surface levels,surface players,surface logo,surface Breturn,surface black1,surface black2,MenuSet menuSet)
{
	SDL_BlitSurface(*(bg.image+(bg.num)) , NULL , screen , NULL);
	
	if (menuSet.nbrmenu==1)	//main
	{
		SDL_BlitSurface(*(logo.image), NULL , screen , &logo.pos);
		SDL_BlitSurface(*(buttons.image+(buttons.num)),NULL,screen,&buttons.pos);
	}

	if (menuSet.nbrmenu==2) //settings
	{
		SDL_BlitSurface(*(settings.image+(settings.num)),NULL,screen,&settings.pos);
	}

	if (menuSet.nbrmenu==3)  //levels menu
	{		
		SDL_BlitSurface(*(levels.image+(levels.num)),NULL,screen,&levels.pos);
		SDL_BlitSurface(*(Breturn.image),NULL,screen,&Breturn.pos);
		if (menuSet.level==1)
		{
			SDL_BlitSurface(*(black1.image),NULL,screen,&black1.pos);
			SDL_BlitSurface(*(black2.image),NULL,screen,&black2.pos);
		}
		if (menuSet.level==2)
			SDL_BlitSurface(*(black2.image),NULL,screen,&black2.pos);
	}

	if (menuSet.nbrmenu==4)  //players selection
	{		
		SDL_BlitSurface(*(players.image+(players.num)),NULL,screen,&players.pos);
		SDL_BlitSurface(*(Breturn.image),NULL,screen,&Breturn.pos);
	}
}

void inputClavier (MenuSet *menuSet, int *key)
{
	SDL_Event event;
	(*key)=0;
	if(SDL_PollEvent(&event)) 
	{
	        switch (event.type) 
		{
		    case SDL_QUIT: 
				(menuSet->running)=0;
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


void update (int key,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,MenuSet *menuSet)
{	
	
	switch (key)
	{
	case 1 : //escape
		if ((menuSet->nbrmenu)==4) //player selection
		{
			(menuSet->nbrmenu)=3; 
			if ((settings->num)==0 || (settings->num)==1)
				Mix_PlayChannel(-1,menuSet->effect,0);
		}
 		
		else if ((menuSet->nbrmenu)==2 || (menuSet->nbrmenu)==3) 
		{
			(menuSet->nbrmenu)=1; 
			if ((settings->num)==0 || (settings->num)==1)
				Mix_PlayChannel(-1,menuSet->effect,0);
		}

		else if ((menuSet->nbrmenu)==1) (menuSet->running)=0;
	break;
	case 2 : //down
		switch (menuSet->nbrmenu)
		{				
		case 1 : //main

			(buttons->num)++;
			if ((buttons->num)>=4) 
				(buttons->num)=1;
			break;

		case 2 : //settings

			if ((menuSet->selection)==1) 
				(menuSet->selection) =2;

			else if ((menuSet->selection)==2) 
				(menuSet->selection) =1;
			break;
		}
	break;
	case 3 : //up
		switch (menuSet->nbrmenu)
		{				
		case 1 : //main

			(buttons->num)--;
			if ((buttons->num)<=0)					
				(buttons->num)=3;

			break;

		case 2 : //settings

			if ((menuSet->selection)==1) 					
				(menuSet->selection) =2;

			else if ((menuSet->selection)==2) 	
				(menuSet->selection) =1;
			break;
		}
	break;
	case 4 : //rigth
		if ((menuSet->nbrmenu)==3)
		{
			if (menuSet->level==1)
			{
				(levels->num)++;
				if ((levels->num)==3) 
					(levels->num)=1;
			}

			if (menuSet->level==2)
			{
				(levels->num)++;
				if ((levels->num)==5) 
					(levels->num)=1;
			}

			if (menuSet->level==3)
			{
				(levels->num)++;
				if ((levels->num)==7) 
					(levels->num)=1;
			}
		}

		if ((menuSet->nbrmenu)==4)
		{
			(players->num)++;
			if ((players->num)==3) 
				(players->num)=1;
		}
	break;
	case 5 : //left
		if ((menuSet->nbrmenu)==3)
		{
			if (menuSet->level==1)
			{
				(levels->num)--;
				if ((levels->num)<=0) 
					(levels->num)=2;
			}

			if (menuSet->level==2)
			{
				(levels->num)--;
				if ((levels->num)<=0) 
					(levels->num)=4;
			}

			if (menuSet->level==3)
			{
				(levels->num)++;
				if ((levels->num)<=0) 
					(levels->num)=6;
			}
		}

		if (menuSet->nbrmenu==4)
		{
			(players->num)--;
			if ((players->num)<=0) 
				(players->num)=2;
		}
	break;
	case 6 : //return
		switch (menuSet->nbrmenu)
		{				
		case 1 :
			if ((buttons->num)==1) 
			{
				(menuSet->nbrmenu)=3; 
				if ((settings->num)==0 || (settings->num)==1)
					Mix_PlayChannel(-1,menuSet->effect,0);}//levels menu
			if ((buttons->num)==2) 
			{
				(menuSet->nbrmenu)=2;  
				if ((settings->num)==0 || (settings->num)==1)						
					Mix_PlayChannel(-1,menuSet->effect,0);} //settings
			if ((buttons->num)==3) (menuSet->running)=0; //quit
			break;

		case 2 : 
			(menuSet->nbrmenu)=1;  
			if ((settings->num)==0 || (settings->num)==1)
				Mix_PlayChannel(-1,menuSet->effect,0);
			break;

		case 3 :
			if ((levels->num)==1 || (levels->num)==3 || (levels->num)==5)
			{
				(menuSet->multij)=0;
				(menuSet->nbrmenu)=4; //choisir le joueur
				if ((settings->num)==0 || (settings->num)==1)						
					Mix_PlayChannel(-1,menuSet->effect,0);
			}
			if ((levels->num)==2 || (levels->num)==4 || (levels->num)==6)
			{
				(menuSet->multij)=1;
				(menuSet->game)=1;//le jeu commence directement
				if ((settings->num)==0 || (settings->num)==1)						
					Mix_PlayChannel(-1,menuSet->effect,0);
			}
			break;
		case 4 :
			if ((players->num)==1)
				(menuSet->player)=1; //delta
				
			if ((players->num)==2)
				(menuSet->player)=2; //alpha
			
			(menuSet->game)=1; //le jeu commence
			(menuSet->running)=0;
			break;
		}
	break;
	case 7 : //space
		switch (menuSet->nbrmenu)
		{				
		case 2 :
			switch (menuSet->selection)
			{
			case 1:
				if ((settings->num)==0) (settings->num)=2;					
				else if ((settings->num)==1) (settings->num)=3;					
				else if ((settings->num)==2) 
				{ 
					(settings->num)=0; 
					Mix_PlayChannel(-1,menuSet->effect,0);
				}				
				else if ((settings->num)==3)
				{ 
					(settings->num)=1; 
					Mix_PlayChannel(-1,menuSet->effect,0);
				}		
			break;
			case 2:
				if ((settings->num)==0) 
				{
					(settings->num)=1; 
					Mix_PlayChannel(-1,menuSet->effect,0);	
					Mix_PauseMusic();
				}				
				else if ((settings->num)==1)	
				{
					(settings->num)=0; 
					Mix_PlayChannel(-1,menuSet->effect,0);	
					Mix_ResumeMusic();
				}					
				else if ((settings->num)==2) {(settings->num)=3;     Mix_PauseMusic();}				
				else if ((settings->num)==3) {(settings->num)=2;     Mix_ResumeMusic();}
			break;
			}
			printf("\nnum :%d",settings->num);
	printf("\nselec :%d",menuSet->selection);
		break;//case2
		}// switch
	break;
	}//switch
	
	if((SDL_GetTicks()-(menuSet->time))>250)
	{	
		bg->num++;
		menuSet->time=SDL_GetTicks();
	}
    	if(bg->num >= 12) (bg->num) = 0;
}
