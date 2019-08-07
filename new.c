#include <stdio.h>

int countZeroes(int a[], int size);
void sort(int* a, int size);
void printArray(int* a, int size);


int main()
{
	int array[8], i=0;
	printf("Please enter an array of 0/1, of length 8\n");
	for(i=0 ; i<8 ; i++)
	{
		scanf("%d",&array[i]);
	}
	sort(array,8);
	printArray(array,8);
	return 0;
}


/* function to count the number of 0's in an array */
int countZeroes(int a[], int size)
{
	int i=0, count=0;
	for(i=0 ; i<size ; i++)
	{
		if(a[i]==0)
		{
			count++;
		}
	}
	return count;
}


/* function to write 0's and 1's in the right number of times in the array */
void sort(int* a, int size)
{
	int i=0, zeroes_num=countZeroes(a, size);
	for(i=0 ; i<zeroes_num ; i++)
	{
		a[i]=0;
	}
	for(i ; i<size ; i++)
	{
		a[i]=1;		
	}
	return;
}


/* function to print an array */
void printArray(int* a, int size)
{
	int i=0;
	for(i=0 ; i<size ; i++)
	{
		printf("%d",a[i]);
	}
	return;
}
