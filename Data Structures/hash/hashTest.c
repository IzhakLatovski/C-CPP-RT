/*changed the whole implementation. testing doesnt work yet with this implementation*/

#include <stdio.h>
#include "hash.h"


unsigned long hashFunction(void* str);
int compareFunction(void* keyOne, void* keyTwo);
void destroyValue(void *value, void *context);
void destroyKey(void *key, void *context);


static int testCreateFunction();
static int testCreate1();
static int testCreate2();
static int testCreate3();

static int testDestroyFunction();
static int testInsertFunction();

static int testInsertFunction();
static int testInsert1();


static int testFindFunction();
static int testForEachFunction();

static void testHashTable();


int main()
{
	if(testCreateFunction())
	{
		printf("1/6 SUCCESS\n");
	}
	if(	testInsertFunction())
	{
		printf("2/6 SUCCESS\n");
	}


/*
	testHashTable();*/

	/*testDestroyFunction();
	testInsertFunction();
	testFindFunction();
	testForEachFunction();*/

	return 0;
}

/*----------------------------------------------------*/
static int testCreateFunction()
{
	if(testCreate1()!=1)
	{
		return 0;
	}
	if(testCreate2()!=1)
	{
		return 0;
	}
	if(testCreate3()!=1)
	{
		return 0;
	}

	return 1;
}

/*normal size*/
static int testCreate1()
{
	hashTable_t* table;

	table=hashtableCreate(hashFunction,compareFunction,10);
	if(table==NULL)
	{
		return 0;
	}

	return 1;
}

/*small size (1)*/
static int testCreate2()
{
	hashTable_t* table;

	table=hashtableCreate(hashFunction,compareFunction,1);
	if(table==NULL)
	{
		return 0;
	}

	return 1;
}

/*large size*/
static int testCreate3()
{
	hashTable_t* table;

	table=hashtableCreate(hashFunction,compareFunction,4000000);
	if(table==NULL)
	{
		return 0;
	}

	return 1;
}
/*----------------------------------------------------*/


static int testInsertFunction()
{
	if(testInsert1()!=1)
	{
		return 0;
	}/*
	if(testInsert2()!=1)
	{
		return 0;
	}
	if(testInsert3()!=1)
	{
		return 0;
	}*/

	return 1;
}

/*test with #inserts = size*/
static int testInsert1()
{
	hashTable_t* table;

	int test1=3;
	int test2=7;
	int test3=20;
	int test4=15;

	void* testPtr1=&test1;
	void* testPtr2=&test2;
	void* testPtr3=&test3;
	void* testPtr4=&test4;

	table=hashtableCreate(hashFunction,compareFunction,2);
	if(table==NULL)
	{
		return 0;
	}
	if(hashtableInsert(table,testPtr1,testPtr1)!=OK)
	{
		return 0;
	}	
	if(hashtableInsert(table,testPtr2,testPtr2)!=OK)
	{
		return 0;
	}
	if(hashtableInsert(table,testPtr3,testPtr3)!=OK)
	{
		return 0;
	}
	if(hashtableInsert(table,testPtr4,testPtr4)!=OK)
	{
		return 0;
	}

	hashtableForEach(table);

	return 1;

}




/*
static void testHashTable()
{
	FILE* file;
	hashTable_t* table;
	int test1=3;
	int test2=7;
	int test3=20;
	int test4=15;
	char* test5="izhakfghgfhgfhgfhgfh";
	int test6=1;
	void* testPtr1=&test1;
	void* testPtr2=&test2;
	void* testPtr3=&test3;
	void* testPtr4=&test4;
	void* testPtr5=&test5;
	void* testPtr6=&test6;
	void* testPtr7;
	char* charTest1;
	int* testInt=0;
	unsigned char* testChar;


	table=hashtableCreate(hashFunction,compareFunction,10);

	hashtableInsert(table,testPtr1,testPtr2);
	hashtableInsert(table,testPtr3,testPtr1);	
	hashtableInsert(table,testPtr4,testPtr5);
	hashtableInsert(table,testPtr5,testPtr2);
	hashtableInsert(table,testPtr2,testPtr3);
	hashtableInsert(table,testPtr1,testPtr4);
	hashtableForEach(table);

	hashtableDelete(table,testPtr4);
	hashtableForEach(table);

	hashtableDelete(table,testPtr1);
	hashtableForEach(table);

	testPtr7=hashtableFind(table,testPtr2);
	if(testPtr7!=NULL)
	{
		testInt=(int*)testPtr7;
		printf("\n%d\n",*testInt);
	}

/*
	hashtableDelete(table,testPtr2);
	hashtableForEach(table);

	hashtableDelete(table,testPtr2);
	hashtableForEach(table);

	hashtableDelete(table,testPtr5);
	hashtableForEach(table);

	hashtableDelete(table,testPtr3);
	hashtableForEach(table);

	

	hashtableDestroy(table);

	return;
}
*/

void destroyValue(void *value, void *context)
{
	FILE* file=(FILE*)context;
	int* temp(int*)value;

	fprintf(file,"%d",*temp);
}

void destroyKey(void *key, void *context)
{
	FILE* file=(FILE*)context;
	int* temp(int*)key;

	fprintf(file,"%d",*temp);
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
