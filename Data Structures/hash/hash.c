#include <stdlib.h>
#include "hash.h"


static node_t* createNode(void* key, void* value);


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
    newHashTable->buckets=malloc(sizeof(node_t*)*size*1.3);
    if(newHashTable->buckets==NULL)
    {
        free(newHashTable);
        return NULL;
    }
    for(i=0 ; i<size ; i++)
    {
        newHashTable->buckets[i]=NULL;
    }
    newHashTable->sizeOfHashTable=size*1.3;
    newHashTable->hashFunction=hashFunctionInput;
    newHashTable->compareFunction=compareFunctionInput;

    return newHashTable;
}


Status hashtableDestroy(hashTable_t* hashTable)
{
    free(hashTable->buckets);
    free(hashTable);
}


void* hashtableFind(hashTable_t* hashTable, void* key)
{
    unsigned long index=0;
    int equal=0;
    node_t* temp;

    index=hashTable->hashFunction(key);
    index%=hashTable->sizeOfHashTable;
    temp=hashTable->buckets[index];
    while(temp!=NULL)
    {
        equal=hashTable->compareFunction(temp->m_key,key);
        if(equal)
        {
            return temp->m_value;
        }
        temp=temp->m_next;
    }

    return NULL;
}


Status hashtableInsert(hashTable_t* hashTable, void* key, void* value)
{
    int index=0;
    node_t* nextNode;
    node_t* currentNode;
    node_t* newNode;

    index=hashTable->hashFunction(key);
    index%=hashTable->sizeOfHashTable;
    nextNode=hashTable->buckets[index];
    while((nextNode!=NULL) && (hashTable->compareFunction(nextNode->m_key,key)!=0))
    {
        currentNode=nextNode;
        nextNode=nextNode->m_next;
    }
    /*stopped because of second condition (compare is positive)*/
    if(nextNode!=NULL && (hashTable->compareFunction(nextNode->m_key,key)==0))
    {
        return ItemInHashAlready;
    }
    /*stopped because of first condition (nextNode==NULL)*/
    else
    {
        newNode=createNode(key,value);
        currentNode->m_next=newNode;
    }

    return OK;
}


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
    for(i=0 ; i<hashTable->sizeOfHashTable ; i++)
    {
        newNode=hashTable->buckets[i];
        while(newNode!=NULL)
        {
            newNode=newNode->m_next;
        }
    }

    return OK;
}
