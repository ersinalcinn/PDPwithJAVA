all: compile run

compile:
	gcc -I ./include/ -o ./lib/koloni.o -c ./src/koloni.c
	gcc -I ./include/ -o ./lib/taktik.o -c ./src/taktik.c
	gcc -I ./include/ -o ./lib/taktikA.o -c ./src/taktikA.c
	gcc -I ./include/ -o ./lib/taktikB.o -c ./src/taktikB.c
	gcc -I ./include/ -o ./lib/uretim.o -c ./src/uretim.c
	gcc -I ./include/ -o ./lib/uretimA.o -c ./src/uretimA.c
	gcc -I ./include/ -o ./lib/uretimB.o -c ./src/uretimB.c
	gcc -I ./include/ -o ./lib/test.o -c ./src/test.c
	gcc -I ./include/ -o ./lib/oyun.o -c ./src/oyun.c
	gcc -I ./include/ -o ./bin/Test ./lib/koloni.o ./lib/taktik.o ./lib/taktikA.o ./lib/taktikB.o ./lib/uretim.o ./lib/uretimA.o ./lib/uretimB.o ./lib/test.o ./lib/oyun.o
	
run:
	./bin/Test.exe