#include "bg.h"


void init_bg(background *bg)  
{
	bg->fixe[0]=IMG_Load("back.png");
	//bg->fixe[1]=IMG_Load("background2.jpg");
	//bg->fixe[2]=IMG_Load("background3.jpg");

	bg->scroll[0]=IMG_Load("scroll.png");
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
}



void scrolling (background *bg,perso p) // bch ybadl camera
{
	if(p.mvt==1) //marcher
	{
		bg->camera.x+=3;
	}		
	if(p.mvt==2) //courir
		{
		bg->camera.x+=5;
	}
	if(p.mvt==3)//sauter
		{
		bg->camera.x+=4;
	
}		
}
