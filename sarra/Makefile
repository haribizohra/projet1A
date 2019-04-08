prog: test.o bg.o perso.o
	gcc test.o bg.o perso.o -o prog -g -lSDL -lSDL_image
test.o: test.c
	gcc -c test.c -g -lSDL -lSDL_image
bg.o: bg.c
	gcc -c bg.c -g -lSDL -lSDL_image
perso.o: perso.c
	gcc -c perso.c -g -lSDL -lSDL_image
