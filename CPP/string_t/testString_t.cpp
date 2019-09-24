/********************************************************/
/*		                                                */
/*      NO TIME TO MAKE THE TESTING MODULE PROPERLY     */
/* The second part(bottom note), tests all the features */  										 */
/*  										            */
/********************************************************/

#include "string_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int chosen=1, objectNumber=0;
	char testString[64];
	string_t string1, string2;
	printf("You have 2 empty objects, and now create 3rd with your text:\n");
	printf("Enter your string:\n");
	scanf("%s",testString);
	string_t string3(testString);
	while(chosen>0 && chosen<10)
	{
		printf("Please choose an option:\n");
		printf("1. Print string:\n");
		printf("2. Change string:\n");

		/*
		printf("3. Copy string:\n");
		printf("4. Use assignment:\n");
		printf("5. Set string:\n");
		printf("6. Get string:\n");
		printf("7. Get length:\n");
		printf("8. Compare 2 strings:\n");
		printf("9. Print string:\n");*/
		printf("Other - EXIT\n");
		scanf("%d",&chosen);
		switch(chosen)
		{
			case 1:
			{
				printf("Enter the object number (1/2/3)\n");
				scanf("%d",&objectNumber);
				if(objectNumber==1)
				{
					string1.print();
				}
				else if(objectNumber==2)
				{
					string2.print();
				}
				else if(objectNumber==3)
				{
					string3.print();
				}
				break;
			}/*
			case 2:
			{
				printf("Enter the object number (1/2/3)\n");
				scanf("%d",&objectNumber);
				printf("Enter the string to put\n");
				scanf("%s",&testString);
				if(objectNumber==1)
				{
					string1.setString(testString);
				}
				else if(objectNumber==2)
				{
					string2.setString(testString);
				}
				else if(objectNumber==3)
				{
					string3.setString(testString);
				}
				break;
			}*/
		}
	}
			/*
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
			}
			case 5:
				printf("Enter the string\n");
				scanf("%s",temp);
				string_t case2=string_t(temp);*/
	/*
	string_t temp1("izhak");
	temp1.print();
	temp1.setString("Yossi");
	temp1.print();
	printf("NUMBER OF OBJECTS : %lu\n",temp1.getNumberOfObjects());

	const char* gotName=temp1.getString();
	printf("%s\n",gotName);
	temp1.setString("RITA");
	string_t temp2(temp1);
	printf("NUMBER OF OBJECTS : %lu\n",temp1.getNumberOfObjects());
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
	temp1.setString("Izhakizhaka");
	temp2.setString("izhAk");
	printf("----%d----\n",(temp1>temp2));
	printf("----%d----\n",(temp1<temp2));
	printf("----%d----\n",(temp1>=temp2));
	printf("----%d----\n",(temp1<=temp2));
	printf("----%d----\n",(temp1==temp2));
	printf("----%d----\n",(temp1!=temp2));
	printf("%lu\n",temp1.firstOccurrence('a'));
	printf("%lu\n",temp1.lastOccurrence('A'));
	printf("NUMBER OF OBJECTS : %lu\n",temp2.getNumberOfObjects());
	temp1.print();/*
	string_t temp3=temp1(8,4);
	temp3.print();/*
	temp1+=temp2;
	temp1.print();
	temp1.setString("rita");
	temp1.prepend(temp2);
	temp1.print();
	temp1.prepend("|||");
	temp1.print();
	temp1+="???";
	temp1.print();
	printf("%d\n",temp1.contains("Ta??"));
	printf("%lu\n",temp1.length());
	printf("---%c---\n",temp1[7]);
	temp1[0]='Z';
	cout<<temp1;
	cin>>temp2;
	temp1.print();
	printf("%lu",temp1.getDefaultCapacity());
	printf("%lu",temp2.getDefaultCapacity());
	temp2.print();
	printf("\n%d\n",temp1.compare(temp2));*/

	return 0;
}
