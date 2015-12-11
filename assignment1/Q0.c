/***************************************************************************
** Name: Kevin Sliker, Vlad Predovic
** Date: 4-4-2015
** Compiler: gcc -std=c99 
** Solution description: This program demonstrates how passing values and 
**			 pointers to a function works in C.
***************************************************************************/


#include <stdlib.h>
#include <stdio.h>


/* this function demonstrates what pointers do in C */
/* Preconditions: given a pointer                   */
/* Postconditions: print the value of pointer       */
void fooA(int *iptr)
{
	/*print the value of the integer pointed to by iptr*/
	printf("The value of x pointed to by iptr is: %d\n", *iptr);

	/*print the address pointed to by iptr*/
	printf("The address pointed to by iptr is: %p\n", iptr);

	/*print the address of iptr itself*/
	printf("The address of iptr itself is: %p\n", &iptr);
}


int main()
{
	/*declare an integer x*/
	int x = 10;
	int *iptr;
	iptr = &x;
	
	/*print the address of x*/
	printf("The address of x is: %p\n", &x);

	/*call fooA() with the address of x*/
	fooA(iptr);

	/*print the value of x*/
	printf("The value of x is: %d\n", x);

	return 0;
}
