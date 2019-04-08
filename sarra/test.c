#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bg.h"
#include "perso.h"

int main()
{
	SDL_Surface *screen =NULL;
	SDL_Event event;   
	background bg;
	int done=1,level=1,player=1;
	perso pers;

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());	

	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	init_bg(&bg);
	initialiserPerso(&pers,player);


	while(done==1)
	{
		if(SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			    case SDL_QUIT: // X
					done=0;
					break;
			}
		}

		deplacementPerso(event,&pers);
		scrolling(&bg,pers);
		animPerso(&pers);

		afficher_bg(bg,level,screen);
		afficherPerso (pers,screen);
	
		SDL_Flip(screen); //actualiser 

	}
	
	return 0;
}
