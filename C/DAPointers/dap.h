#ifndef DAP
#define DAP

typedef int* intPtr;

typedef struct
{
    int capacity;
    int index;
    intPtr* arr; /*  */
} Array_t;

Array_t* createArray(int capacity);
int insert(Array_t* array, intPtr number); /*  */
void print(Array_t* array);
void destroy(Array_t* array);


#endif
