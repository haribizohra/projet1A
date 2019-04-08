#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include "ennemi.h"
#include "lampe.h"
#include "etoile.h"
#include "perso.h"


#ifndef COLLISIONS_H_INCLUDED
#define COLLISIONS_H_INCLUDED

typedef struct {
	int x,y;
}point;

int collisionBoundingBox(SDL_Rect first,SDL_Rect second);
int collisionTrigo (SDL_Rect first,SDL_Rect second,int cercle);
bool collisionmap (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran);


#endif
