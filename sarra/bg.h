#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED

typedef struct {
	SDL_Surface *fixe[3];
	SDL_Surface *scroll[3];
	SDL_Rect camera;
	Mix_Music *music;
}background;

void init_bg(background *bg);
void afficher_bg(background bg,int level,SDL_Surface *screen);
void scrolling(background *bg,perso p);

#endif
