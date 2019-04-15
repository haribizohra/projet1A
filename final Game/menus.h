#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

typedef struct {
	SDL_Surface **image;
	int nbr,num;
	SDL_Rect pos;
}surface;


typedef struct {
	int nbrmenu,level,player,multij,game,selection,running;
	float time;
	Mix_Music *music;
	Mix_Chunk *effect;
}MenuSet;


SDL_Surface *loadimage(char name[]);

void initialiserMenu(SDL_Surface** screen,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,surface *logo,surface *Breturn,surface *black1,surface *black2,MenuSet *menuSet);

void afficherMenu(SDL_Surface *screen,surface bg,surface buttons,surface settings,surface levels,surface players,surface logo,surface Breturn,surface black1,surface black2,MenuSet menuSet);

void inputClavier (MenuSet *menuSet, int *key);

void update (int key,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,MenuSet *menuSet);


#endif
