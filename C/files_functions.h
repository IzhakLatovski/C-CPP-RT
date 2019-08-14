#ifndef FILESFUNCTIONS
#define FILESFUNCTIONS

#include <stdlib.h>

typedef struct {
	char word[100];
	int counter;
} word;

void last(char* file_name, int n);
void countLetters(char* file_name);

#endif
