#include <stdlib.h>
#include <stdio.h>
#include "darray_int.h"


int main()
{
    darray* ptrArray;
    size_t capacity=0;
    int chosen=0, item=0, index=0, itemsNum=0;

    printf("Creating new array. Please inser capacity:\n");
    scanf("%lu",&capacity);
    darrayCreate(&ptrArray,capacity);

    while(chosen>=0 && chosen<=7)
    {
        printf("Choose an option:\n");
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Get item on specific index\n");
        printf("4. Set item on specific index\n");
        printf("5. Print the number of items\n");
        printf("6. Sort the array\n");
        printf("7. Print the array\n");
        printf("Other - exit!\n\n");

        scanf("%d",&chosen);
        switch(chosen)
        {
            case 1:
                printf("Insert item\n");
                scanf("%d",&item);
                darrayAdd(ptrArray,item);
                break;
            case 2:
                darrayDelete(ptrArray,&item);
                printf("Last item deleted\n");
                break;
            case 3:
                printf("Enter index to get\n");
                scanf("%d",&index); 
                darrayGet(ptrArray,index,&item);
                printf("The item received: %d\n",item);
                break;
            case 4:
                printf("Enter index to set\n");
                scanf("%d",&index);
                printf("Enter item to set\n");
                scanf("%d",&item);
                darraySet(ptrArray,index,item);
                break;
            case 5:
                darrayItemsNum(ptrArray,&itemsNum);
                printf("%d items\n",itemsNum);
                break;
            case 6:
                darraySort(ptrArray);
                break;
            case 7:

                darrayPrint(ptrArray);
                break;
        }
    }

    darrayDestroy(ptrArray);

    return 0;
}
