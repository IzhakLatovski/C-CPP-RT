#include "string_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int chosen=1;
	char* string;
	while(chosen>0 && chosen<10)
	{
		printf("Please choose an option:\n");
		printf("1. Create empty string:\n");
		printf("2. Create string:\n");
		printf("3. Copy string:\n");
		printf("4. Use assignment:\n");
		printf("5. Set string:\n");
		printf("6. Get string:\n");
		printf("7. Get length:\n");
		printf("8. Compare 2 strings:\n");
		printf("9. Print string:\n");
		printf("Other - EXIT\n");

		scanf("%d",&chosen);
		switch(chosen)
		{
			case 5:
				printf("Enter the string\n");
				scanf("%s",string);
				string_t case2=string_t(string);
		}
	}
/*
	string_t temp1("izhak");
	temp1.print();
	temp1.setString("Yossi");
	temp1.print();
	const char* gotName=temp1.getString();
	printf("%s\n",gotName);
	temp1.setString("Rita");
	string_t temp2(temp1);
	temp2.print();
	int ln=temp1.length();
	printf("%d\n",ln);
*/
	return 0;
}
