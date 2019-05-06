#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

SDL_Surface *loadimage(char name[]);
void initialiserMenu(SDL_Surface** screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[],SDL_Surface **logo,SDL_Surface **Breturn,SDL_Surface **black,Mix_Music **music,Mix_Chunk **effect, SDL_Rect *posButtons,SDL_Rect *posLevels,SDL_Rect *posLogo,SDL_Rect *posSettings,SDL_Rect *posPlayers,SDL_Rect *posCsm,SDL_Rect *posBReturn,SDL_Rect *posBlack1,SDL_Rect *posBlack2);

void afficherMenu(SDL_Surface* screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[],SDL_Surface *logo,SDL_Surface *Breturn,SDL_Surface *black,SDL_Rect posButtons,SDL_Rect posLevels,SDL_Rect posLogo,SDL_Rect posSettings,SDL_Rect posPlayers,SDL_Rect posCsm,SDL_Rect posBReturn,SDL_Rect posBlack1,SDL_Rect posBlack2,int menu,int level,int nbg,int nbut,int nset,int nlevel,int nplayer,int nCsm);

void input (int *done, int *key,SDL_Event *event);

void update (int key,int *done,int *menu,int *selection,int level,int *multij,int *game,int *nbg,int *nbut,int *nset,int *nlevel,int *nplayer,int *nCsm,Mix_Chunk *effect,int *player,int *Csm,int *time);

void updateSouris(SDL_Event event,int *done,int *menu,int *selection,int level,int *multij,int *game,int *nbg,int *nbut,int *nset,int *nlevel,int *nplayer,int *nCsm,Mix_Chunk *effect,int *player,int *Csm,int *time,SDL_Surface *screen,SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[]);

#endif
