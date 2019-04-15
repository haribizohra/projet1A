#include "menus.h"

void runMenu(SDL_Surface **screen,int *key,MenuSet *menuSet,surface *bg,surface *buttons,surface *settings,surface *levels,surface *players,surface *logo,surface *Breturn,surface *black1,surface *black2)
{
	Mix_PlayMusic(menuSet->music,-1);
	
	while(menuSet->running==1)
	{
		inputClavier(menuSet,key);

		update(*key,bg,buttons,settings,levels,players,menuSet);

		afficherMenu(*screen,*bg,*buttons,*settings,*levels,*players,*logo,*Breturn,*black1,*black2,*menuSet);
		
	
	    	SDL_Flip(*screen);
	}
}
