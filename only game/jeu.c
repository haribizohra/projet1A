
#include "jeu.h"


int main(int argc, char *argv[])
{
	SDL_Surface *screen =NULL;
	SDL_Event event;
	background bg;
	int done=1,level=1,player=1,gameover=0,i;
	Etoile etoile;
	Lampe lampe;
	perso pers;
	Ennemi ennemi;
	Chrono chrono;
	Uint32 start;
	Vie vie;
	Score score;

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());	

	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	
	init_bg(&bg);
	initialiserEtoile(&etoile);
	initialiserLampe(&lampe);
	initialiserPerso(&pers,player);
	initialiser_ennemi(&ennemi);
	initChrono(&chrono);
	initialiserScore(&score);
	initialiserVie(&vie);
	//initialiserEnigme
	
	

	while(done==1)
	{

		start=SDL_GetTicks();
			if(SDL_PollEvent(&event)) 
			{
				switch (event.type) 
				{
				    case SDL_QUIT: 
						done=0;
						break;
				}
			}
		
		pers.collision=0;
		for(i=0;i<ennemi.nbrEnnemis;i++)
		{
			if ((collisionBoundingBox(pers.pos,ennemi.mvt[i].pos)==1))
			{
								
				pers.collision=1;				
				ennemi.collision[i]=1;
				if(i > ennemi.numEnnemi)
					{
					ennemi.nbrCollisions++;
					ennemi.numEnnemi++;
					}
			}		
		}
		for(int i=0;i<lampe.nbrLampes;i++)
		{
			if (collisionTrigo(pers.pos,lampe.pos[i],2)==1)
				lampe.collision[i]=1;
		}
		for(int i=0;i<etoile.nbrEtoiles;i++)
		{
			if (collisionTrigo(pers.pos,etoile.pos[i],2)==1)
				etoile.collision[i]=1;
		}
	
		
		if(bg.camera.x<8465)
			scrolling(&bg,&lampe,&etoile,&ennemi,&pers,level);
	
		afficher_bg(bg,level,screen);

		animLampe(&lampe);
		afficherLampe(screen,lampe);

		animEtoile(&etoile);
		afficherEtoile(screen,etoile);
	
		deplacement_alea_ennemi(&ennemi,screen);
		animEnnemi(&ennemi);
		afficher_ennemi(ennemi,screen);

		deplacementPerso(event,&pers);
		animPerso(&pers);
		afficherPerso (pers,screen);
	
		timer(&chrono,screen);
		
		nbVie(ennemi.nbrCollisions,&gameover,&vie,screen);
		afficherScore(screen,&score,/*etoile.collision[i]*/0);

		if(bg.camera.x>=8465)
			//afficherEnigme
			//resolutionEnigme
			;
	
		SDL_Flip(screen);

	}

	

	
	return 0;
}
