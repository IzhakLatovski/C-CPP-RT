#ifndef H_HASH
#define H_HASH


typedef struct node
{
    void* m_key;
    void* m_value;
    struct node* m_next;
} node_t;


typedef enum  {Destroyed,AllocationError,OK,ItemInHashAlready,NoSuchTable,NoSuchItem,DeletedSuccessfully} Status;

typedef unsigned long (*hashFunc) (void* key);
typedef int (*compareFunc) (void* keyOne, void* keyTwo);
typedef void (*destroyFunc)(void* key, void* context);



typedef struct hashTable
{
    node_t** buckets;
    size_t sizeOfHashTable;
    hashFunc hashFunction;
    compareFunc compareFunction;
} hashTable_t;


hashTable_t* hashtableCreate(hashFunc hashFunctionInput, compareFunc compareFunctionInput, size_t size);
Status hashtableDestroy(hashTable_t* hashTable, destroyFunc destroyFunctionKey, destroyFunc destroyFunctionValue, void* context);
Status hashtableFind(hashTable_t* hashTable, void* key, void**value);
Status hashtableInsert(hashTable_t* hashTable, void* key, void* value);
Status hashtableDelete(hashTable_t* hashTable, void* key, destroyFunc destroyFunctionKey, destroyFunc destroyFunctionValue, void* context);
Status hashtableForEach(hashTable_t* hashTable);

#endif