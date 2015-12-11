default: prog

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c

testCirListDeque.o: testCirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o

clean:
	rm prog cirListDeque.o testCirListDeque.o

