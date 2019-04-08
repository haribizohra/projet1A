#include "collisions.h"

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

