prog: main.o menu.o objet.o
	gcc main.o menu.o objet.o -o prog -g -lSDL -lSDL_image -lSDL_mixer
main.o: myversion.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer
menu.o: menu.c
	gcc -c menu.c -g -lSDL -lSDL_image -lSDL_mixer
objet.o: objet.c
	gcc -c objet.c -g -lSDL -lSDL_image -lSDL_mixer
