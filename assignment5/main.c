#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
	char cmd = ' ';
	DynArr * mainList = createDynArr(10);
	struct Task * newTask = malloc(sizeof(struct Task *)*4);
	struct Task * firstTask = malloc(sizeof(struct Task *)*4);
	FILE * fptr;
	char * nullptr, filename[100], desc[TASK_DESC_SIZE];
	int priority = 0;

	printf("\n\n** TO-DO LIST APPLICATION **\n\n");

	do
	{
		printf("Press:\n"
				"'l' to load to-do list from a file\n"
				"'s' to save to-do list to a file\n"
				"'a' to add a new task\n"
				"'g' to get the first task\n"
				"'r' to remove the first task\n"
				"'p' to print the list\n"
				"'e' to exit the program\n"
		      );
		/* get input command (from the keyboard) */
		cmd = getchar();
		/* clear the trailing newline character */
		while (getchar() != '\n');

		/* Fixme:  Your logic goes here! */
		switch(cmd)
		{
			case 'l':
				printf("Enter filename: ");
				if(fgets(filename, sizeof(filename), stdin) != NULL)
				{
					nullptr = strchr(filename, '\n');
					if(nullptr)
					{
						* nullptr = '\0';
					}
				}

				fptr = fopen(filename, "r");
				if(fptr == NULL)
				{
					printf("Can't open file!");
				}

				loadList(mainList, fptr);
				fclose(fptr);
				printf("List loaded successfully!\n");

				break;



			case 's':
				if(sizeDynArr(mainList) > 0)
				{
					nullptr = strchr(filename, '\n');
					if(nullptr)
					{
						* nullptr = '\0';
					}
				}
				fptr = fopen(filename, "w");
				if(fptr == NULL)
				{
					printf("Can't open file!\n");
				}
				saveList(mainList, fptr);
				fclose(fptr);
				printf("List saved successfully!\n");

				break;



			case 'a':
				printf("Please enter your task: ");
				if(fgets(desc, sizeof(desc), stdin) != NULL)
				{
					nullptr = strchr(desc, '\n');
					if(nullptr)
					{
						* nullptr = '\0';
					}
				}

				do
				{
					printf("Please enter task priority: ");
					scanf("%d", &priority);
				}
				while(priority >= 999 && priority <= 0);

				//create the task then add it to the heap
				newTask = createTask(priority, desc);
				addHeap(mainList, newTask, compare);
				printf("Task added successfully!\n");
				break;


			case 'g':
				if(sizeDynArr(mainList) > 0)
				{
					firstTask = getMinHeap(mainList);
					printf("The first task is: %s\n", firstTask->description);
				}
				else
				{
					printf("You have nothing to do!\n");
				}

				break;



			case 'r':
				if(sizeDynArr(mainList) > 0)
				{
					firstTask = getMinHeap(mainList);
					removeMinHeap(mainList, compare);
					printf("Task %s has been removed.\n", firstTask->description);
				}
				else
				{
					printf("Your list is empty already!\n");
				}

				break;




			case 'p':
				if(sizeDynArr(mainList) > 0)
				{
					printList(mainList);
				}
				else
				{
					printf("Your list is empty!\n");
				}

				break;


			default:
				printf("That is not a valid entry!\n");
				break;
		}

		/* Note: We have provided functions called printList(), saveList() and loadList() for you
		   to use.  They can be found in toDoList.c */
	}
	while(cmd != 'e');
	/* delete the list */
	deleteDynArr(mainList);

	return 0;
}

