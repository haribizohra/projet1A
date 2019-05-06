#include "perso.h"

void initialiserPerso(perso *p,int player)
{
	p->image[0]=IMG_Load("./resources/delta.png");
	p->image[1]=IMG_Load("./resources/alpha.png");
	
	p->pos.x=120;
	p->pos.y=368;  //372
	p->pos.w=80;
	p->pos.h=128;
	p->numPerso=player-1;
	p->frame[0].y = 0;
	p->frame[0].x = 0;
	p->frame[0].w = 80;
	p->frame[0].h = 128;
	p->vie = 3;
	p->lastAnimated = 0;
	p->mvt=0;
	p->previousmvt=0;
	p->acc=0;
	p->attack=0;
	p->vitesse=0;
	p->velocity=0;
}

void afficherPerso (perso p,SDL_Surface *screen)
{
	if(p.mvt==3)
	{
		p.frame[p.numPerso].w=128;
	}	
	
	SDL_BlitSurface(p.image[p.numPerso],&p.frame[p.numPerso],screen,&p.pos);	    
}

void animPerso(perso *p)
{
				
	switch (p->mvt)
	{		
		case 0: //stop
			p->frame[p->numPerso].y=0;
			p->frame[p->numPerso].x=400;
		break;
	
		case 1: //marche
			if(SDL_GetTicks() - p->lastAnimated>=100)
			{
				p->frame[p->numPerso].y=128;
				p->frame[p->numPerso].x +=80;
				if (p->frame[p->numPerso].x >= 400 )
					{p->frame[p->numPerso].x = 0;
					p->mvt=0;}
				p->lastAnimated=SDL_GetTicks();
			}
		break;

		case 2: //courir
			if(SDL_GetTicks() - p->lastAnimated>=100)
			{
				p->frame[p->numPerso].y=0;
				p->frame[p->numPerso].x +=80;
				if (p->frame[p->numPerso].x >= 480 )
					{p->frame[p->numPerso].x = 0;
					p->mvt=0;}
				p->lastAnimated=SDL_GetTicks();
			}
		break;

		case 3: //sauter
			if(SDL_GetTicks() - p->lastAnimated>=100)
			{
				p->frame[p->numPerso].y=256;
				p->frame[p->numPerso].x +=128;
				if (p->frame[p->numPerso].x >= 768 )
					{p->frame[p->numPerso].x = 0;
					p->mvt=0;}
				p->lastAnimated=SDL_GetTicks();
			}
		break;
	}	
}	


void deplacementPerso(SDL_Event event,perso *p,SDL_Surface *mask,int scrollmask)
{
	int x,y;	
	float acceleration=0.5;
	
	if(p->mvt != p->previousmvt)
	{
		p->frame[p->numPerso].x=0;
		p->previousmvt = p->mvt;
	}

	switch(event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				p->mvt=1; //marcher
				if (p->collision==0)
					//p->pos.x+=3;
					p->vitesse+=acceleration;
					
			break;

			case SDLK_UP:
				p->mvt=3; //sauter
				if(p->pos.y==368)				
					p->velocity =-70;
			break;

			case SDLK_LEFT:
				if(p->vitesse>=2*acceleration)
				p->vitesse-=2*acceleration;
				else 
				p->vitesse=0;
			break;
	
			case SDLK_DOWN:
				p->vitesse=0;
			break;
		
			case SDLK_SPACE:
				p->attack=1;
			break;
			}
		break;
	
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT)
		    	{
				p->mvt=2;
				if (p->collision==0)
					p->pos.x+=6;
			}
			if(event.button.button == SDL_BUTTON_RIGHT)
		    	{
				p->mvt=3; //sauter
				if(p->pos.y==368)				
					p->velocity =-70;
			}
	  	break;
	/*
		case SDL_MOUSEBUTTONUP:			
			p->mvt=0;
	  	break;*/

		case SDL_MOUSEMOTION:
			if(event.motion.x > p->pos.x + 40)
			{
				p->mvt=1;
				if(p->collision==0)				
					p->pos.x+=4;
			}
			else p->mvt=0;
	   	break;
		
	/*	
		case SDL_KEYUP:				
			p->mvt=0;
		break;	*/				
	}
	//printf("%f  ",p->vitesse);
	p->pos.x+=p->vitesse;
	if(p->vitesse>5)
		p->mvt=2; //courir
	else if(p->vitesse>0)
		p->mvt=1;
	
	if((p->velocity <0))
	{			
		p->velocity+=10;		
		p->pos.y+=p->velocity; 
		p->pos.x+=15;
	}

	if (collisionmap(p->pos,mask,scrollmask)==0 && (p->velocity >=0))
		{                         
			
			p->velocity+=10; //gravité
			p->pos.y+=p->velocity;
			p->pos.x+=15;
		}
}
