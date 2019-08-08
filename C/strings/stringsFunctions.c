#include <stdio.h>
#include <string.h>


int location(char* a, char* b);
char* shiftLeft(char* a, int shift_by, int shift_start);



int main()
{
    char a[]="izhak";
    char b[]="ha";
    int result=location(a,b);
    printf("%d\n",result);

    return 0;
}


char* shiftLeft(char* a, int shift_by, int shift_start)
{
    int i=0;
	for(i=shift_start ; i<shift_start+shift_by ; i++)
	{
        a[i-shift_by]=a[i];
	}
	a[i]='\0';
	
	
    printf("%s",a);
	return a;
}



int location(char* a, char* b)
{
    int i=0, j=0;
    int a_size=strlen(a);
    int b_size=strlen(b);
    for(i=0 ; i<(a_size-(b_size)+1) ; i++)
    {
        while((a[i]==b[j]) && (i<=a_size))
        {
            if(j==b_size-1)
            {
                return (i-b_size+1);
            }
            i++;
            j++;
        }
        i-=j;
        j=0;
    }
    
    return -1;
}
