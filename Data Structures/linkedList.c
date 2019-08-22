#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int value;
	struct node* next;
} node_t;

node_t* flipLinkedList (node_t* node);
node_t* findMiddleOfLinkedList (node_t* node);
int findLoopInLinkedList (node_t* node);
node_t* findCommonNode (node_t* nodeOne, node_t* nodeTwo);
void printLinkedList (node_t* node);


int main()
{
	int i=0;

	node_t* aa=malloc(sizeof(node_t));
	node_t* ab=malloc(sizeof(node_t));
	node_t* ac=malloc(sizeof(node_t));
	node_t* ad=malloc(sizeof(node_t));
	node_t* ae=malloc(sizeof(node_t));

	node_t* ba=malloc(sizeof(node_t));
	node_t* bb=malloc(sizeof(node_t));
	node_t* bc=malloc(sizeof(node_t));
	node_t* bd=malloc(sizeof(node_t));

	aa->value=9;
	aa->next=ab;
	ab->value=5;
	ab->next=ac;
	ac->value=1444;
	ac->next=ad;
	ad->value=50;
	ad->next=ae;
	ae->value=19;
	ae->next=NULL;

	ba->value=3;
	ba->next=bb;
	bb->value=5;
	bb->next=bc;
	bc->value=7;
	bc->next=bd;
	bd->value=2;
	bd->next=NULL;	

	/*---------------------------TEST 1---------------------------*/
	/*
	flipLinkedList(aa);
	printLinkedList(ae);
	*/

	/*---------------------------TEST 2---------------------------*/
	/*
	printf("%d is the value in the middle\n",findMiddleOfLinkedList(bd)->value);
	*/

	/*---------------------------TEST 3---------------------------*/
	/*
	ac->next=aa;
	printf("%d (0 if no loops. 1 if there is a loop\n",findLoopInLinkedList(aa));
	*/

	/*---------------------------TEST 4---------------------------*/
	/*
	bb->next=ab;
	printf("%d is the value of the first common node of the lists\n",findCommonNode(aa,ba)->value);
	*/

	free(aa);
	free(ab);
	free(ac);
	free(ad);
	free(ae);

	free(ba);
	free(bb);
	free(bc);
	free(bd);

	return 0;
}

node_t* flipLinkedList (node_t* node)
{
	node_t* nextNode;
	node_t* previousNode;
	/* make the first one point to null */
	if(node->next!=NULL)
	{
		nextNode=node->next;
		previousNode=node;
		node->next=NULL;
		node=nextNode;
	}
	/* while im not the last one */
	while(node->next!=NULL)
	{
		nextNode=node->next;
		node->next=previousNode;
		previousNode=node;
		node=nextNode;
	}
	/* if Im the last one */
	node->next=previousNode;

	return node;
}

node_t* findMiddleOfLinkedList (node_t* node)
{
	node_t* currentNode=node;
	node_t* lastNode=node;
	/* if list is size of 1 or 2, return first one */
	if(node->next==NULL || node->next->next==NULL)
	{
		return node;
	}
	while(lastNode!=NULL && lastNode->next!=NULL)
	{
		currentNode=currentNode->next;
		lastNode=lastNode->next->next;
	}
	return currentNode;
}

int findLoopInLinkedList (node_t* node)
{
	node_t* currentNode=node;
	node_t* lastNode=node;
	/* if list is size of 1, no loops */
	if(currentNode->next==NULL)
	{
		return 0;
	}
	while(lastNode!=NULL && lastNode->next!=NULL)
	{
		currentNode=currentNode->next;
		lastNode=lastNode->next->next;
		if(currentNode==lastNode)
		{
			return 1;
		}
	}
	return 0;
}

node_t* findCommonNode (node_t* nodeOne, node_t* nodeTwo)
{
	int firstLength=1, secondLength=1, difference=0, i=0;
	node_t* firstNode=nodeOne;
	node_t* secondNode=nodeTwo;
	while(firstNode->next!=NULL)
	{
		firstLength++;
		firstNode=firstNode->next;
	}
	while(secondNode->next!=NULL)
	{
		secondLength++;
		secondNode=secondNode->next;
	}
	firstNode=nodeOne;
	secondNode=nodeTwo;
	if(firstLength-secondLength>0)
	{
		difference=firstLength-secondLength;
		for(i=0 ; i<difference ; i++)
		{
			firstNode=firstNode->next;
		}
	}
	else
	{
		difference=secondLength-firstLength;
		for(i=0 ; i<difference ; i++)
		{
			secondNode=secondNode->next;
		}
	}
	while(1)
	{
		if(firstNode==secondNode)
		{
			return firstNode;
		}
		firstNode=firstNode->next;
		secondNode=secondNode->next;
	}
}

void printLinkedList (node_t* node)
{
	while(node!=NULL)
	{
		printf("%d ",node->value);
		node=node->next;
	}
		printf("\n");

}