#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int isNumber(int length, char* array[], int index);
int isString(int length, char* array[], int index);



int main (int argc, char *argv[])
{
	int firstLength=strlen(argv[1]);
	int secondLength=strlen(argv[2]);

	if(argc>3)
	{
		printf("Too much arguments\n");
		return -1;
	}

	if(isNumber(firstLength,argv,1))
	{
		if(isString(secondLength,argv,2))
		{
			printf("%s is %s years old\n",argv[2],argv[1]);
			return 0;
		}
	}
	else if (isString(firstLength,argv,1))
	{
		if(isNumber(secondLength,argv,2))
		{
			printf("%s is %s years old\n",argv[1],argv[2]);	
			return 0;
		}
	}
		
	printf("Wrong input\n");
	return -1;

}



int isNumber(int length, char* array[], int index)
{
	int i=0;

	for(i=0 ; i<length ; i++)
	{
		if(!(isdigit(array[index][i])))
		{
			return 0;
		}
	}

	return 1;
}



int isString(int length, char* array[], int index)
{
	int i=0;

	for(i=0 ; i<length ; i++)
	{
		if(!(isalpha(array[index][i])))
		{
			return 0;
		}
	}

	return 1;
}
