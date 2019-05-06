#include "bg.h"
#include "collisions.h"


void init_bg(background *bg)
{
	bg->fixe[0]=IMG_Load("./resources/back.png");
	//bg->fixe[1]=IMG_Load("background2.jpg");
	//bg->fixe[2]=IMG_Load("background3.jpg");

	bg->scroll[0]=IMG_Load("./resources/scroll1.png");
	//bg->scroll[1]=IMG_Load("scroll2.jpg");
	//bg->scroll[2]=IMG_Load("scroll3.jpg");

	bg->mask=IMG_Load("./resources/scroll 1 mask.png");

	bg->camera.x=0;
	bg->camera.y=0;
	bg->camera.w=1080;
	bg->camera.h=720;
	bg->scrolling=0;
	bg->scrollmask=0;
}

void afficher_bg(background bg,int level,SDL_Surface *screen)
{
	SDL_BlitSurface(bg.fixe[level-1],NULL,screen,NULL);
	SDL_BlitSurface(bg.scroll[level-1],&bg.camera,screen,NULL);
}



void scrolling (background *bg,Lampe *l,Etoile *et,Ennemi *en,perso *p, int level)
{
		if(bg->scrolling==1)
		{
			p->pos.x-=10;			
			bg->camera.x+=10;
			bg->scrollmask+=10;
			for(int i=0;i<l->nbrLampes; i++)	
			{
				l->pos[i].x-=10;
			}
			for(int i=0;i<et->nbrEtoiles; i++)	
			{
				et->pos[i].x-=10;
			}
			for(int i=0;i<en->nbrEnnemis; i++)	
			{
				en->mvt[i].pos.x-=10;
				en->mvt[i].Xmax-=10;
				en->mvt[i].Xmin-=10;
				en->mvt[i].Xdest-=10;
			}
		}	
		if(p->pos.x>=400)
			bg->scrolling=1;
		if(p->pos.x<100)
			bg->scrolling=0;
				
}
