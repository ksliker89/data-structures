/*************************************************************************
** Author: Kevin Sliker
** Date: 2015.10.16
** Compiler: gcc -std=c99
** Program Description: This program uses one stack (found in dynamicArray.c) 
              to implement a command line Reverse Polish Notation calculator.
*************************************************************************/

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"


/* Return type: returns 1 if element is a number, otherwise returns 0.
   Parameters: s - the string, num - a pointer to a double.
   Preconditions: none.
   Postconditions: if it is a number, num will hold the value of the number.
*/
int isNumber(char * s, double * num)
{
	char * end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there is anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  // If it got this far, it was not a number
}



/* Add elements in the stack
   Preconditions: the stack contains at least two elements
   Postconditions: the top two elements are popped and
                   their sum is pushed back onto the stack.
   Parameters: stack - the stack being manipulated.
*/
void add(struct DynArr * stack)
{
	TYPE i, j, sum;
	
	i = topDynArr(stack);
	popDynArr(stack);
	j = topDynArr(stack);
	popDynArr(stack);

	sum = j + i;

	pushDynArr(stack, sum);
}




/* Subtract elements in the stack
   Preconditions: the stack contains at least two elements
   Postconditions: the top two elements are popped and
                   their difference is pushed back onto the stack.
   Parameters: stack - the stack being manipulated.
*/
void subtract(struct DynArr * stack)
{
	TYPE x, y, difference;
	
	x = topDynArr(stack);

	popDynArr(stack);
	y = topDynArr(stack);
	
	popDynArr(stack);
	difference = y - x;

	pushDynArr(stack, difference);

}




/* Subtract elements in the stack
   Preconditions: the stack contains at least two elements
   Postconditions: the top two elements are popped and
                   their quotient is pushed back onto the stack.
   Parameters: stack - the stack being manipulated.
*/
void divide(struct DynArr * stack)
{
	TYPE x, y, quotient;
	
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	if(x == 0)
	{
		printf("Undefined value: You can't divide by zero\n");
	}	
	popDynArr(stack);
	quotient = y / x;

	pushDynArr(stack, quotient);
}


void mult(struct DynArr * stack)
{
	TYPE x, y, product;
	
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	product = y * x;
	pushDynArr(stack, product);
}

void carrot(struct DynArr * stack)
{
	TYPE x, y, power;
	
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	power = pow(y,x);
	pushDynArr(stack, power);
}

void square(struct DynArr * stack)
{
	TYPE x, square;
	
	x = topDynArr(stack);
	popDynArr(stack);
	square = pow(x,2);
	pushDynArr(stack, square);
}

void cube(struct DynArr * stack)
{
	TYPE x, cube;
	
	x = topDynArr(stack);
	popDynArr(stack);
	cube = pow(x,3);
	pushDynArr(stack, cube);
}


void absolute(struct DynArr * stack)
{
	TYPE x, abs;

	x = topDynArr(stack);
	popDynArr(stack);
	abs = fabs(x);
	pushDynArr(stack, abs);
}

void sqroot(struct DynArr * stack)
{
	TYPE x, root;

	x = topDynArr(stack);
	popDynArr(stack);
	root = sqrt(x);
	printf("+-");
	pushDynArr(stack, root);
}

void expo(struct DynArr * stack)
{
	TYPE x, expo;

	x = topDynArr(stack);
	popDynArr(stack);
	expo = exp(x);
	pushDynArr(stack, expo);
}


void natlog(struct DynArr * stack)
{
	TYPE x, natlog;

	x = topDynArr(stack);
	popDynArr(stack);
	natlog = log(x);
	pushDynArr(stack, natlog);
}



void logbten(struct DynArr * stack)
{
	TYPE x, log;
	
	x = topDynArr(stack);
	popDynArr(stack);
	log = log10(x);
	pushDynArr(stack, log);
}


double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char s[1];
	struct DynArr * stack;

	//set up the stack
	stack = createDynArr(20);

	//start at 1 to skip the name of the calculator calc
	for(i = 1; i < numInputTokens; i++)
	{
		strcpy(s, inputString[i]);
		/* general algorithm:
		   1. Check if the string s is in the list of operators.
		   2. If it is, perform corresponding operations.
		   3. Otherwise, check if s is a number.
		   4. If s is not a number, produce an error.
		   5. If s is a number, push it onto the stack        */
		if(strcmp(s, "+") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				add(stack);
			}
		else if(strcmp(s, "-") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				subtract(stack);
			}
		else if(strcmp(s, "/") == 0)
				{
				if(sizeDynArr(stack) != 2)
					exit(0);
				divide(stack);
			}
		else if(strcmp(s, "x") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				mult(stack);
			}
		else if(strcmp(s, "^") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				carrot(stack);
			}
		else if(strcmp(s, "^2") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				square(stack);
			}
		else if(strcmp(s, "^3") == 0)
			{
				if(sizeDynArr(stack) != 2)
					exit(0);
				cube(stack);
			}
		else if(strcmp(s, "abs") == 0)
			{
				if(sizeDynArr(stack) != 1)
					exit(0);
				absolute(stack);
			}
		else if(strcmp(s, "sqrt") == 0)
			{
				if(sizeDynArr(stack) != 1)
					exit(0);
				sqroot(stack);
			}
		else if(strcmp(s, "exp") == 0)
			{
				if(sizeDynArr(stack) != 1)
					exit(0);
				expo(stack);
			}
		else if(strcmp(s, "ln") == 0)
			{
				if(sizeDynArr(stack) != 1)
					exit(0);
				natlog(stack);
			}
		else if(strcmp(s, "log") == 0)
			{
				if(sizeDynArr(stack) != 1)
					exit(0);
				logbten(stack);
			}
		else
		{
			//develop code to check for when s is not an operator
			//Remember to deal with special values("pi" and "e")
			//checks for numbers
			if(isNumber(s, &result))
			{
				pushDynArr(stack, result);
			}
			//checks for bad input
			int lettercheck = 0;
			int charcheck = 0;
			lettercheck = strspn(s, "ABCDEFGHIJKLMNOPQRSTUVWXYZcdfghijkmouvwyz");
			charcheck = strspn(s, "~`!@#$%&*()_=:;'?/<>,[]{}");
			if(lettercheck != 0 || charcheck != 0)
			{
				printf("You've entered bad input!\n");
				exit(0);
			}
		}
	}
	/* You will write this part of the function:
	   1. Check if everything look OK and produce an error if needed.
	   2. Store the final value in result and print it out.
	*/
	result = topDynArr(stack);
	deleteDynArr(stack);
	return result;
}


int main(int argc, char ** argv)
{
	//Assume each argument is contained in the argv array
	//argc-1 determines the number of operands + operators
	if(argc == 1)
		return 0;

	TYPE result = calculate(argc, argv);
	printf("RESULT: %f\n", result);
	return 0;
}
