#include <stdio.h>
#include "dap.h"



int main()
{
    int capacity=0, number=0, result=0;
    intPtr number==NULL;     /* */
    Array_t* array;
    printf("Insert capacity\n");
    scanf("%d",&capacity);
    array=createArray(capacity);
    if(array==NULL)
    {
        return -1;
    }
    while(*number!=(-1))
    {
        printf("Insert number\n");
        scanf("%d",&number);	 /*  */
        result=insert(array,*number); /*  */
    }
    print(array);
    destroy(array);
    
    return 0;
}
