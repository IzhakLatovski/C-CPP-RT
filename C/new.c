#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, char *argv[])
{
	int i=0, isNumber=1, isString=1;
	int firstLength=strlen(argv[1]);
	int secondLength=strlen(argv[2]);
	int firstIsNumber=0;

/* run on the first string and check is it number/string/none */
	for(i=0 ; i<firstLength ; i++)
	{
		if(!(isalpha(argv[1][i])))
		{
			isString=0;
		}
		if(!(isdigit(argv[1][i])))
		{
			isNumber=0;
		}
	}

/* if the first one wasnt a string - look for a string */
	if(!isString)
	{
		firstIsNumber=1;
		isString=1;
		for(i=0 ; i<secondLength ; i++)
		{
			if(!(isalpha(argv[2][i])))
			{
				isString=0;
			}
		}
	}
/* if the first one wasnt a number - look for a number */

	else
	{
		isNumber=1;
		for(i=0 ; i<secondLength ; i++)
		{
			if(!(isdigit(argv[2][i])))
			{
				isNumber=0;
			}
		}
	}

/* if we have a number and a string, success */
	if(isNumber && isString)
	{
		if(firstIsNumber)
		{
			printf("%s is %s years old\n",argv[2],argv[1]);
		}
		else
		{
			printf("%s is %s years old\n",argv[1],argv[2]);			
		}
	}
	else
	{
		printf("Wrong input");

	}

	return 0;
}