all: process time quick main
	gcc -I. tempo.o processo.o quick_sort.o main.o -o gerente.out -std=c99 -Wall
	rm -f *.o
 
main:
	gcc -c main.c -o main.o

time:
	gcc -c ./tempo/tempo.c -o tempo.o

quick:
	gcc -c ./quick_sort/quick_sort.c -o quick_sort.o

process:
	gcc -c ./processo/processo.c -o processo.o


clean:
	rm -f *.o *.out *.zip

run:
	./gerente.out

test:
	./gerente.out < ./tests/1.input | diff ./tests/1.output -u -

test-mem:
	valgrind --leak-check=full ./gerente.out < ./tests/1.input | diff ./tests/1.output -u -

zip:
	zip -R gerente.zip . '*.c' '*.h' 'Makefile'
