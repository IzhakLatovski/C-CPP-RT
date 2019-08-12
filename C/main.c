#include <stdio.h>
#include "da.h"



int main()
{
    int capacity=0, number=0, result=0;
    int* nPtr==NULL;     /* */
    Array_t* array;
    printf("Insert capacity\n");
    scanf("%d",&capacity);
    array=createArray(capacity);
    if(array==NULL)
    {
        return 0;
    }
    while(number!=(-1))
    {
        printf("Insert number\n");
        nPtr=scanf("%d",&(*number));	 /*  */
        result=insert(array,*number); /*  */
    }
    print(array);
    destroy(array);
    
    return 0;
}
