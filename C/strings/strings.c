/* this is what I've done in class. Unfortunately didn't have enough time at home this time to improve*/

#include <stdio.h>
#include <string.h>


int myCmp(char* a, char* b);
char* myCpy(char* a, char* b);
char* myCat(char* a, char* b);


int main()
{

	return 0;
}


int myCmp(char* a, char* b)
{
    int i=0;
    if((a==NULL) || (b==NULL))
    {
	   return NULL;
    }	    
    while((a[i]==b[i]) && (a[i]!='\0'))
    {
		i++;
    }
	
    return a[i]-b[i];
}


char* myCpy(char* a, char* b)
{
    int i=0;
    if(a==NULL)
    {
	   return NULL;
    }
    while(b[i]!='\0')
    {
        a[i]=b[i];
        i++;
    }
    a[i]='\0';
    
    return a;
}


char* myCat(char* a, char* b)
{
    int i=0, j=0;
    if(a==NULL)
    {
	   return NULL;
    }
    while(a[i]!='\0')
    {
        i++;
    }
    while(b[j]!='\0')
    {
        a[i]=b[j];
        i++;
        j++;
    }
    a[i]='\0';
    
    return a;
}
