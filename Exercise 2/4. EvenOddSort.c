/* bubble sort program */

#include <stdio.h>

#define SIZE 8

void swap(int* a, int* b);
void printArray(int* a, int size);
int sort(int* a, int size);


int main()
{
	int i=0, array[SIZE];
	printf("Enter an array of size %d\n",SIZE);
	for(i=0 ; i<SIZE ; i++)
	{
		scanf("%d",&array[i]);
	}	
	sort(array,SIZE);
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


int sort(int* a, int size)
{
	int i=0, j=0, count=0, even_counter=0;
	for(i=0 ; i<size ; i++)
	{
		count=0;
		for(j=0; j<(size-i-1) ; j++)
		{
			if((a[j]%2==1 || a[j]%2==-1 ) && (a[j+1]%2==0))
			{
				swap(&a[j],&a[j+1]);
				count++;
			}
		}
		if(count==0)
		{
			break;
		}
	}
	i=0;
	while((a[i]%2)==0)
	{
		even_counter++;
	}

	return even_counter;
}
