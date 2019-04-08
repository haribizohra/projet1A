#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
 
void deplacement_alea_ennemi(SDL_Rect *positionEnnemi , SDL_Surface *screen,int Xmin , int Xmax , int step)
{
	

	SDL_Rect positionInitiale;
	positionInitiale.x=positionEnnemi->x;

if((positionEnnemi->x)<= positionInitiale )//avancer
{
	// alea a et b : rand()%(b-a)+a
	positionEnnemi->x+= (rand()%(step-(Xmax-(positionEnnemi->x))))+Xmax-(positionEnnemi->x);

}
else if((positionEnnemi->x)> positionInitiale )//reculer
{
	
	positionEnnemi->x-= (rand()%(step-((positionEnnemi->x)-Xmin)))+(positionEnnemi->x)-Xmin;


}


