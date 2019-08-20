#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

int main ()
{
    darray *myDarray;
    int myInt;
    darrayCreate(&myDarray, 100);
    darrayAdd(myDarray, 8);
    darrayAdd(myDarray, 9);
    darrayAdd(myDarray, 15);


    darrayDelete(myDarray,&myInt);
    printf("%d\n", myInt); /*15*/
    darrayDelete(myDarray,&myInt);
    printf("%d\n", myInt); /*9*/
    darrayDelete(myDarray,&myInt);
    printf("%d\n", myInt); /*8*/

    return 1;

}