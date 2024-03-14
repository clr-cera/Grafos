all: graph main
	gcc -I. *.o -o main.out -std=c99 -Wall
	rm -f *.o
 
main:
	gcc -c main.c -o main.o

graph:
	gcc -c ./graph.c -o graph.o

clean:
	rm -f *.o *.out *.zip

run:
	./main.out

test:
	./main.out < ./tests/1.input | diff ./tests/1.output -u -

test-mem:
	valgrind --leak-check=full ./main.out < ./tests/1.input | diff ./tests/1.output -u -

zip:
	zip -R grafo.zip . '*.c' '*.h' 'Makefile'
