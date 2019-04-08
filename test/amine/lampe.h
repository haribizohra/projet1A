#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef LAMPE_H_INCLUDED
#define LAMPE_H_INCLUDED

typedef struct {
	
	SDL_Surface *image[2];
	SDL_Rect pos[3];
	int num[3],nbrLampes,collision[3],col,previousCol;
	float lastAnimated;
}Lampe;

void initialiserLampe(Lampe *l);
void afficherLampe(SDL_Surface *bg,Lampe l);
void animLampe(Lampe *l);


#endif
