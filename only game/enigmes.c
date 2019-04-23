#include "enigmes.h"

void init_enigme(enigme *e)
{
	// Enigme 1
	strcpy(e->questions[0].question,"what is the gaz that causes climate change?\n");
	stpcpy(e->questions[0].reponses,"1- gaz	2-gaz	3-gaz\n");
	e->questions[0].solution=3;

	//Enigme 2
	strcpy(e->questions[1].question,"how can we prevent climate change?\n");
	stpcpy(e->questions[1].reponses,"1- drive cars less	2-sleep more	3-eat less\n");
	e->questions[1].solution=1;

	//Enigme 3
	strcpy(e->questions[2].question,"which one of these is going to extinct due to the climate change?\n");
	stpcpy(e->questions[2].reponses,"1- bee	    2-polar bear	 3-girafe\n");
	e->questions[2].solution=2;

	e->police = TTF_OpenFont("./resources/coolvetica condensed rg.ttf", 65);
	e->num=-1;
	e->correcte=-1;

	e->questions[0].fond = IMG_Load ("./resources/bois.png");

	SDL_Color couleureNoire ={0,0,0};

	e->questions[0].texteQ = TTF_RenderText_Blended (e->police,"what is the gaz that causes climate change?", couleureNoire) ;
	e->questions[0].texteR = TTF_RenderText_Blended (e->police, "1- gaz    2-gaz    3-gaz", couleureNoire) ;
	
	e->vrai = IMG_Load("./resources/true.png");
	e->faux = IMG_Load("./resources/false.png");

	e->posTF.x=450;
	e->posTF.y=300;
	
}

void generationAleatoire(enigme *e)
{
	e->num=rand()%3;
	printf("\nenumm=%d",e->num);
}

void afficherEnigme(enigme *e,SDL_Surface *screen)
{
	e->posQ.x=130;
	e->posQ.y=140;
	e->posR.x=330;
	e->posR.y=220;		
	SDL_BlitSurface (e->questions[0].fond, NULL, screen, &e->posQ) ; 
	SDL_BlitSurface (e->questions[0].texteQ, NULL, screen, &e->posQ) ;
	SDL_BlitSurface (e->questions[0].texteR, NULL, screen, &e->posR) ;
}

void resoudreEnigme (enigme *e,SDL_Event event,SDL_Surface *screen)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_a:
			if(e->questions[0].solution==1)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else 
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}	
		break;

		case SDLK_b:
			if(e->questions[0].solution==2)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else 
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}
		break;

		case SDLK_c:
			if(e->questions[0].solution==3)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else 
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}
		break;
	}

}
