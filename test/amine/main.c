#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "etoile.h"
#include "lampe.h"
#include "collisions.h"
#include "ennemi.h"


int main(int argc, char *argv[])
{
	SDL_Surface *screen =NULL;
	SDL_Event event;
	int done=1;
	Etoile etoile;
	Lampe lampe;
	Ennemi ennemi;
	SDL_Surface *bg;

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());	

	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	bg=IMG_Load("scrolling 2.png");
	initialiserEtoile(&etoile);
	initialiserLampe(&lampe);
	initialiser_ennemi(&ennemi);
	
	while(done==1)
	{

			if(SDL_PollEvent(&event)) 
			{
				switch (event.type) 
				{
				    case SDL_QUIT: 
						done=0;
						break;
				}
			}
		SDL_BlitSurface(bg,NULL,screen,NULL);
		animLampe(&lampe);
		afficherLampe(screen,lampe);

		animEtoile(&etoile);
		afficherEtoile(screen,etoile);
	
		deplacement_alea_ennemi(&ennemi,screen);
		animEnnemi(&ennemi);
		afficher_ennemi(ennemi,screen);

		SDL_Flip(screen);

	}
	
	return 0;
}
