#include "collisions.h"

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


bool collisionmap (int direction,SDL_Rect col,SDL_Surface *collisionMap,SDL_Surface *ecran)
{
/*
 if (collisionMap == NULL)
 collisionMap = SDL_LoadBMP("map.bmp");
    SDL_Color couleur;
    int i;
    if (direction == 3)
    {
 for(i=(col.y+80);i<(col.y + 117);i++)
{
 couleur = GetPixel(collisionMap, col.x, i);
 if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
 break;
}
    }
    else if (direction == 4)
    {
 for(i=(col.y+80);i<(col.y + 117);i++)
{
       couleur = GetPixel(collisionMap, col.x + 65 + 10, i);
 if((couleur.r == 255  && couleur.g == 255 && couleur.b == 255) )
 break;
}
    }
    else if (direction == 1)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y);
 if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
 break;
}
    }
    else if (direction == 2)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y + 100 + 10);
 if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
 break;
}
    }
   
 return ((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) );
*/
}

