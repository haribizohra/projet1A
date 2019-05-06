#include "collisions.h"
#include "getpixel.h"

int collisionBoundingBox(SDL_Rect first,SDL_Rect second)
{
	int collision;
	if ( (first.x + first.w < second.x) || (first.x > second.x + second.w) 
	|| (first.y + first.h < second.y) || (first.y > second.y + second.h) )
		collision=0;
	else 
		collision=1;
	return collision;
}



int collisionTrigo (SDL_Rect first,SDL_Rect second,int cercle)
{
	point C1,C2;
	float R1,R2,D1,D2;
	int collision=0;

	
	//centre
	C1.x=first.x+(first.w)/2;
	C1.y=first.y+(first.h)/2;
	C2.x=second.x+(second.w)/2;
	C2.y=second.y+(second.h)/2;
	
	switch (cercle)
	{
	case 1 : // cercle circonscrit
		R1=sqrt(pow ((first.w)/2 ,2)  +  pow((first.h)/2, 2)); 
		R2=sqrt(pow ((second.w)/2 ,2)  +  pow((second.h)/2, 2)); 

		D1=sqrt(pow((C1.x-C2.x),2)+pow((C1.y-C2.y),2));
		D2=R1+R2;
	break;

	case 2 : // cercle inscrit
		if (first.h > first.w)
			R1=first.w/2;
		else R1=first.h/2;

		if (second.h > second.w)
			R2=second.w/2;
		else R2=second.h/2;

		D1=sqrt(pow((C1.x-C2.x),2)+pow((C1.y-C2.y),2));
		D2=R1+R2;
	break;
	}
	
	if (D1<=D2)
		collision=1;
		
	return collision;
}


bool collisionmap (SDL_Rect entite,SDL_Surface *mask,int scrollmask)
{
	SDL_Color couleur;
	couleur.r=255;
	couleur.g=255;
	couleur.b=255;
	int i;

	for(i=entite.x+20 ;i<(entite.x + entite.w-20);i++)
	{
		couleur = GetPixel(mask, i+scrollmask, entite.y + entite.h);
		if((couleur.r == 0 && couleur.g == 0 && couleur.b == 0) )
			break;
	}
	return ((couleur.r == 0 && couleur.g == 0 && couleur.b == 0) );
}
