#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        
	//create a deque
	struct cirListDeque * q = createCirListDeque();

	//populate the deque
	printf("addBackCirListDeque(q, (TYPE)5);\n");
	printf("addFrontCirListDeque(q, (TYPE)4);\n");
	printf("addBackCirListDeque(q, (TYPE)6);\n");
	printf("addFrontCirListDeque(q, (TYPE)3);\n");
	printf("addBackCirListDeque(q, (TYPE)7);\n");
	printf("addFrontCirListDeque(q, (TYPE)2);\n");
	printf("addBackCirListDeque(q, (TYPE)8);\n");
	printf("addFrontCirListDeque(q, (TYPE)1);\n");
	printf("Result should be: 1 2 3 4 5 6 7 8 \n");
	addBackCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)4);
	addBackCirListDeque(q, (TYPE)6);
	addFrontCirListDeque(q, (TYPE)3);
	addBackCirListDeque(q, (TYPE)7);
	addFrontCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)8);
	addFrontCirListDeque(q, (TYPE)1);

	//print the deque
	printCirListDeque(q);


	//remove from the deque
	printf("Removing from the list....\n");
	printf("removeFrontCirListDeque(q);\n");
	printf("removeBackCirListDeque(q);\n");
	printf("Result should be 2 3 4 5 6 7 \n");
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	
	//print the deque
	printCirListDeque(q);


	//front and back tests
	printf("Front and Back test....\n");
	printf("frontCirListDeque(q);\n");
	printf("%f\n", frontCirListDeque(q));
	printf("backCirListDeque(q);\n");
	printf("%f\n", backCirListDeque(q));




	//reverse deque
	printf("Reversing deque...\n");
	reverseCirListDeque(q);
	//print the deque
	printCirListDeque(q);
	

	return 0;
}
