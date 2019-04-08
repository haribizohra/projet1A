#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#ifndef GETPIXEL_H_INCLUDED
#define GETPIXEL_H_INCLUDED

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y);

#endif
