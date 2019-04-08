#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "Timer.h"


int main( )
{
    SDL_Surface *screen= NULL;
    int continuer = 1;
	chronometre chrono;
	SDL_Event event;
	int x,y ;
	int gameOver=0 ,pause=0;

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1020, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("chronometre", NULL);


initialiser_chrono(&chrono);



    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
	        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
set_chrono(&gameOver , pause ,&chrono);
 afficher_chrono(chrono , screen);      
    }

	SDL_FreeSurface(screen);
SDL_FreeSurface(chrono.chr);
    SDL_Quit();

    return EXIT_SUCCESS;
}
