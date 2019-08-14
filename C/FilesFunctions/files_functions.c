#include <stdio.h>
#include <stdlib.h>
#include "files_functions.h"


void last(char* file_name, int n)
{
	
	int index=0, lines_number=n+1, i=0;
	char string[512];
	unsigned int* offsets;
	FILE* input; 
	input=fopen(file_name,"r");
	if (input == NULL) { 
		return; 
	} 
	if((offsets=(unsigned int*)malloc(lines_number*sizeof(unsigned int)))==NULL)
	{
		return;
	}
	for(i=0 ; i<lines_number ; i++)
	{
		offsets[i]=0;
	}	
	while(fgets(string,512,input))
	{
		index=(index+1)%lines_number;
		offsets[index]=ftell(input);
	}
	fseek(input,offsets[(index+1)%lines_number],0);
	while(fgets(string,512,input))
	{
		printf("%s",string);
	}	
	
	free(offsets);
	fclose(input);
	return;
}









void countLetters(char* file_name)
{
	int i=0;
	int count_letters[52]={0};
	int letter; 
	FILE* input; 
	input=fopen(file_name,"r");
	if (input == NULL) { 
		return; 
	}

/*-------------------------GET LETTERS------------------------------*/
	for (letter=getc(input); letter!=EOF; letter=getc(input)) 
	{
		if((letter>='A') && (letter<='Z'))
		{
			letter-='A';
			(count_letters[letter])++;
		}
		else if((letter>='a') && (letter<='z'))
		{
			letter-=('a'-26);
			(count_letters[letter])++;
		}
	}

	fclose(input); 

/*-------------------------PRINT------------------------------*/
	for(i=0 ; i<52 ; i++)
	{
		if(count_letters[i]>0)
		{
			if(i<26)
			{
				printf("%c   %d\n",i+'A',count_letters[i]);
			}
			else
			{
				printf("%c   %d\n",i+'a'-26,count_letters[i]);
			}
	
		}
	}
	return;
}




/*
void countLetters(char* file_name)
{
	int i=0, j=0;
	word** words;
	FILE* input; 
	input=fopen(file_name,"r");
	if (input == NULL) { 
		return; 
	}
	if(!(words=(word*)malloc(sizeof(word*)))
	{
		return;
	}
	

	return;
}

*/
