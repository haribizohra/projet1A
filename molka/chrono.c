#include "chrono.h"

void initChrono(Chrono *chrono)
{
	chrono->image=IMG_Load("chrono.png");

	chrono->pos.x=300;
	chrono->pos.y=10;

	chrono->frame.x=0;
	chrono->frame.y=0;
	chrono->frame.w=chrono->image->w / 12;
	chrono->frame.h=chrono->image->h;
	
	chrono->numChrono=0;
}

void timer(Chrono *chrono, SDL_Surface *screen)
{

	if (SDL_GetTicks() - chrono->tempsPrecedent >= 5000) /* Si 5s au moins se sont écoulées */
        {
        	chrono->frame.x += chrono->frame.w;
		
        	chrono->tempsPrecedent = SDL_GetTicks(); /* On met à jour le tempsPrecedent */
        }
	SDL_BlitSurface(chrono->image,&chrono->frame,screen,&chrono->pos);
}
