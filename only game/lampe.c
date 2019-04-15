#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lampe.h"


void initialiserLampe(Lampe *l)
{
	l->image[0]=IMG_Load("./resources/lampeON.png");
	l->image[1]=IMG_Load("./resources/lampeOFF.png");
	l->nbrLampes=3;

	l->col=0;
	l->previousCol=0;

	l->pos[0].x=2380;
	l->pos[1].x=4700;
	l->pos[2].x=7500;

	for(int j=0;j < l->nbrLampes;j++)
	{
		l->pos[j].y=250;		
		l->pos[j].w=l->image[0]->w;
		l->pos[j].h=l->image[0]->h;
		l->num[j]=0;
		l->collision[j]=0;
	}

	l->lastAnimated=0;
}


void afficherLampe(SDL_Surface *screen,Lampe l)
{
	for(int i=0;i < l.nbrLampes;i++)
	{	
		if(l.collision[i]==0)
			SDL_BlitSurface(l.image[l.num[i]],NULL,screen,&l.pos[i]);
	}
}

void animLampe(Lampe *l)
{
	for(int i=0;i < l->nbrLampes ;i++)
	{
		if(SDL_GetTicks()-l->lastAnimated >=100)
		{
			if(l->num[i]==0)
				l->num[i]=1;
			else if(l->num[i]==1)
				l->num[i]=0;
			l->lastAnimated =SDL_GetTicks();
		}
	}
}













/*

void initialiserLampe(Lampe *l)
{
	l->num=0;
	l->image[0]=IMG_Load("lampeON.png");
	l->image[1]=IMG_Load("lampeOFF.png");
	l->pos.x=2000;
	l->pos.y=370;
	l->pos.w=l->image[0]->w;	
	l->pos.h=l->image[0]->h;	
}



void afficherLampe(SDL_Surface *bg,Lampe l)
{
	SDL_BlitSurface(l.image[l.num],NULL,bg,&l.pos);
}

void animLampe(Lampe *l)
{
	if(SDL_GetTicks() - l->lastAnimated>=110)
	{
		if(l->num==0)
			l->num=1;
		else if(l->num==1)
			l->num=0;
		l->lastAnimated=SDL_GetTicks();
	}
}



void fadeIn()
{
	int i;
	SDL_Surface *surface;

	surface = IMG_Load("black.bmp");
	if(surface == NULL) 
	{
		fprintf(stderr, "Load image error: %s\n",
		SDL_GetError()); exit(-1);
	}
	else
	{
		for (i=2;i<=256;i<<=1) 
		{
			SDL_SetAlpha(surface,SDL_RLEACCEL | SDL_SRCALPHA,(Uint8)i);
			SDL_BlitSurface(surface,NULL,screen,NULL);
			update();
		}
	}
}
*/


