/*********************************************************************
** Name: Kevin Sliker
** Date: 4-4-2015
** Compiler: gcc -std=c99
** Solution description: Create and output a list of 10 students with 
** their unique ID's and scores, the max, the min, and the average score.
*********************************************************************/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

struct student
{
	int id;
	int score;
};


/* this function allocates memory for the struct type student */
/* Preconditions: none                                        */
/* Postconditions: returns the pointer to the created array   */
struct student *allocate()
{
	/*allocate memory for ten students*/
	struct student *student_array;
	student_array = (struct student *) malloc(20 * sizeof(int*));

	/*return the pointer*/
	return student_array;
}


/* generate random ID and score for 10 students, ID being between 1 and 10, scores between 0 and 100*/
/* Preconditions: takes the pointer to an array                            */
/* Postconditions: populates the array with values                         */ 
void generate(struct student *students)
{
	int i, j;
	
	/*get a different set of random numbers every time rand is called*/
	srand(time(NULL));

	/*populate struct with random numbers*/
	for(i = 0; i < 10; i++)
	{
		students[i].id = 1 + rand() % 10;
		students[i].score = rand() % 100;
		for (j = 0; j < i; j++){
			/*make sure id's are unique*/
			if (students[i].id == students[j].id){
				i--;
			}
		}
		
	}
}

/* output information about the ten students in this format*/
/* Preconditions: takes the pointer of an array            */
/* Postconditions: prints the values stored in array       */
void output(struct student *students)
{
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("ID%d: %d Score%d:  %d\n", i, students[i].id, i, students[i].score);
	}

}


/* compute and print the minimum, maximum and average scores of the ten students */
/* Preconditions: takes a pointer to an array                                    */
/* Postconditions: outputs the proper min, max, avg, found in array              */
void summary(struct student* students)
{
	int min, max, avg, i;

	/*compute min*/
	min = 100;
	/* setting min to 100 ensures that this swap will take place
	   because the number in the array will obviously be less than,
	   which is what we want, to perform the swap.                  */
	for(i = 0; i < 10; i++)
	{
		if(min > students[i].score)
		{
			min = students[i].score;
		}
	}
	/*print min*/
	printf("The min score was: %d\n", min);


	/*compute max*/
	/* setting max to 0 ensures that this swap will take place
	   because the number in the array will obviously be greater than,
	   which is what we want, to perform the swap.                  */
	max = 0;
	for(i = 0; i < 10; i++)
	{
		if(max < students[i].score)
		{
			max = students[i].score;
		}
	}
	/*print max*/
	printf("The max score was: %d\n", max);


	/*compute avg*/
	avg = 0;
	for(i = 0; i < 10; i++)
	{
		/* add up all the sums */
		avg += students[i].score;
	}
	/* divide by the total */
	avg = avg / 10;

	/*print avg*/
	printf("The average score was: %d\n", avg);

}


/* deallocate memory from stud                                  */
/* Preconditions: takes the pointer of an array                 */
/* Postconditions: removes the memory currently held by pointer */
void deallocate(struct student *stud)
{
	/*check to make sure the pointer is pointing somewhere*/
	if(stud != NULL)
	{
		free(stud);
	}

}



int main()
{
	/*create a pointer of type stud*/
	struct student *stud = NULL;

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);	

	/*call output*/
	output(stud);	

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	deallocate(stud);

	return 0;
}
