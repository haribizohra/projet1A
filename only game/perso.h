#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collisions.h"

#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

typedef struct {
	int numPerso;
	SDL_Surface* image[2];
	SDL_Rect frame[2];
	SDL_Rect pos;
	int collision;
	int velocity;
	float vitesse;
	float acc;
	int mvt; //0repos 1marche 2courir 3sauter
	int previousmvt;
	int vie;
	int score;
	float lastAnimated;
	int attack;
}perso;


void initialiserPerso(perso *p,int player);
void afficherPerso (perso p,SDL_Surface *screen);
void animPerso(perso *p);
void deplacementPerso(SDL_Event event,perso *p,SDL_Surface *mask,int scrollmask);

#endif
