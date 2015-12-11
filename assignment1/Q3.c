/******************************************************************************
** Name: Kevin Sliker
** Date: 4-4-2015
** Compiler: gcc -std=c99
** Solution description: this program sorts and array of n integers in ascending
 			 order. Then it prints both the sorted and unsorted
			 array to the user.
******************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* Sort the given array number, of length n                                */
/* Preconditions: takes a pointer to an array, and an int as size of array */
/* Postconditions: sorts the array of elements in ascending order          */
void sort(int *number, int n)
{
	int temp = 0, count = 0;
	
	/*The while loop here ensures that we search through the array at least n times.
	  Whether there was a swap or not, we increment count independently to keep track
	  of the times through the array  */
	while(count < n)
	{
		/* This for loop is to make sure that for every n in the array, we have searched through
		   the entire array against that n   */
		for(int i = 0; i < n; i++)
		{
			if(number[i] > number[i+1])
			{
				/*This is the actual swap using a temp variable*/
				temp = number[i];
				number[i] = number[i+1];
				number[i+1] = temp;
			}
		}
		count ++;	
	}

}



int main()
{
	/* srand set to time gives a different set of random numbers every time the program is run */
	srand(time(NULL));

	/* Declare an integer n and assign it a value of 20 */
	int n = 20;

	/* Allocate memory for an array of n integer using malloc */
	int *number = malloc(n * sizeof(int));

	/* Fill this array with random numbers between 0 and n, using rand() */
	for(int i = 0; i < n; i++)
	{
		number[i] = rand() % n;
	}

	/* Print the contents of the array */
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", number[i]);
	}

	/* Pass this array along with n to the sort() function */
	sort(number, n);

	/* Print the contents of the array */
	printf("This is the array after being sorted:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", number[i]);
	}

	return 0;
}
