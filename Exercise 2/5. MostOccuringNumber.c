/* most accuring number program */

#include <stdio.h>

#define SIZE 8

void swap(int* a, int* b);
void printArray(int* a, int size);
void bubbleSort(int* a, int size);
int count(int* a, int size);


int main()
{
	int i=0, array[SIZE];
	printf("Enter an array of size %d\n",SIZE);
	for(i=0 ; i<SIZE ; i++)
	{
		scanf("%d",&array[i]);
	}	
	i=count(array,SIZE);
	printArray(array,SIZE);

	return 0;
}


void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
	return;
}


void printArray(int* a, int size)
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
	int i=0, j=0, count=0;
	for(i=0 ; i<size ; i++)
	{
		count=0;
		for(j=0; j<(size-i-1) ; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				count++;
			}
		}
		if(count==0)
		{
			return;
		}
	}

	return;
}


int count(int* a, int size)
{
	int i=0, max_counter=1, max_value=a[0], counter=1;
	bubbleSort(a,size);
	while(i<size)
	{
		while(a[i]==a[i+1])
		{
			counter++;
		}
		if(counter>max_counter)
		{
			max_value=a[i];
		}
		i++;
	}

	printf("The most common is %d, and it occurs %d times",max_value,max_counter);

	return max_value;
}
