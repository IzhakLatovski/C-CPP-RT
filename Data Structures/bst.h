#ifndef H_BST
#define H_BST
#include <stdlib.h>

typedef enum  {OK,AllocationError,NotInTheTree} AdtStatus; 
typedef void (*walkFunction) (int value);
typedef struct tree_t tree_t;

tree_t* createBst(int value);
AdtStatus insertBstNode(tree_t* root, int value);
AdtStatus destroyBst(tree_t* root);
AdtStatus searchInBst(tree_t* root, int value);
AdtStatus deleteBstNode(tree_t* root, int value);
void walkBst(tree_t* root, walkFunction func, int order);

void inorderPrint(tree_t* tree);

#endif