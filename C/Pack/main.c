#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"


int main()
{
	char strings[]="abcapabp";
	packString(strings);
	/*packStringUnion(strings);*/

	return 0;
}
