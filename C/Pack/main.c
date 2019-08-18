#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pack.h"


int main()
{
	char strings[]="abcapabp";
	
	/*choose one of the two (same result)*/

	packString(strings);
	/*packStringUnion(strings);/*

	return 0;
}
