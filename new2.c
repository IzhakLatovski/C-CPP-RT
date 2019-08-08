#include <stdio.h>
#include <string.h>


int myCmp(char* a, char* b);
char* myCpy(char* a, char* b);
char* myCat(char* a, char* b);
char *my_strcat(char *dest, const char *src);

int main()
{
	char a[]="izj";
	char b[]="izj";
	printf("%d",myCmp(a,b));



	return 0;
}


int myCmp(char* a, char* b)
{
    int i=0;
    while(1)
    {
        if(a[i]!=b[i])
        {
            return (a[i]-b[i]);
        }
	if((a[i]==b[i]) && (a[i]=='\0'))
	{
		return 0;
	}
        i++;
    }
    
    return 0;
}


char* myCpy(char* a, char* b)
{
    int i=0;
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

	printf("%d , %d\n",i,j);
    
    return a;
}
