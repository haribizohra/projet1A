prog: main.o etoile.o lampe.o collisions.o ennemi.o 
	gcc main.o etoile.o lampe.o collisions.o ennemi.o -o prog -g -lSDL -lSDL_image -lm -lSDL_ttf
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image
etoile.o: etoile.c
	gcc -c etoile.c -g -lSDL -lSDL_image
lampe.o: lampe.c
	gcc -c lampe.c -g -lSDL -lSDL_image
collisions.o: collisions.c
	gcc -c collisions.c -g -lSDL -lSDL_image -lm
ennemi.o: ennemi.c
	gcc -c ennemi.c -g -lSDL -lSDL_image

