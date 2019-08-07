/* bubble sort program */

#include <stdio.h>

#define SIZE 7

void swap(int* a, int* b);
void printArray(int* a, int size);
void bubbleSort(int* a, int size);


int main()
{
	int i=0, array[SIZE];
	printf("Enter an array of size %d\n",SIZE);
	for(i=0 ; i<SIZE ; i++)
	{
		scanf("%d",&array[i]);
	}	
	bubbleSort(array,SIZE);
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


void bubbleSort(int* a, int size)
{
	int i=0, j=0, swaps_count=0;
	for(i=0 ; i<size-1 ; i++)		/* every iteration, the last i values are in the right place */

	{
		count=0;
		for(j=0; j<(size-i-1) ; j++)	/* compare pairs, swap if needed */
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swaps_count++;
			}
		}
		if(swaps_count==0)		/* if 0 swaps in iteration, array is sorted, can finish */
		{
			return;
		}
	}

	return;
}
