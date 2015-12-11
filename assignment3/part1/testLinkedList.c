#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	printf("Testing the list......\n\n\n");

	//create a new list 
	struct linkedList * lst =  createLinkedList(); 


	//populate the list 
	printf("addFrontList(lst, (TYPE)0);\n");
	addFrontList(lst, (TYPE)0);
	printf("addBackList(lst, (TYPE)8);\n");
	addBackList(lst, (TYPE)8);
	printf("addBackList(lst, (TYPE)2);\n");
	addBackList(lst, (TYPE)2);
	printf("addBackList(lst, (TYPE)5);\n");
	addBackList(lst, (TYPE)5);
	printf("addFrontList(lst, (TYPE)1);\n");
	addFrontList(lst, (TYPE)1);
	printf("Printing list....\n");
	printList(lst);
	printf("\n\n\n");

	//front and back test
	printf("Front and back tests...\n");
	printf("frontList(lst);\n");
	printf("%d\n", frontList(lst));
	printf("backList(lst);\n");
	printf("%d\n", backList(lst));
	printf("\n\n\n");

	//remove front and back tests
	printf("Remove front and back tests...\n");
	printf("removeFrontList(lst);\n");
	removeFrontList(lst);
	printList(lst);
	printf("removeBackList(lst);\n");
	removeBackList(lst);
	printf("Printing list....\n");
	printList(lst);
	printf("\n\n\n");

	//contains test, remove test
	printf("Contains and removes test...\n");
	printf("removeList(lst, (TYPE)0);\n");
	removeList(lst, (TYPE)0);
	printf("Printing list....\n");
	printList(lst);
	printf("\n\n\n");
	
	//isEmpty test
	printf("isEmpty test...\n");
	printf("isEmpty(lst);\n");
	int empty;
	empty = isEmptyList(lst);
	printf("Empty Test Result: %d", empty);
	printf("\n\n\n");
	return 0;
}
