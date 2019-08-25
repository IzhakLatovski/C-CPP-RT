#include <stdio.h>
#include "bst.h"

int main()
{
	tree_t* test;
	test=createBst(5);
	insertBstNode(test,8);

	inorderPrint(test);

	return 0;
}