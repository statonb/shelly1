all: d1 d2 d3

haver_c.o : haver_c.c
	gcc -c haver_c.c

d1 : d1.o haver_c.o
	gcc -o d1 d1.o haver_c.o -lm

d1.o : d1.c
	gcc -c d1.c

d2 : d2.o haver_c.o
	gcc -o d2 d2.o haver_c.o -lm

d2.o : d2.c
	gcc -c d2.c

d3 : d3.o haver_c.o
	gcc -o d3 d3.o haver_c.o -lm

d3.o : d3.c
	gcc -c d3.c
