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



/* REGULAR CREATE
tree_t* createBst(int value)
{
    tree_t* temp=(tree_t*)malloc(sizeof(tree_t));
    if(temp==NULL)
    {
        return NULL;
    }
    temp->key=value;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
*/



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



/* REGULAR DESTROY
void destroyBst(tree_t* root)
{
	if(root!=NULL)
	{
		if((root->left==NULL) && (root->right==NULL))
		{
			free(root);
		}
		else
		{
			destroyBst(root->left);
			destroyBst(root->right);
		}
	}

	return;
}
*/


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


/* REGULAR INSERT
tree_t* insertBstNode(tree_t* root, int value)
{
    if(root==NULL)
    {
        return createBst(value);
    }
    if(value<=root->key)
    {
        root->left=insertBstNode(root->left,value);
    }
    else
    {
        root->right=insertBstNode(root->right,value);
    }

    return root;
}
*/


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


/* REGULAR DELETE
tree_t* deleteBstNode(tree_t* root, int value)
{
    tree_t* temp;
    tree_t* father;
    if(value<root->key)
    {
    	root->left=deleteBstNode(root->left,value);
    }
    else if(value>root->key)
    {
    	root->right=deleteBstNode(root->right,value);
    }
    else
    {
    	if(root->left==NULL)
    	{
    		temp=root->right;
    		free(root);
    		root=temp;
    	}
    	else if(root->right==NULL)
    	{
    		temp=root->left;
    		free(root);
    		root=temp;
    	}
    	else
    	{
    		temp=root->right;
    		while(temp->left!=NULL)
    		{
    			father=temp;
    			temp=temp->left;
    		}
    		root->key=temp->key;
    		if(father!=NULL)
    		{
    			father->left=deleteBstNode(father->left,father->left->key);
    		}
    		else
    		{
    			root->right=deleteBstNode(root->right,root->right->key);
    		}
    	}
    }
*/


AdtStatus deleteBstNode(tree_t* tree, int value)
{
	node_t* temp=root;
	node_t* result;
	if(tree==NULL)
	{
		return AllocationError;
	}
	if(searchInBst(tree,value)!=OK)
	{
		return NotInTheTree;
	}
	if(value>temp->key)
	{
		temp->right=deleteBstNode(temp->right,value);
	}
	else if(value<temp->key)
	{
		temp->left=deleteBstNode(temp->left,value);
	}
	else
	{
		if(temp->left==NULL)
		{
			result=temp->right;
		}
		else
		{
			result=temp->left;
		}
	}

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
