
#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

typedef struct{
	int Xmax,Xmin,Xdest,direction;
	SDL_Rect pos;
}mouvement;

typedef struct
{
	SDL_Surface *image;
	SDL_Rect frame[10];
	int nbrEnnemis,coll,collision[10],numEnnemi,nbrCollisions;
	mouvement mvt[10];
	float lastAnimated;
}Ennemi;

void initialiser_ennemi ( Ennemi *e);
void afficher_ennemi(Ennemi e,SDL_Surface *screen);
void deplacement_alea_ennemi(Ennemi *e, SDL_Surface *screen);
void animEnnemi(Ennemi *e);
#endif



















/*typedef struct{
	int numEnnemi,nbrCollisions,collisionOuPas;
}Collision;
*/

/*typedef struct
{
	SDL_Surface *image[3];
	SDL_Rect frame[3][10];
	int nbrEnnemis[3]; //dans le level
	mouvement mvt[3][10];
	float lastAnimated[3];
}Ennemi;*/
