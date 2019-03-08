prog: main.o menu.o
	gcc main.o menu.o -o prog -g -lSDL -lSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer
menu.o: menu.c
	gcc -c menu.c -g -lSDL -lSDL_image -lSDL_mixer
