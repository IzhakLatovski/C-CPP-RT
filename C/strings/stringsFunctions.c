/* not sure I will finish all the assignment before submission*/

#include <stdio.h>
#include <string.h>


void squeeze(char* a, char* b);
int location(char* a, char* b);
int Bin2Int(char* binary);
void Int2Bin();

int main()
{
    char a[]="izhak";
    char b[]="kaz";
    int result=location(a,b);
    printf("%d\n",result);
    
    squeeze(a,b);
	
	Int2Bin;


    return 0;
}


/* O(M*N). Possible to do KMP O(m+n), didn't have enough time */
int location(char* a, char* b)
{
    int i=0, j=0;
    int a_size=strlen(a);
    int b_size=strlen(b);
    if((a_size==0) || (b_size==0) || (a=="/0") || (b=="/0") || (a_size < b_size))
    {
        return -1;   
    }
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


void squeeze(char* a, char* b)
{   
    int i=0, j=0, k=0;
    int b_size=strlen(b);
    for(i=0 ; i< b_size ; i++)
    {
        int a_size=strlen(a);
        k=0;
        for(j=0; j<a_size; j++)
	    {
    		if(a[j]==b[i])
    		{
    			for(k=j; k<a_size; k++)
    			{
    				a[k]=a[k+1];
    			}
    			a_size--;
    			j--;	
	    	} 
    	}
    }
    a[k]="/0";
    printf("%s\n",a);
    
    return;
} 


		
void Int2Bin()
{
    int number=0;
    char binary_number[33];
    int i = 0;

    printf("Enter positive integer:\n");
    scanf("%d",&number);
    if(number<0)
    {
        return;
    }
    while(number)
    {
        i=0;
        while(number>0)
        {
            binary_number[i]=(number%2)+48;
            number/=2;
            i++;
        }
        for(i ; i<33 ; i++)
        {
            binary_number[i]=0+48;
        }
    
      /* reverse the string---------------- */
    
        printf("%s\n",binary_number);
        
        printf("Enter positive integer:\n");
        scanf("%d",&number);
        if(number<0)
        {
            return;
        }

    }
    return;
    
}


void Bin2Int() 
{
	
		int i=0, result=0, base=1;
		binary_size=strlen(binary);
		for(i=binary_size-1 ; i>=0 ; i--)
		{
			if(binary[i]=="1")
			{
				result+=base;
			}
			base*=2;
		}
	
	return;	
}
