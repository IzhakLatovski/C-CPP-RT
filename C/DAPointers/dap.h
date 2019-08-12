#ifndef DAP
#define DAP

typedef struct
{
    int capacity;
    int index;
    int** arr; /*  */
} Array_t;

Array_t* createArray(int capacity);
int insert(Array_t* array, int* number); /*  */
void print(Array_t* array);
void destroy(Array_t* array);


#endif
