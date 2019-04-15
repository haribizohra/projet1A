#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#ifndef VIESCORE_H_INCLUDED
#define VIESCORE_H_INCLUDED


typedef struct Vie
{
	SDL_Surface* vie_img[4];
	SDL_Rect posVie;
	int valVie;	
}Vie;

void initialiserVie(Vie *vie);
void nbVie(int collision,int *gameOver ,Vie *vie,SDL_Surface *screen);



#endif
