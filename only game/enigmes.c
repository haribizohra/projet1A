#include "enigmes.h"

void init_enigme(enigme *e)
{
	e->questions[0].solution=3;

	e->questions[1].solution=1;

	e->questions[2].solution=2;

	e->police = TTF_OpenFont("./resources/coolvetica condensed rg.ttf", 50);
	e->num=-1;
	e->correcte=-1;

	SDL_Color couleureNoire ={0,0,0};

	e->questions[0].texteQ = TTF_RenderText_Blended (e->police,"what is the gaz that causes climate change?", couleureNoire) ;
	e->questions[0].texteR = TTF_RenderText_Blended (e->police, "1- azote    2-oxygene    3-CO2", couleureNoire) ;

	
	e->questions[1].texteQ = TTF_RenderText_Blended (e->police,"how can we prevent climate change?", couleureNoire) ;
	e->questions[1].texteR = TTF_RenderText_Blended (e->police, "1- drive cars less   2-sleep more    3-eat less", couleureNoire) ;
	

	e->questions[2].texteQ = TTF_RenderText_Blended (e->police,"which one of these is going to extinct due to the climate change?", couleureNoire) ;
	e->questions[2].texteR = TTF_RenderText_Blended (e->police, "1- bee     2-polar bear	 3-girafe", couleureNoire) ;
	
	e->vrai = IMG_Load("./resources/true.png");
	e->faux = IMG_Load("./resources/false.png");

	e->posTF.x=800;
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
	SDL_BlitSurface (e->questions[e->num].texteQ, NULL, screen, &e->posQ) ;
	SDL_BlitSurface (e->questions[e->num].texteR, NULL, screen, &e->posR) ;
}

void resoudreEnigme (enigme *e,SDL_Event event,SDL_Surface *screen)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_a:
			if(e->questions[e->num].solution==1)
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
			if(e->questions[e->num].solution==2)
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
			if(e->questions[e->num].solution==3)
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
