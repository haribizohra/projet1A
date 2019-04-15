#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "etoile.h"
#include "bg.h"
#include "lampe.h"
#include "perso.h"
#include "collisions.h"
#include "ennemi.h"
#include "chrono.h"
#include "vie.h"
#include "score.h"
#include "enigme.h"
#include "getpixel.h"
#include "menus.h"

#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

void runGame(SDL_Surface **screen, MenuSet menuSet,background *bg,int *done,Etoile *etoile,Lampe *lampe,perso *pers,Ennemi *ennemi,Chrono *chrono,Vie *vie,Score *score,int *gameover);

#endif
