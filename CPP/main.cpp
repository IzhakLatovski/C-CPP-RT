#include "string_t.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	string_t temp;
	string_t temp1("izhak");
	temp1.print();
	temp1.setString("Yossi");
	temp1.print();
	const char* gotName=temp1.getString();
	printf("%s",gotName);
	string_t temp2(temp1);
	temp2.print();
	temp1.setString("Rita");
	string_t temp3=temp1;
	temp3.print();
	int len=temp3.length();
	printf("%d\n",len);

	temp1.setString("Qri");
	temp2.setString("Ori");

	int compared=temp1.compare(temp2);
	printf("%d\n",compared);

	temp.setString("AAAAAA");
	temp.print();


	return 0;
}