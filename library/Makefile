all: a.out example.o linearalgebra.o

a.out: example.o linearalgebra.o
	gcc example.o linearalgebra.o
example.o: example.c linearalgebra.h
	gcc -c example.c linearalgebra.h
linearalgebra.o: linearalgebra.c linearalgebra.h
	gcc -c linearalgebra.c linearalgebra.h
