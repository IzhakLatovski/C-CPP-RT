#include <stdlib.h>
#include "hash.h"
#include <stdio.h>


static node_t* createNode(void* key, void* value);
static unsigned long hashRightKey(hashTable_t* hashTable, void* key);
static void* hashtableTravel(hashTable_t* hashTable, void* key, node_t** parentPtr, node_t** currentNode);



hashTable_t* hashtableCreate(hashFunc hashFunctionInput, compareFunc compareFunctionInput, size_t size)
{
    int i=0;
    hashTable_t* newHashTable;

    if(size<1)
    {
        return NULL;
    }
    newHashTable=(hashTable_t*)malloc(sizeof(hashTable_t));
    if(newHashTable==NULL)
    {
        return NULL;
    }
    newHashTable->buckets=calloc(size*1.3,sizeof(node_t*));
    if(newHashTable->buckets==NULL)
    {
        free(newHashTable);
        return NULL;
    }
    newHashTable->sizeOfHashTable=size*1.3;
    newHashTable->hashFunction=hashFunctionInput;
    newHashTable->compareFunction=compareFunctionInput;

    return newHashTable;
}


Status hashtableDestroy(hashTable_t* hashTable, destroyFunc destroyFunctionKey, destroyFunc destroyFunctionValue, void* context)
{
    int i=0;
    node_t* nextNode;
    node_t* currentNode;

    if(hashTable==NULL)
    {
        return NoSuchTable;
    }
    for(i=0 ; i<hashTable->sizeOfHashTable ; i++)
    {
        currentNode=hashTable->buckets[i];
        while(currentNode!=NULL)
        {
            nextNode=currentNode->m_next;
            hashtableDelete(hashTable,currentNode->m_key,destroyFunctionKey,destroyFunctionValue,context);
            currentNode=nextNode;
        }
    }
    free(hashTable->buckets);
    free(hashTable);

    return OK;
}

Status hashtableFind(hashTable_t* hashTable, void* key, void**value)
{
    node_t* currentNode;
    node_t* parentNode;
    unsigned long* counterInList=0;

    if(hashTable==NULL)
    {
        return NoSuchTable;
    }

    *value=hashtableTravel(hashTable,key,&parentNode,&currentNode);
    if(*value!=NULL)
    {
        return OK;
    }

    return NoSuchItem;
}

Status hashtableInsert(hashTable_t* hashTable, void* key, void* value)
{
    node_t* currentNode;
    node_t* parentNode;
    node_t* newNode;
    unsigned long index=0;

    if(hashTable==NULL)
    {
        return NoSuchTable;
    }
    index=hashRightKey(hashTable,key);
    hashtableTravel(hashTable,key,&parentNode,&currentNode);
    if(currentNode!=NULL)
    {
        return ItemInHashAlready;
    }
    else
    {
        newNode=createNode(key,value);
        if(parentNode==NULL)
        {
            hashTable->buckets[index]=newNode;
        }
        else
        {
            parentNode->m_next=newNode;
        }
    }
    
    return OK;
}

static void* hashtableTravel(hashTable_t* hashTable, void* key, node_t** parentNode, node_t** nextNode)
{
    unsigned long index=0;
    
    index=hashRightKey(hashTable,key);
    *nextNode=hashTable->buckets[index];
    while((*nextNode!=NULL) && (hashTable->compareFunction((*nextNode)->m_key,key)!=0))
    {
        *parentNode=*nextNode;
        *nextNode=(*nextNode)->m_next;
    }
    if(*nextNode!=NULL && (hashTable->compareFunction((*nextNode)->m_key,key)==0))
    {
        return (*nextNode)->m_value;
    }

    return NULL;
}

/*
void* hashtableFind(hashTable_t* hashTable, void* key)
{
    unsigned long index=0;
    int equal=0;
    node_t* temp;

    index=hashRightKey(hashTable,key);
    temp=hashTable->buckets[index];
    /*temp is pointing to the right linked list start*/
    /*while(temp!=NULL)
    {
        /*while the list is not empty, compare*/
       /* equal=hashTable->compareFunction(temp->m_key,key);
        if(equal==0)
        {
            return temp->m_value;
        }
        temp=temp->m_next;
    }

    return NULL;
}*/
/*
Status hashtableInsert(hashTable_t* hashTable, void* key, void* value)
{
    unsigned long index=0, counterInList=0;
    node_t* nextNode=NULL;
    node_t* currentNode=NULL;
    node_t* newNode=NULL;

    index=hashRightKey(hashTable,key);
    nextNode=hashTable->buckets[index];
    while((nextNode!=NULL) && (hashTable->compareFunction(nextNode->m_key,key)!=0))
    {
        counterInList++;
        currentNode=nextNode;
        nextNode=nextNode->m_next;
    }
    if(nextNode!=NULL && (hashTable->compareFunction(nextNode->m_key,key)==0))
    {
        return ItemInHashAlready;
    }
    else
    {
        newNode=createNode(key,value);
        if(counterInList==0)
        {
            hashTable->buckets[index]=newNode;
        }
        else
        {
            currentNode->m_next=newNode;
        }
    }
    
    return OK;
}*/

static node_t* createNode(void* key, void* value)
{
    node_t* newNode;

    newNode=(node_t*)malloc(sizeof(node_t));
    if(newNode==NULL)
    {
        return NULL;
    }
    newNode->m_key=key;
    newNode->m_value=value;
    newNode->m_next=NULL;

    return newNode;
}


Status hashtableForEach(hashTable_t* hashTable)
{
    node_t* newNode;
    int i=0;

    if(hashTable==NULL)
    {
        return NoSuchTable;
    }
    /*pass "vertically" on the array*/
    for(i=0 ; i<hashTable->sizeOfHashTable ; i++)
    {
        newNode=hashTable->buckets[i];
        /*pass "horizontally" on each list*/
        while(newNode!=NULL)
        {
            printf("|_|   ");
            newNode=newNode->m_next;
        }
        printf("\n");
    }
    printf("--------------\n");

    return OK;
}


static unsigned long hashRightKey(hashTable_t* hashTable, void* key)
{
	unsigned long index=0;

	index=hashTable->hashFunction(key);
    index%=hashTable->sizeOfHashTable;

    return index;
}


Status hashtableDelete(hashTable_t* hashTable, void* key, destroyFunc destroyFunctionKey, destroyFunc destroyFunctionValue, void* context)
{
    unsigned long index=0, counterInList=0;
    node_t* nextNode=NULL;
    node_t* currentNode=NULL;

    if(hashTable==NULL)
    {
        return NoSuchTable;
    }
    index=hashRightKey(hashTable,key);
    hashtableTravel(hashTable,key,&currentNode,&nextNode);
    if(nextNode==NULL)
    {
        return NoSuchItem;
    }
    if(currentNode==NULL)
    {
        if(nextNode->m_next==NULL)
        {
            hashTable->buckets[index]=NULL;
            destroyFunctionValue(nextNode->m_value,context);
            destroyFunctionKey(nextNode->m_key,context);
        }
        else
        {
            hashTable->buckets[index]=nextNode->m_next;
            destroyFunctionValue(nextNode->m_value,context);
            destroyFunctionKey(nextNode->m_key,context);
        }
    }
    else if(nextNode->m_next==NULL)
    {
        currentNode->m_next=NULL;
        destroyFunctionValue(nextNode->m_value,context);
        destroyFunctionKey(nextNode->m_key,context);
    }
    else
    {
        currentNode->m_next=nextNode->m_next;
        destroyFunctionValue(nextNode->m_value,context);
        destroyFunctionKey(nextNode->m_key,context);
    }
    
    return OK;
}