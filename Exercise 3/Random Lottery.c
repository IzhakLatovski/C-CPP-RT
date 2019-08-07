#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {

 
	int random_numbers[6], i=0;
	srand(time(NULL));
    	for (i=0; i<6; i++) {
		random_numbers[i]=(rand()%49)+1;
		printf("%d\n",random_numbers[i]);
	}

 
	return 0;
}
