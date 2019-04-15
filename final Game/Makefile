prog: main.o menu.o menus.o jeu.o etoile.o lampe.o bg.o perso.o collisions.o ennemi.o chrono.o vie.o score.o
	gcc main.o menu.o menus.o jeu.o etoile.o lampe.o bg.o perso.o collisions.o ennemi.o chrono.o vie.o score.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lm -lSDL_ttf
main.o: main.c menu.o menus.o jeu.o
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lm -lSDL_ttf
jeu.o: jeu.c etoile.o lampe.o bg.o perso.o collisions.o ennemi.o chrono.o vie.o score.o 
	gcc -c jeu.c -g -lSDL -lSDL_image -lm -lSDL_ttf
etoile.o: etoile.c
	gcc -c etoile.c -g -lSDL -lSDL_image
lampe.o: lampe.c
	gcc -c lampe.c -g -lSDL -lSDL_image
bg.o: bg.c
	gcc -c bg.c -g -lSDL -lSDL_image
perso.o: perso.c
	gcc -c perso.c -g -lSDL -lSDL_image
collisions.o: collisions.c
	gcc -c collisions.c -g -lSDL -lSDL_image -lm
ennemi.o: ennemi.c
	gcc -c ennemi.c -g -lSDL -lSDL_image
chrono.o: chrono.c
	gcc -c chrono.c -g -lSDL -lSDL_image
vie.o: vie.c
	gcc -c vie.c -g -lSDL -lSDL_image
score.o: score.c
	gcc -c score.c -g -lSDL -lSDL_image -lSDL_ttf
menu.o: menu.c 
	gcc -c menu.c -g -lSDL -lSDL_image -lSDL_mixer
menus.o: menus.c
	gcc -c menus.c -g -lSDL -lSDL_image -lSDL_mixer
