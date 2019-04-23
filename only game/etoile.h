#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef ETOILE_H_INCLUDED
#define ETOILE_H_INCLUDED

typedef struct {
	
	SDL_Surface *image[2];
	SDL_Rect pos[5];
	int num[5],nbrEtoiles,collision[5];
	int nbrCollisions,numEtoile;
	float lastAnimated;
	
}Etoile;

void initialiserEtoile(Etoile *e);
void afficherEtoile(SDL_Surface *bg,Etoile e);
void animEtoile(Etoile *e);


#endif
