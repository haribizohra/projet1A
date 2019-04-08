prog: jeu.o bg.o etoile.o lampe.o perso.o collisions.o ennemi.o chrono.o vie.o score.o enigme.o getpixel.o
	gcc jeu.o etoile.o lampe.o bg.o perso.o collisions.o ennemi.o chrono.o vie.o score.o enigme.o getpixel.o -o prog -g -lSDL -lSDL_image -lm -lSDL_ttf
jeu.o: jeu.c
	gcc -c jeu.c -g -lSDL -lSDL_image
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
enigme.o: enigme.c
	gcc -c enigme.c -g -lSDL -lSDL_image -lSDL_ttf
getpixel.o: getpixel.c
	gcc -c getpixel.c -g -lSDL -lSDL_image -lSDL_ttf
