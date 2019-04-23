
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
	Vie vie;
	Score score;
	enigme enig;
	int gamestate=0;

	char string[20];

	
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());	

	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	TTF_Init();
	
	init_bg(&bg);
	initialiserEtoile(&etoile);
	initialiserLampe(&lampe);
	initialiserPerso(&pers,player);
	initialiser_ennemi(&ennemi);
	initChrono(&chrono);
	initialiserScore(&score);
	initialiserVie(&vie);
	init_enigme(&enig);
	
	SDL_Surface *won,*lost,*board;
	board=IMG_Load("./resources/blaka.png");
	SDL_Color couleureNoire ={0,0,0};
	won=TTF_RenderText_Blended (enig.police, "YOU WON", couleureNoire) ;
	lost=TTF_RenderText_Blended (enig.police, "YOU LOST", couleureNoire) ;
	
	SDL_Rect posWL,posBoard,posScore;
	posBoard.x=250;
	posBoard.y=150;
	posWL.x=480;
	posWL.y=230;
	posScore.x=490;
	posScore.y=350;

	//srand(time(NULL));


	while(done==1)
	{

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
			if ((collisionTrigo(pers.pos,ennemi.mvt[i].pos,2)==1))
			{
								
				pers.collision=1;				
				ennemi.collision[i]=1;
				if(i > ennemi.numEnnemi)
					{
					ennemi.nbrCollisions++;
					ennemi.numEnnemi=i;
					}
			}		
		}
		for(int i=0;i<etoile.nbrEtoiles;i++)
		{
			if (collisionTrigo(pers.pos,etoile.pos[i],2)==1)
			{			
				etoile.collision[i]=1;
				if(i > etoile.numEtoile)
					{
					etoile.nbrCollisions++;
					etoile.numEtoile=i;
					}
			}
		}
		for(int i=0;i<lampe.nbrLampes;i++)
		{
			if (collisionTrigo(pers.pos,lampe.pos[i],2)==1)
				lampe.collision[i]=1;
		}
	
		
		if(bg.camera.x<8560)
			scrolling(&bg,&lampe,&etoile,&ennemi,&pers,level);
	
		afficher_bg(bg,level,screen);

		animLampe(&lampe);
		afficherLampe(screen,lampe);

		animEtoile(&etoile);
		afficherEtoile(screen,etoile);
	
		deplacement_alea_ennemi(&ennemi,screen);
		animEnnemi(&ennemi);
		afficher_ennemi(ennemi,screen);

		if(   (bg.camera.x<8560)  ||  ( (bg.camera.x>=8560)&&(pers.pos.x<450) )   )		
			deplacementPerso(event,&pers);
		animPerso(&pers);
		afficherPerso (pers,screen);
	
		timer(&chrono,screen);
		
		nbVie(ennemi.nbrCollisions,&gameover,&vie,screen);
		afficherScore(screen,&score,bg,etoile.nbrCollisions);

		if( (bg.camera.x>=8560)&&(pers.pos.x>=450) ) 
		{
			if(enig.num==-1)
				generationAleatoire(&enig);
			afficherEnigme(&enig,screen);
			if(enig.correcte==-1)
				resoudreEnigme(&enig,event,screen);
		}
	
		if(enig.correcte==1)
		{
			SDL_BlitSurface(board,NULL,screen,&posBoard);
			SDL_BlitSurface(won,NULL,screen,&posWL);
			sprintf(string, "score = %d ", score.scoreActuel);
			
			score.texteScore =TTF_RenderText_Blended(score.police,string, couleureNoire);
			SDL_BlitSurface(score.texteScore, NULL, screen, &posScore);
		}
		if(enig.correcte==0 || vie.valVie==0 || SDL_GetTicks()>72000)
		{
			SDL_BlitSurface(board,NULL,screen,&posBoard);
			SDL_BlitSurface(lost,NULL,screen,&posWL);
			sprintf(string, "score = %d ", score.scoreActuel);

			score.texteScore =TTF_RenderText_Blended(score.police,string, couleureNoire);
			SDL_BlitSurface(score.texteScore, NULL, screen, &posScore);
		}
			
	
		SDL_Flip(screen);

	}

	
	TTF_Quit();
	
	return 0;
}
