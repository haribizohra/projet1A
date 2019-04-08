prog: main.o  ennemi.o
	gcc main.o  ennemi.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
ennemi.o: ennemi.c
	gcc -c ennemi.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf


