#include "bg.h"
#include "collisions.h"


void init_bg(background *bg)
{
	bg->fixe[0]=IMG_Load("./resources/back.png");
	//bg->fixe[1]=IMG_Load("background2.jpg");
	//bg->fixe[2]=IMG_Load("background3.jpg");

	bg->scroll[0]=IMG_Load("./resources/scrolling.png");
	//bg->scroll[1]=IMG_Load("scroll2.jpg");
	//bg->scroll[2]=IMG_Load("scroll3.jpg");

	bg->camera.x=0;
	bg->camera.y=0;
	bg->camera.w=1080;
	bg->camera.h=720;
}

void afficher_bg(background bg,int level,SDL_Surface *screen)
{
	SDL_BlitSurface(bg.fixe[level-1],NULL,screen,NULL);
	SDL_BlitSurface(bg.scroll[level-1],&bg.camera,screen,NULL);
printf("dkhal lel bg");
}



void scrolling (background *bg,Lampe *l,Etoile *et,Ennemi *en,perso p, int level)
{
	
	{
		if(p.mvt==1)
		{
			bg->camera.x+=3;
			for(int i=0;i<l->nbrLampes; i++)	
			{
				l->pos[i].x-=3;
			}
			for(int i=0;i<et->nbrEtoiles; i++)	
			{
				et->pos[i].x-=3;
			}
			for(int i=0;i<en->nbrEnnemis; i++)	
			{
				en->mvt[i].pos.x-=3;
				en->mvt[i].Xmax-=3;
				en->mvt[i].Xmin-=3;
				en->mvt[i].Xdest-=3;
			}
		}		
		if(p.mvt==2)
			{
			bg->camera.x+=6;
			for(int i=0;i<l->nbrLampes; i++)	
			{
				l->pos[i].x-=6;
			}
			for(int i=0;i<et->nbrEtoiles; i++)	
			{
				et->pos[i].x-=6;
			}
			for(int i=0;i<en->nbrEnnemis; i++)	
			{
				en->mvt[i].pos.x-=6;
				en->mvt[i].Xmax-=6;
				en->mvt[i].Xmin-=6;
				en->mvt[i].Xdest-=6;
			}
		}
		if(p.mvt==3)
			{
			bg->camera.x+=8;
			for(int i=0;i<l->nbrLampes; i++)	
			{
				l->pos[i].x-=8;
			}
			for(int i=0;i<et->nbrEtoiles; i++)	
			{
				et->pos[i].x-=8;
			}
			for(int i=0;i<en->nbrEnnemis; i++)	
			{
				en->mvt[i].pos.x-=8;
				en->mvt[i].Xmax-=8;
				en->mvt[i].Xmin-=8;
				en->mvt[i].Xdest-=8;
			}
		}	
	}
}
