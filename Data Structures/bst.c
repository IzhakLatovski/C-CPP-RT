#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


typedef struct node
{  
	int key;
	struct node* right;
    struct node* left;
} node_t;

struct tree
{
	struct node* root;
} tree_t;


static void inorderWalk(node_t* root, walkFunction func);
static void preorderWalk(node_t* root, walkFunction func);
static void postorderWalk(node_t* root, walkFunction func);


tree_t* createBst(int value)
{
    tree_t* temp=(tree_t*)malloc(sizeof(tree_t));
    if(temp==NULL)
    {
        return NULL;
    }
    temp->key=value;

    return temp;
}


AdtStatus destroyBst(tree_t* tree)
{
	if(tree==NULL)
	{
		return AllocationError;
	}
	if(tree->root!=NULL)
	{
		destroyAllNodes(tree->root);
	}

	return OK;
}


AdtStatus insertBstNode(tree_t* tree, int value)
{
	node_t* temp;
	node_t* treeRoot;
    if(tree==NULL)
    {
        return AllocationError;
    }
    temp=(node_t*)malloc(sizeof(node_t));
    if(temp==NULL)
    {
    	return AllocationError;
    }
    temp->key=value;
    temp->left=NULL;
    temp->right=NULL;
    treeRoot=tree->root;
    if(tree->root==NULL)
    {
    	tree->root=temp;
    	return OK;
    }
    if(value<=treeRoot->key)
    {
        treeRoot->left=insertBstNode(treeRoot->left,value);
    }
    else
    {
        treeRoot->right=insertBstNode(treeRoot->right,value);
    }

    return OK;
}



AdtStatus deleteBstNode(tree_t* root, int value)
{

}



AdtStatus searchInBst(tree_t* tree, int value)
{
	node_t* temp=tree->root;
    if(root==NULL)
    {
        return AllocationError;
    }
    if(value==temp->key)
    {
        return OK;
    }
    if(value<temp->key)
    {
        searchInBst(temp->left,value);
    }
    else
    {
        searchInBst(temp->right,value);
    }

    return NotInTheTree;
}



void walkBst(tree_t* tree, walkFunction func, int order)
{
	switch(order)
	{
		case 1:
			inorderWalk(tree->root,walkFunction);
			break;
		case 2:
			preorderWalk(tree->root,walkFunction);
			break;
		case 3:
			postorderWalk(tree->root,walkFunction);
			break;
	}

	return;
}



static void inorderWalk(node_t* root, walkFunction func)
{
	if(root==NULL)
	{
		return;
	}	
	inorderWalk(root->left);
	walkFunction(root->key);
	inorderWalk(root->right);

	return;
}

static void preorderWalk(node_t* root, walkFunction func)
{
	if(root==NULL)
	{
		return;
	}	
	walkFunction(root->key);
	preorderWalk(root->left);
	preorderWalk(root->right);

	return;
}

static void postorderWalk(node_t* root, walkFunction func)
{
	if(root==NULL)
	{
		return;
	}	
	postorderWalk(root->left);
	postorderWalk(root->right);
	walkFunction(root->key);

	return;
}

void inorderPrint(tree_t* tree) 
{ 
    if (tree!=NULL) 
    { 
        inorder(tree->left); 
        printf("%d \n", tree->key); 
        inorder(tree->right); 
    } 
} 


static void destroyAllNodes(node_t* node)
{
	if(node==NULL)
	{
		return;
	}
	destroyAllNodes(node->left);
	destroyAllNodes(node->right);
	free(node);

	return;
}