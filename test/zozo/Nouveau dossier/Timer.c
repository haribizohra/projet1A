#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Timer.h"

void initialiser_chrono(chronometre *chrono)
{
	chrono->chr=IMG_Load("chrono.png");
	chrono->pos_chr.x=30;
	chrono->pos_chr.y=30;

}
void afficher_chrono(chronometre chrono , SDL_Surface *screen)
{
	SDL_BlitSurface(chrono.chr,&chrono.frame,screen,&chrono.pos_chr);
	SDL_Flip(screen);

}

void set_chrono(int *gameOver , int pause , chronometre *chrono)
{
	int tempsActuel=0;
	int tempsPrec=0;
	int compteur=0;
	//imageLoad
	tempsActuel=SDL_GetTicks();
	while(*gameOver!=1 && compteur!=30)
	{
		if(tempsActuel-tempsPrec>=1000 && pause==0)
		{
			compteur++;				
		}

		if (compteur==60)
		{
			*gameOver=1;
		}
		chrono->frame.w = 280;
		chrono->frame.h = 338;
		chrono->frame.y = 47;
		switch(compteur)

		{
			case 0:case 5:	
				chrono->frame.x = 31+70*0;
				break;

			case 10:	
				chrono->frame.x = 31+70*1;	
				break;
			case 15:	
				chrono->frame.x = 31+70*2;
				break;
			case 20:	
				chrono->frame.x = 31+70*3;
				break;
			case 25:	
				chrono->frame.x = 31+70*4;
				break;
			case 30: 	
				chrono->frame.x = 31+70*5;
				break;
			case 35:	
				chrono->frame.x = 31+70*6;
				break;
			case 40:	
				chrono->frame.x = 31+70*7;
				break;
			case 45:	
				chrono->frame.x = 31+70*8;
				break;
			case 50:	
				chrono->frame.x = 31+70*9;
				break;
			case 55:	
				chrono->frame.x = 31+70*10;
				break;
			case 60:
				chrono->frame.x = 31+70*11;
				break;
		}
	}
}
