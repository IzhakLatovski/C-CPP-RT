#include <stdio.h>
#include "hash.h"


unsigned long hashFunction(void* str);
int compareFunction(void* keyOne, void* keyTwo);
static void testHashTable();


int main()
{
	testHashTable();

	return 0;
}

static void testHashTable()
{
	hashTable_t* table;
	
	table=hashtableCreate(hashFunction,compareFunction,5);
	
	hashtableInsert(table,numberOne,numberTwo);
	
	hashtableFind(table,numberOne);



	return;
}

unsigned long hashFunction(void* str)
{
    unsigned char *key=(unsigned char*)str;
    unsigned long hash = 0;
    int c;
    while(c=*key++)
   	{	
       	hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}


int compareFunction(void* keyOne, void* keyTwo)
{
	int result=0;
	unsigned char* hashedOne=(unsigned char*)keyOne;
	unsigned char* hashedTwo=(unsigned char*)keyTwo;

	result=*hashedOne-*hashedTwo;

	return result;
}
