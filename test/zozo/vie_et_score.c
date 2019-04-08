#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "tools.h"
void score( SDL_Surface *personnage , SDL_Surface *etoile)
{
	int score;	
	collision=collisionTrigo(personnage,etoile,1);
	if (collision==1)
	score=score+10;
	

        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */

        position.x = 20;
        position.y = 10;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);
    }

} 
int vie(SDL_Surface (*vie)[] , SDL_Rect positionVie ,SDL_Surface *screen , SDL_Surface *personnage , SDL_Surface *ennemi[] )
{
	int gameOver=0;
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Unable to initialize SDL : %s\n",SDL_GetError());
	}
    	(*vie)[0] = SDL_LoadBMP("0 vie.bmp");
	(*vie)[1] = SDL_LoadBMP("1 vie.bmp");
	(*vie)[2] = SDL_LoadBMP("2 vie.bmp");
	(*vie)[3] = SDL_LoadBMP("3 vie.bmp");
	for(i=0;i>4;i++)
	{
		SDL_SetColorKey(vie[i], SDL_SRCCOLORKEY, SDL_MapRGB((vie[i])->format, 0, 0, 0));
	}

	if (collision && vie!=0)
	vie --;
	 if (vie==0)
	{
		gameOver=1;
		SDL_BlitSurface(vie[0], NULL, screen, &positionVie);
	}
 	else if (vie==1)
	{
		SDL_BlitSurface(vie[1], NULL, screen, &positionVie);
	}
	 else if (vie==2)
	{
		SDL_BlitSurface(vie[2], NULL, screen, &positionVie);
	}
	 else if (vie==3)
	{
		SDL_BlitSurface(vie[3], NULL, screen, &positionVie);
	}
	
    SDL_Flip(screen);
	
return(gameOver);	

} 
