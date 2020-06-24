a.out: example.o linearalgebra.o
  gcc example.o linearalgebra.o
example.o: example.c linearalgebra.h
  gcc example.c linearalgebra.h
linearalgebra.o: linearalgebra.c linearalgebra.h
  gcc linearalgebra.c linearalgebra.h
