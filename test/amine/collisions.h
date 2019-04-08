#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <stdbool.h>


#ifndef COLLISIONS_H_INCLUDED
#define COLLISIONS_H_INCLUDED

typedef struct {
	int x,y;
}point;

int collisionTrigo (SDL_Rect first,SDL_Rect second,int cercle);


#endif
