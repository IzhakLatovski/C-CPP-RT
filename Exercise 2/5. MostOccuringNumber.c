/* most occuring number */

#include <stdio.h>

#define SIZE 5

void swap(int* a, int* b);
void bubbleSort(int* a, int size);
int count(int* a, int size);


int main()
{
	int i=0, array[SIZE], max_occuring_value=0;
	printf("Enter an array of size %d\n",SIZE);
	for(i=0 ; i<SIZE ; i++)
	{
		scanf("%d",&array[i]);
	}	
	max_occuring_value=count(array,SIZE);	/* for the example */

	return 0;
}


void swap(int* a, int* b)			/* function to swap 2 values */
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
	return;
}


void bubbleSort(int* a, int size)
{
	int i=0, j=0, swaps_count=0;
	for(i=0 ; i<size-1 ; i++)		/* every iteration, the biggest i values are in their place */

	{
		swaps_count=0;
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


int count(int* a, int size)			/* the function to count the value and number of most occuring */
{
    int i=0, max_counter=1, max_value=a[0], counter=1;
	bubbleSort(a,size);			/* sort the array using bubble sort */
	i=0;
	while(i<size-1)				/* go over the array */
	{
		while(a[i]==a[i+1])		/* count same how many times each number occurs */
		{
			counter++;
			i++;
		}
		if(counter>max_counter)		/* if it occurs more than the last highest, update the highest */
		{
			max_value=a[i];
			max_counter=counter;
		}
		i++;
		counter=1;
	}

	printf("The most common is %d, and it occurs %d times",max_value,max_counter);

	return max_value;
}
