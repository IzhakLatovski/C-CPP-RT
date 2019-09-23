#include "string_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{/*
	int chosen=1, index=0;
	char* temp;
	string_t string1, string2;
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
			case 1:
			{
				string1();
				break;
			}
			case 2:
			{
				printf("Enter the string to put in the new object:\n");
				scanf("%s",temp);
				string2(temp);
				break;
			}
			case 9:
			{
				string2.print();
				break;
			}/*
			case 5:
				printf("Enter the string\n");
				scanf("%s",temp);
				string_t case2=string_t(temp);
		}*/
	

	string_t temp1("izhak");
	temp1.print();
	temp1.setString("Yossi");
	temp1.print();
	const char* gotName=temp1.getString();
	printf("%s\n",gotName);
	temp1.setString("RITA");
	string_t temp2(temp1);
	temp2.print();
	int ln=temp1.length();
	printf("%d\n",ln);
	temp1.toLower();
	temp1.print();
	temp2.setString("AbCdE");
	temp2.print();
	temp2.toUpper();
	temp2.print();
	temp2.toLower();
	temp1.print();
	temp2.print();
	printf("----%d----\n",(temp1>temp2));
	printf("----%d----\n",(temp1<temp2));
	printf("----%d----\n",(temp1<=temp2));
	printf("----%d----\n",(temp1>=temp2));
	printf("----%d----\n",(temp1==temp2));
	printf("----%d----\n",(temp1!=temp2));
	temp1+=temp2;
	temp1.print();
	temp1.setString("rita");
	temp1.prepend(temp2);
	temp1.print();
	temp1.prepend("|||");
	temp1.print();
	temp1+="???";
	temp1.print();
	printf("%d\n",temp1.contains("ta?"));
	printf("%d\n",temp1.length());
	printf("---%c---\n",temp1[7]);
	temp1[2]='T';
	cout<<temp1;
	cin>>temp1;
	temp1.print();

	return 0;
}
