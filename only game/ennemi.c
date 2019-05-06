#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"


void initialiser_ennemi ( Ennemi *e)
{	
	e->image = IMG_Load("./resources/ours.png");

	e->nbrEnnemis=5;

	e->mvt[0].pos.x=1690;
	e->mvt[1].pos.x=4120;
	e->mvt[2].pos.x=6130;
	e->mvt[3].pos.x=7120;
	e->mvt[4].pos.x=8700;

	for (int i=0;i< e->nbrEnnemis;i++)
	{		
		e->mvt[i].pos.y=410;
		e->mvt[i].pos.w=100;
		e->mvt[i].pos.h=82;
		e->frame[i].w=100;
		e->frame[i].h=82;
		e->frame[i].x=0;
		e->frame[i].y=0;
		e->collision[i]=0;
		e->mvt[i].Xmin=e->mvt[i].pos.x - 50;
		e->mvt[i].Xmax=e->mvt[i].pos.x + 50;
		e->mvt[i].Xdest = rand()% (e->mvt[i].Xmax - e->mvt[i].Xmin) + e->mvt[i].Xmin;
		e->mvt[i].direction=0; //repos
	}

	e->lastAnimated=0;
	e->numEnnemi=-1;
	e->nbrCollisions=0;
}



void afficher_ennemi(Ennemi e,SDL_Surface *screen)
{

	for(int i=0;i < e.nbrEnnemis ; i++)
	{
		
			SDL_BlitSurface(e.image, &e.frame[i], screen, &e.mvt[i].pos);
	}
}


void deplacement_alea_ennemi(Ennemi *e, SDL_Surface *screen,perso *p)
{

	if(p->attack!=1)
	{
		for(int i=0;i<e->nbrEnnemis;i++)
		{
			if(e->mvt[i].Xdest < e->mvt[i].pos.x)
			{
				e->mvt[i].pos.x-=1;
				e->mvt[i].direction=1; //gauche
			}
			else if(e->mvt[i].Xdest > e->mvt[i].pos.x)
			{
				e->mvt[i].pos.x+=1;
				e->mvt[i].direction=2; //droite
			}
			else if(e->mvt[i].Xdest == e->mvt[i].pos.x)
			{
				do
				{			
					e->mvt[i].Xdest = rand()% (e->mvt[i].Xmax - e->mvt[i].Xmin) + e->mvt[i].Xmin;
				}while (abs(e->mvt[i].Xdest - e->mvt[i].pos.x) < 20);
				e->mvt[i].direction=0; //repos
				e->frame[i].x=0;
			}
		}
	}	
	
}

void animEnnemi(Ennemi *e, perso *p)
{
	

	if(SDL_GetTicks() - e->lastAnimated>=2000)	

	{	
		if(p->attack==1)
		{
			for(int i=0;i<e->nbrEnnemis; i++)
				{	
					e->frame[i].y= e->image->h*2 / 3 ;
					e->frame[i].x += e->image->w / 3 ;
					if (e->frame[i].x >= e->image->w )
					e->frame[i].x = 0;	
					e->lastAnimated = SDL_GetTicks();
				}
		}
	}

		/*else if (e->mvt[i].pos.x>=40+p->pos.x && e->mvt[i].pos.x<=40+p->pos.x)
		{*/
		
		if(SDL_GetTicks() - e->lastAnimated>=100)
		{
			for(int i=0;i<e->nbrEnnemis; i++)
			{	
				switch (e->mvt[i].direction)
				{		
					case 0: //repos
						e->frame[i].x = e->image->w / 3 * 2 ;
					break;
	
					case 1: //gauche
							e->frame[i].y=0;
							e->frame[i].x += e->image->w / 3 ;
							if (e->frame[i].x >= e->image->w )
								e->frame[i].x = 0;
					break;

					case 2: //droite
							e->frame[i].y= e->image->h / 3 ;
							e->frame[i].x += e->image->w / 3 ;
							if (e->frame[i].x >= e->image->w )
								e->frame[i].x = 0;
					break;
				}	
				e->lastAnimated = SDL_GetTicks();
			}
		}
	


}



