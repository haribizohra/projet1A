#include "menu.h"


int main()
{

	SDL_Event event;
	SDL_Surface *screen =NULL,*bg[12],*buttons[4],*settings[4],*levels[7],*players[3],*logo =NULL,*Breturn,*black;
	SDL_Rect posButtons,posLevels,posLogo,posSettings,posPlayers,posBReturn,posBlack1,posBlack2;
	int done=1,time=0,menu=1,level=1,selection=1,key=0,multij=0,game=0,player=0;
	int nbg=0,nbut=0,nset=0,nlevel=0,nplayer=0;
	Mix_Music *music;
	Mix_Chunk *effect;

	initialiserMenu(&screen,bg,buttons,settings,levels,players,&logo,&Breturn,&black,&music,&effect,&posButtons,&posLevels, &posLogo,&posSettings,&posPlayers,&posBReturn,&posBlack1,&posBlack2);

	Mix_PlayMusic(music,-1);

while(done==1)
{
	time=SDL_GetTicks();
	
	input(&done,&key);

	update(key,&done,&menu,&selection,level,&multij,&game,&nbg,&nbut,&nset,&nlevel,&nplayer,effect,time,&player);

	afficherMenu(screen,bg,buttons,settings,levels,players,logo,Breturn,black,posButtons,posLevels,posLogo,posSettings, posPlayers,posBReturn,posBlack1,posBlack2,menu,level,nbg,nbut,nset,nlevel,nplayer);

    	SDL_Flip(screen);
    	SDL_Delay(200);

	if(1000/30>(SDL_GetTicks()-time))
		SDL_Delay(1000/30-(SDL_GetTicks()-time));
}

SDL_FreeSurface(screen);
for(int i=0;i<12;i++)
	SDL_FreeSurface(bg[i]);
for(int i=0;i<4;i++)
	SDL_FreeSurface(buttons[i]);
for(int i=0;i<4;i++)
	SDL_FreeSurface(settings[i]);
for(int i=0;i<7;i++)
	SDL_FreeSurface(levels[i]);
SDL_FreeSurface(logo);
for(int i=0;i<3;i++)
	SDL_FreeSurface(players[i]);
SDL_FreeSurface(Breturn);
SDL_FreeSurface(black);
Mix_FreeMusic(music);
Mix_FreeChunk(effect);

SDL_Quit;
}
