/****************************************************************************
** Name: Kevin Sliker
** Date: 4-4-2015
** Compiler: gcc -std=c99
** Solution description: This program takes an array of the struct student,
			 which is populated with with id numbers and score
			 numbers, and sorts the array. The sort puts the
			 array of students in ascending order by their scores. 
****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct student
{
	int id;
	int score;
};


/* Put the students and their scores in ascending order            */
/* Preconditions: takes a pointer to an array, and a size of array */
/* Postconditions: sorts the array of elements in ascending order  */
void sort(struct student* students, int n)
{
	/* create temps to hold the swaps of id and score numbers */
	int tempid = 0;
	int tempscore = 0;
	int count = 0; 

	/* count is how we make sure we went through the entire array. The for loop proceeding 
	   this, is to make sure we check each element against all elts in the array  */
	while(count < n)	
	{
		/* for each element in the array search against all other elements */
		for(int i = 0; i < n-1; i++)
		{
			/* this check of i being greater than i+1 
			   puts the array into ascending   */
			/* even though we only are worried about 
			   swapping the scores into ascending order,
			   we still have to swap the student id's to
			   go along with their respective scores  */
			if(students[i].score > students[i+1].score)
			{
				/* set the id and score temps, respectively */
				tempscore = students[i].score;
				tempid = students[i].id;

				/* set the ith elt of the array for score and id */
				students[i].score = students[i+1].score;
				students[i].id = students[i+1].id;

				/* set the next elt of the array for next comparison */
				students[i+1].score = tempscore;
				students[i+1].id = tempid;
			}
		}
		count++;
	}

}

/* Generate ID's and scores for the students, using rand()                                  */
/* Preconditions: takes a pointer to an array of struct type student, and the size of array */
/* Postconditions: populates the array of type struct with id and score numbers             */
void generate(struct student *students, int n)
{
	/*get a different set of random numbers every time rand (the program) is called*/
	srand(time(NULL));
	
	/*populate struct with random numbers */
	for(int i = 0; i < n; i++)
	{
		students[i].id = 1 + rand() % 10;
		students[i].score = rand() % 100;
		/*make sure id's are unique!*/
		for(int j = 0; j < i; j++)
		{
			if(students[i].id == students[j].id)
			{
				i--;
			}
		} 
	}
}


/* Output the contents of the array of students */
void output(struct student *students, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("ID: %d    SCORE: %d\n", students[i].id, students[i].score);
	}

}

int main()
{
	/* Declare an integer n and assign it a value */
	int n = 10;

	/* Allocate memory for n students using malloc */
	struct student *students;
	students = (void *)malloc(n * sizeof(int));

	/* Generate random ID's and scores for the n students, using rand() */
	generate(students, n);
	
	/* Print the contents of the array of n students */
	output(students, n);

	/* Pass this array along with n to the sort() function */
	sort(students, n);

	/* Print the contents of the array of n students */
	printf("This is the array of students after being sorted:\n");
	output(students, n);


	return 0;
}
