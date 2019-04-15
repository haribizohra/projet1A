#include "jeu.h"

void runGame(SDL_Surface **screen, MenuSet menuSet, background *bg, int *done, Etoile *etoile, Lampe *lampe, perso *pers, Ennemi *ennemi, Chrono *chrono, Vie *vie, Score *score, int *gameover)
{
	SDL_Event event;
	int i;
	
	while(*done==1)
	{
		if(SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			    case SDL_QUIT: 
					(*done)=0;
					break;
			}
		}
	
		deplacementPerso(event,pers);
/*
		printf("\nnumEnnemi=%d--",ennemi->numEnnemi);
		ennemi->coll=0;
		for(i=0;i<ennemi->nbrEnnemis;i++)
		{
			if ((collisionBoundingBox(pers->pos,ennemi->mvt[i].pos)==1))
			{
								
				ennemi->coll=1;				
				ennemi->collision[i]=1;
				printf("\ni=%d--",i);
				printf("\nnumEnnemi=%d--",ennemi->numEnnemi);
				printf("\nnbr=%d--",ennemi->nbrCollisions);
				if(i > ennemi->numEnnemi)
					{
					ennemi->nbrCollisions++;
					ennemi->numEnnemi++;
					}
			}		
		}
		for(int i=0;i<lampe->nbrLampes;i++)
		{
			if (collisionTrigo(pers->pos,lampe->pos[i],2)==1)
				lampe->collision[i]=1;
		}
		for(int i=0;i<etoile->nbrEtoiles;i++)
		{
			if (collisionTrigo(pers->pos,etoile->pos[i],2)==1)
				etoile->collision[i]=1;
		}
	
		
		if(ennemi->coll==0 && bg->camera.x<8465)
			scrolling(bg,lampe,etoile,ennemi,*pers,menuSet.level);*/
		
		afficher_bg(*bg,menuSet.level,*screen);

		animLampe(lampe);
		afficherLampe(*screen,*lampe);

		animEtoile(etoile);
		afficherEtoile(*screen,*etoile);
	
		deplacement_alea_ennemi(ennemi,*screen);
		animEnnemi(ennemi);
		afficher_ennemi(*ennemi,*screen);

	
		animPerso(pers);
		afficherPerso (*pers,*screen);
	
		timer(chrono,*screen);
		
		nbVie(ennemi->nbrCollisions,gameover,vie,*screen);
		afficherScore(*screen,score,/*etoile.collision[i]*/0);

		if(bg->camera.x>=8465)
			//afficherEnigme
			//resolutionEnigme
			;
	
		SDL_Flip(*screen);

	}
}
