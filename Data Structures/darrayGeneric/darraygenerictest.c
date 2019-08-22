#include <stdlib.h>
#include <stdio.h>
#include "darraygeneric.h"

void destroyPoint (void *_elem, void *context);
void printPoint (void *_elem);
int comparePoints(void *_elemA, void *_elemB);
int getMenuOption();

typedef struct 
{
    int x;
    int y;
} point_t;


int main()
{
    darray* ptrArray;
    void* voidPtrOne;
    point_t* pointOne;
    point_t* pointTwo;
    size_t capacity=0;
    int chosen=0, item=0, index=0, itemsNum=0;
    FILE* fp;

    elementDestroy destroyFunc=destroyPoint;
    elementPrint printFunc=printPoint;
    elementCompare compFunc=comparePoints;

    fp=fopen("input.txt","a");
    if((fp)==NULL)
    {
        return 0;
    }


    printf("Creating new array. Please insert capacity:\n");
    scanf("%lu",&capacity);
    darrayCreate(&ptrArray,capacity);

    while(chosen>=0 && chosen<=7)
    {
        chosen=getMenuOption;
        switch(chosen)
        {
            case 1:
                pointOne=malloc(sizeof(point_t));
                printf("Insert item x:\n");
                scanf("%d",&pointOne->x);
                printf("Insert item y:\n");
                scanf("%d",&pointOne->y);
                darrayAdd(ptrArray,pointOne);
                break;
            case 2:
                voidPtrOne=(point_t*)malloc(sizeof(point_t));
                darrayDelete(ptrArray,&voidPtrOne);
                printf("Last item deleted\n");
                break;
            case 3:
                printf("Enter index to get\n");
                scanf("%d",&index); 
                darrayGet(ptrArray,index, (void**)&pointTwo);
                printf("The item received: %d . %d\n",pointTwo->x,pointTwo->y);
                break;
            case 4:
                pointOne=malloc(sizeof(point_t));
                printf("Insert item x:\n");
                scanf("%d",&pointOne->x);
                printf("Insert item y:\n");
                scanf("%d",&pointOne->y);
                darrayAdd(ptrArray,pointOne);


                printf("Enter index to set\n");
                scanf("%d",&index);
                darraySet(ptrArray,index,pointOne);
                break;
            case 5:
                darrayItemsNum(ptrArray,&itemsNum);
                printf("%d items in the array\n",itemsNum);
                break;
            case 6:
                darraySort(ptrArray,compFunc);
                darrayPrint(ptrArray,printFunc);
                break;
        }
    }

    darrayDestroy(ptrArray, destroyFunc, fp);
    fclose(fp);

    return 0;
}


void destroyPoint (void *_elem, void *context)
{
    FILE* fp=(FILE*)context;
    point_t* point=(point_t*)_elem;
    fprintf(fp,"x = %d ",point->x);
    fprintf(fp,"y = %d ",point->y);
    free(point);
}

void printPoint (void *_elem)
{
    point_t* point=(point_t*)_elem;
    printf("x = %d ",point->x);
    printf("y = %d ",point->y);
}

int comparePoints(void *_elemA, void *_elemB)
{   
    if(_elemA==NULL || _elemB==NULL)
    {
        return -1;
    }
    point_t* pointA=(point_t*)_elemA;
    point_t* pointB=(point_t*)_elemB;
    int res=(pointA->x+pointA->y)-(pointB->x+pointB->y);
    return res;
}

int getMenuOption()
{
        printf("Choose an option:\n");
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Get item on specific index\n");
        printf("4. Set item on specific index\n");
        printf("5. Print the number of items\n");
        printf("6. Sort the array\n");
        printf("7. Print the array(deleted function)\n");
        printf("Other - exit!\n\n");

        scanf("%d",&chosen);
    
        return chosen;
}
