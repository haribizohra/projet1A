#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main()
{

	SDL_Event event;
	SDL_Surface *screen;
	SDL_Surface *bg[11];
	SDL_Surface *buttons[4];
	SDL_Surface *settings[4];
	SDL_Surface *levels[3];
	SDL_Surface *logo;
	SDL_Rect posButtons,posLevels,posLogo,posSettings;
	int done=1,time=0,menu=1;
	int nbg=0,nbut=0,nset=2,nlevel=0;
	int selection=1;
	Mix_Music *music;
	Mix_Chunk *effect;
	Uint8 volume,volume2;

	if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());


	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		printf("Unable to initialize Mix : %s\n",Mix_GetError());


	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	if(screen==NULL)
		printf("Unable to set video mode: %s \n",SDL_GetError());


	bg[0] = IMG_Load("./layers/Layer1.gif");
	bg[1] = IMG_Load("./layers/Layer2.gif");
	bg[2] = IMG_Load("./layers/Layer3.gif");
	bg[3] = IMG_Load("./layers/Layer4.gif");
	bg[4] = IMG_Load("./layers/Layer5.gif");
	bg[5] = IMG_Load("./layers/Layer6.gif");
	bg[6] = IMG_Load("./layers/Layer7.gif");
	bg[7] = IMG_Load("./layers/Layer8.gif");
	bg[8] = IMG_Load("./layers/Layer9.gif");
	bg[9] = IMG_Load("./layers/Layer10.gif");
	bg[10] = IMG_Load("./layers/Layer11.gif");
	bg[10] = IMG_Load("./layers/Layer11.gif");
	bg[11] = IMG_Load("./layers/Layer12.gif");

	logo = IMG_Load("logo taille sur 1080.png");

	buttons[0] = IMG_Load("./buttons/0.png");
	buttons[1] = IMG_Load("./buttons/1.png");
	buttons[2] = IMG_Load("./buttons/2.png");
	buttons[3] = IMG_Load("./buttons/3.png");

	settings[0] = IMG_Load("./settings/1.png");
	settings[1] = IMG_Load("./settings/2.png");
	settings[2] = IMG_Load("./settings/3.png");
	settings[3] = IMG_Load("./settings/4.png");

	levels[0] = IMG_Load("./levels/1.png");
	levels[1] = IMG_Load("./levels/2.png");
	levels[2] = IMG_Load("./levels/3.png");

	for(int i=0;i<4;i++)	
		SDL_SetColorKey(buttons[i],SDL_SRCCOLORKEY,SDL_MapRGB(buttons[i]->format,255,255,255));

	for(int i=0;i<4;i++)	
		SDL_SetColorKey(settings[i],SDL_SRCCOLORKEY,SDL_MapRGB(settings[i]->format,255,255,255));

	for(int i=0;i<3;i++)	
		SDL_SetColorKey(levels[i],SDL_SRCCOLORKEY,SDL_MapRGB(levels[i]->format,255,255,255));

	posLogo.x=(screen->w/2)-(logo->w/2);
	posLogo.y=40;

	posButtons.x=(screen->w/2)-(buttons[nbut]->w/2);
	posButtons.y=273;

	posSettings.x=(screen->w/2)-(settings[nset]->w/2);
	posSettings.y=(screen->h/2)-(settings[nset]->h/2);

	posLevels.x=14;
	posLevels.y=7;

    	SDL_BlitSurface( bg[nbg] , NULL , screen , NULL);
	SDL_BlitSurface( buttons[nbut] , NULL , screen , &posButtons);
	SDL_BlitSurface( logo , NULL , screen , &posLogo);
    	SDL_Flip(screen);

 	music=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
	
	effect=Mix_LoadWAV("effect.wav");


while(done==1)
{

	time=SDL_GetTicks();

	if(SDL_PollEvent(&event)) 
	{
	        switch (event.type) 
		{
		    case SDL_QUIT: 
			
			done=0;
			break;

		    case SDL_KEYDOWN:

			if(event.key.keysym.sym==SDLK_ESCAPE)
			{
				if (menu==2 || menu==3) {menu=1; Mix_PlayChannel(-1,effect,0);}
				else if (menu==1) done=0;
			}

			if(event.key.keysym.sym==SDLK_DOWN)
			{
				switch (menu)
				{				
				case 1 :
					nbut++;
					if (nbut>=4) nbut=1;
					break;
				case 2 :
					if (selection==1) selection =2;
					else if (selection==2) selection =1;
					break;
				}
			}

			if(event.key.keysym.sym==SDLK_UP)
			{
				switch (menu)
				{				
				case 1 :
					nbut--;
					if (nbut<=0) nbut=3;
					break;
				case 2 :
					if (selection==1) selection =2;
					else if (selection==2) selection =1;
					break;
				}
			}

			if(event.key.keysym.sym==SDLK_RETURN)
			{
				switch (menu)
				{				
				case 1 :
					if (nbut==1) {menu=3; Mix_PlayChannel(-1,effect,0);}//levels menu
					if (nbut==2) {menu=2;  Mix_PlayChannel(-1,effect,0);} //settings
					if (nbut==3) done=0; //quit
					break;

				case 2 : 
					menu=1;  Mix_PlayChannel(-1,effect,0);
					break;
				}
			}

			if(event.key.keysym.sym==SDLK_SPACE)
			{
				switch (menu)
				{				
				case 2 :
					switch (selection)
					{
					case 1:
						if (nset==0) nset=2;					
						else if (nset==1) nset=3;					
						else if (nset==2) nset=0;				
						else if (nset==3) nset=1;
					break;
					case 2:
						if (nset==0) {nset=1;	Mix_PauseMusic();}				
						else if (nset==1) {nset=0;	Mix_ResumeMusic();}				
						else if (nset==2) {nset=3;	Mix_PauseMusic();}				
						else if (nset==3) {nset=2;     Mix_ResumeMusic();}
					break;
					}
					break;//case2
				}// switch
			}//if
                }//switch event type
        }//if poll event

	

    	SDL_BlitSurface( bg[nbg] , NULL , screen , NULL);
	
	if (menu==1)	
	{
		SDL_BlitSurface( logo , NULL , screen , &posLogo);
		SDL_BlitSurface(buttons[nbut],NULL,screen,&posButtons);
	}

	if (menu==2)
	{
		SDL_BlitSurface(settings[nset],NULL,screen,&posSettings);
	}

	if (menu==3)
		SDL_BlitSurface(levels[nlevel],NULL,screen,&posLevels);
	
    	SDL_Flip(screen);
    	SDL_Delay(200);

    	nbg++;

    	if(nbg >= 12) nbg = 0;

	if(1000/30>(SDL_GetTicks()-time))
		SDL_Delay(1000/30-(SDL_GetTicks()-time));
	
}//while

SDL_FreeSurface(screen);
for(int i=0;i<12;i++)
SDL_FreeSurface(bg[i]);
for(int i=0;i<4;i++)
SDL_FreeSurface(buttons[i]);
for(int i=0;i<4;i++)
SDL_FreeSurface(settings[i]);
for(int i=0;i<3;i++)
SDL_FreeSurface(levels[i]);
SDL_FreeSurface(logo);
Mix_FreeMusic(music);

SDL_Quit;
}
