#include <stdio.h>
#include <stdlib.h>
#include "files_functions.h"


int main()
{
	int selection=0, lines_number=0;
	char file_name[100];
	while(1)
	{
		printf("Please choose an option:\n");
		printf("1. Print last lines of text\n");
		printf("2. Count letters in text\n");
		printf("Other number to exit\n\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				printf("Enter file name:\n");
				scanf("%s",file_name);
				printf("Enter number of lines to print:\n");
				scanf("%d",&lines_number);
				last(file_name,lines_number);
				break;
				
			case 2:				
				printf("Enter file name:\n");
				scanf("%s",file_name);
				countLetters(file_name);
				break;			
		}
	}
	
	return 0;
}

