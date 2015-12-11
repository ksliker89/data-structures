all: prog

prog: bst.o compare.o
	gcc -g -Wall -std=c99 -o prog bst.o compare.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c

bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c

pizza: 
	gcc -g -Wall -std=c99 main2.c bst.h compare2.c -o pizza

clean:
	rm bst.o compare.o prog pizza
