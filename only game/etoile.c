#include "etoile.h"


void initialiserEtoile(Etoile *e)
{
	e->image[0]=IMG_Load("./resources/etoile.png");
	e->image[1]=IMG_Load("./resources/etoile ptit.png");
	e->nbrEtoiles=5;
	e->numEtoile=0;
	e->nbrCollisions=0;
//	e->nbrEtoiles[1]=;
//	e->nbrEtoiles[2]=;

	for(int j=0;j < e->nbrEtoiles;j++)
	{
		e->pos[j].w=e->image[0]->w;
		e->pos[j].h=e->image[0]->h;
		e->num[j]=0;
		e->collision[j]=0;
	}

	e->lastAnimated=0;	

	e->pos[0].x=3000;
	e->pos[1].x=600;
	e->pos[2].x=1080;
	e->pos[3].x=5800;
	e->pos[4].x=7400;

	for(int i=0;i < e->nbrEtoiles;i++)	
		e->pos[i].y=250; //250
	/*
	e->pos[1][0].x=;
	e->pos[1][1].x=;
	e->pos[1][2].x=;
	e->pos[1][3].x=;
	e->pos[1][4].x=;
	e->pos[1][5].x=;
	e->pos[1][6].x=;
	for(int i=0;i < e->nbrEtoiles[1];i++)	
		e->pos[1][i].y=;

	e->pos[2][0].x=;
	e->pos[2][1].x=;
	e->pos[2][2].x=;
	e->pos[2][3].x=;
	e->pos[2][4].x=;
	e->pos[2][5].x=;
	e->pos[2][6].x=;
	for(int i=0;i < e->nbrEtoiles[2];i++)	
		e->pos[2][i].y=;
	*/
}


void afficherEtoile(SDL_Surface *screen,Etoile e)
{
	for(int i=0;i < 5 ;i++)	
	{
		if(e.collision[i]==0)
			SDL_BlitSurface(e.image[e.num[i]],NULL,screen,&e.pos[i]);
	}
}

void animEtoile(Etoile *e)
{		
	if(SDL_GetTicks()-e->lastAnimated >=150)
	{	
		for(int i=0;i < e->nbrEtoiles ;i++)
		{
			if(e->num[i]==0)
				e->num[i]=1;
			else if(e->num[i]==1)
				e->num[i]=0;
			e->lastAnimated=SDL_GetTicks();
		}
	}
}
