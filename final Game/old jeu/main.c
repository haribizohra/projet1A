#include "menu.h"
#include "jeu.h"

int main(int argc, char *argv[])
{
	SDL_Surface *screen =NULL;
	surface bg,buttons,settings,levels,players,logo,Breturn,black1,black2;
	int key=0,runningGame=1;
	MenuSet menuSet;
	background bg;
	Etoile etoile;
	Lampe lampe;
	perso pers;
	Ennemi ennemi;
	Chrono chrono;
	Vie vie;
	Score score;

	initialiserMenu(&screen,&bg,&buttons,&settings,&levels,&players,&logo,&Breturn,&black1,&black2,&menuSet);
	init_bg(&bg);
	initialiserEtoile(&etoile);
	initialiserLampe(&lampe);
	initialiserPerso(&pers,player);
	initialiser_ennemi(&ennemi);
	initChrono(&chrono);
	initialiserScore(&score);
	initialiserVie(&vie);
	//initialiserEnigme

		
	runMenu(&screen,&key,&menuSet,&bg,&buttons,&settings,&levels,&players,&logo,&Breturn,&black1,&black2);
	runGame(menuSet,&bg,&done,&etoile,&lampe,&pers,&ennemi,&chrono,&vie,&score,&gameover)

	SDL_FreeSurface(screen);
	SDL_FreeSurface(*bg.image);
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
