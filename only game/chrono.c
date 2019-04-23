#include "chrono.h"

void initChrono(Chrono *chrono)
{
	chrono->image=IMG_Load("./resources/chrono.png");

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

	if (SDL_GetTicks() - chrono->tempsPrecedent >= 6000) /* Si 6s au moins se sont écoulées */
        {
        	chrono->frame.x += chrono->frame.w;
		if(chrono->frame.x >= chrono->image->w-50)
			chrono->frame.x=760;
        	chrono->tempsPrecedent = SDL_GetTicks(); /* On met à jour le tempsPrecedent */
        }
	SDL_BlitSurface(chrono->image,&chrono->frame,screen,&chrono->pos);
}
