#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef CHRONO_H_INCLUDED
#define CHRONO_H_INCLUDED

typedef struct {
	
	SDL_Surface *image;
	SDL_Rect frame,pos;
	int numChrono;
	int tempsPrecedent;
}Chrono;

void initChrono(Chrono *chrono);
void timer(Chrono *chrono, SDL_Surface *screen);


#endif
