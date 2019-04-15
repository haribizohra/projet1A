#include "menu.h"
#include "jeu.h"

int main()
{
	SDL_Surface *screen =NULL;
	surface backg,buttons,settings,levels,players,logo,Breturn,black1,black2;
	int key=0,runningGame=1,gameover=0;
	MenuSet menuSet;
	background bg;
	Etoile etoile;
	Lampe lampe;
	perso pers;
	Ennemi ennemi;
	Chrono chrono;
	Vie vie;
	Score score;

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());

	screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	if(screen==NULL)
		printf("Unable to set video mode: %s \n",SDL_GetError());

	initialiserMenu(&screen,&backg,&buttons,&settings,&levels,&players,&logo,&Breturn,&black1,&black2,&menuSet);
	init_bg(&bg);
	initialiserEtoile(&etoile);
	initialiserLampe(&lampe);
	initialiserPerso(&pers,menuSet.player);
	initialiser_ennemi(&ennemi);
	initChrono(&chrono);
	initialiserScore(&score);
	initialiserVie(&vie);
	//initialiserEnigme

		
	runMenu(&screen,&key,&menuSet,&backg,&buttons,&settings,&levels,&players,&logo,&Breturn,&black1,&black2);
	printf("fel main player =%d",menuSet.player);
	//screen=NULL;
	//screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	runGame(&screen,menuSet,&bg,&runningGame,&etoile,&lampe,&pers,&ennemi,&chrono,&vie,&score,&gameover);

	SDL_FreeSurface(screen);
	SDL_FreeSurface(*backg.image);
	SDL_FreeSurface(*logo.image);
	for(int i=0;i<4;i++)
		SDL_FreeSurface(*(buttons.image+i));
	for(int i=0;i<4;i++)
		SDL_FreeSurface(*(settings.image+i));
	for(int i=0;i<7;i++)
		SDL_FreeSurface(*(levels.image+i));
	for(int i=0;i<3;i++)
		SDL_FreeSurface(*(players.image+i));
	SDL_FreeSurface(*Breturn.image);
	SDL_FreeSurface(*black1.image);
	SDL_FreeSurface(*black2.image);
	Mix_FreeMusic(menuSet.music);
	Mix_FreeChunk(menuSet.effect);
}
