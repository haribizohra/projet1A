#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menus.h"

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void runMenu(SDL_Surface **screen,int *key,MenuSet *menuSet,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,surface *logo,surface *Breturn,surface *black1,surface *black2);

#endif
