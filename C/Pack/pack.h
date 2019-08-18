#ifndef PACK_H
#define PACK_H

typedef struct 
{
	unsigned int left : 4;
	unsigned int right: 4;
} packStruct;

typedef union
{
	packStruct 	lr;
	char 		c;
} un;

int packString(char* string);
int packStringUnion(char* string);

#endif
