#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {

	int random_numbers[6], i=0, r=0, c=0;
	char board[5][10];
	for(r=0 ; r<5 ; r++)        /* initialize board with '-' */
        {
	    for(c=0 ; c<10 ; c++)
	    {
	         board[r][c]='-';
	    }
	}
	    srand(time(NULL));      /* generate random numbers */
    	for (i=0; i<6; i++)
    	{
    		random_numbers[i]=(rand()%49)+1;
    		c=random_numbers[i]%10;
        	random_numbers[i]/=10;
    	        r=random_numbers[i];
    	        while(board[r][c-1]=='+'){		/* if number already there, pick a new one */
    	                random_numbers[i]=(rand()%49)+1;
    	                c=random_numbers[i]%10;
                 	random_numbers[i]/=10;
    	                r=random_numbers[i];
    	        }
    	        board[r][c-1]='+';			/* put the number and get the next number */		
        }
	   
/* PRINTING-----------------------------------------------------------------------------*/
	    printf(" 12345678910\n");
	    for(i=0 ; i<4 ; i++)
	    {
	        printf("%d",i);
	        for(r=0 ; r<10 ; r++)
	        {
	            printf("%c",board[i][r]);
	        }
	        printf("\n");
	    }
	    printf("4");  /* print last row */
	    for(r=0 ; r<9 ; r++)
	    {
	         printf("%c",board[4][r]);
	    }
	    printf("\n");
	
	return 0;
}
