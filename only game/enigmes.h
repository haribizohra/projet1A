#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED

typedef struct {
	SDL_Surface *texteQ, *texteR;
	int solution;
}question;

typedef struct {
	SDL_Surface *vrai,*faux;
	SDL_Rect posTF;
	int correcte;
	question questions[3];
	TTF_Font *police;
	SDL_Rect posQ,posR;
	int num;
}enigme;

void init_enigme(enigme *e);
void generationAleatoire(enigme *e);
void afficherEnigme(enigme *e,SDL_Surface *screen);
void resoudreEnigme (enigme *e,SDL_Event event,SDL_Surface *screen);
#endif
