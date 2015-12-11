/*******************************************************************
** Name: Kevin Sliker
** Date: 4-4-2015
** Compiler: gcc -std=c99
** Solution description: This program demonstrates some pointer 
			 arithmetic.
*******************************************************************/

#include <stdlib.h>
#include <stdio.h>


/* This function performs some basic pointer arithmetic.      */
/* Preconditions: takes two pointers of type int, and one int */
/* Postconditions: returns the value of the int.              */
int foo(int *a, int *b, int c)
{
	/* Set a to double its original value */
	*a = *a*2;

	/* Set b to half its original value */
	*b = *b/2;

	/* Assign a+b to c  */
	c = *a + *b;

	/* return c */
	return c;

}



int main()
{
	/* Declare three integers x, y and z and initialize them to 7, 8, 9 respectively */
	int x = 7;
	int y = 8;
	int z = 9;

	/* Print the values to x, y and z */
	printf("x: %d   y: %d    z: %d\n", x, y, z);

	/* Call foo() appropriately, passing x,y,z as parameters */
	int fooval = foo(&x, &y, z);

	/* Print the value returned by foo */
	printf("foo returned: %d\n", fooval);	

	/* Print the values of x, y and z again */
	printf("x: %d   y: %d    z: %d\n", x, y, z);

	return 0;
}


/* The return value is different from 'c' because 'c' is not passed by reference but by value.
   In other words, a copy of 'c' is passed to the function, hence the output has not altered the
   actual value stored in the memory address holding 'c'.
*/
