#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() 
{
	return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) 
{
	struct linkedList * lst;
	double t1, t2;

	int n;
	for(n=1000; n < 200000; n=n*2) /* outer loop */
	{
		lst = createLinkedList();

		int i;
		for( i = 0 ; i < n; i++) 
		{

			 /*Add elements*/
			addList(lst, (TYPE)i);
		}

		/*Time before contains()*/
		t1 = getMilliseconds();

		for(i=0; i<n; i++) 
		{
			containsList(lst, i);
		}

		/*Time after contains()*/
		t2 = getMilliseconds();

		printf("Time for running contains() on %d elements: %g ms\n", n, t2-t1);

		/* delete DynArr */
		deleteLinkedList(lst);
	}

	return 0;
}

