all: a.out example.o lina.o

a.out: example.o lina.o
	gcc example.o lina.o
example.o: tests/example.c src/lina.h
	gcc -Wno-incompatible-pointer-types -c tests/example.c src/lina.h
lina.o: src/lina.c src/lina.h
	gcc -c src/lina.c src/lina.h

clean:
	rm a.out lina.o example.o
