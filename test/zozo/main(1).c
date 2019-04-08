#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
/*#include "vieScore.h"*/

int main( )
{
    SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Surface *ennemi[5];
    SDL_Rect positionEnnemi;
    SDL_Event event;
    TTF_Font *police = NULL;
    int continuer = 1;
	int x,y ;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

	 initialiser_ennemi (ennemi);

    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
	        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	x=500;
	y=230;
 	afficher_ennemi( positionEnnemi , x ,y, ecran ,&ennemi[0]);
	deplacement_alea_ennemi(&positionEnnemi , ecran,100 , 200 , 50);
       
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    return EXIT_SUCCESS;
}
