#include <stdio.h>
#include <string.h>


int location(char* a, char* b);


int main()
{
    char a[]="izhak";
    char b[]="ha";
    int result=location(a,b);
    printf("%d\n",result);

    return 0;
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
