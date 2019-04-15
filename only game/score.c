#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "score.h"
void initialiserScore(  Score *score )
{
	char string[20];
	SDL_Color couleurRose = {208, 82, 127};
	
	TTF_Init();
	score->fondScore = IMG_Load("./resources/bois.png");
	(score->police) = TTF_OpenFont("beauty.ttf", 35);
	score->scoreActuel=0;
	sprintf(string, "score = %d ", score->scoreActuel);
	//(score->texteScore)=TTF_RenderText_Blended(score->police,string, couleurRose);
	
}

void afficherScore(SDL_Surface *ecran , Score *score,int collision )
{
	score->posFond.x=700;
	score->posFond.y=20;
	score->posScore.x=score->posFond.x+20;
	score->posScore.y=score->posFond.y+20;
		
	SDL_Color couleurRose = {208, 82, 127};
	char scoreString[10]="" ; 
	 char string[20];
	//SDL_BlitSurface(score->fondScore, NULL, ecran,&score->posFond);
	//SDL_BlitSurface(score->texteScore, NULL, ecran,&score->posScore);
	if (collision>=1)

	{
		
		score->scoreActuel=score->scoreActuel+10;
		sprintf(string, "score = %d ", score->scoreActuel);
		SDL_FreeSurface(score->texteScore);
		(score->texteScore)=TTF_RenderText_Blended(score->police,string, couleurRose);
		 


	}
        
   }

    
;








