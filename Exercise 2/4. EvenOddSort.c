/* keep order, put first even numbers, then odd. return number of even numbers */

#include <stdio.h>

#define SIZE 5

void swap(int* a, int* b);
void printArray(int* a, int size);
int sort(int* a, int size);


int main()
{
	int i=0, array[SIZE], number_of_even=0;
	printf("Enter an array of size %d\n",SIZE);
	for(i=0 ; i<SIZE ; i++)
	{
		scanf("%d",&array[i]);
	}	
	number_of_even=sort(array,SIZE);    /* for the example*/
	printArray(array,SIZE);

	return 0;
}


void swap(int* a, int* b)			/* function to swap 2 values */
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
	return;
}


void printArray(int* a, int size)		/* function to print an array */
{
	int i=0;
	for(i=0 ; i<size ; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return;
}


int sort(int* a, int size)
{
	int i=0, j=0, swaps_count=0, evens_count=0;
	for(i=0 ; i<size-1 ; i++)		
	{
		swaps_count=0;
		for(j=0; j<(size-i-1) ; j++)	
		{				/* if a number is odd, and next one is even, swap */
			if( ((((a[j])%2)==1) || (((a[j])%2)==(-1)) )  && ((a[j+1])%2)==0)
			{
				swap(&a[j],&a[j+1]);
				swaps_count++;
			}
		}
		if(swaps_count==0)		/* if 0 swaps in iteration, array is sorted, can finish */
		{
			break;
		}
	}
	i=0;
	while(i<size)				/* count how many even numbers there is, and return it */
	{
		while((a[i]%2)==0)			
		{
			evens_count++;
			i++;
		}
	}
	
	return evens_count;
}
