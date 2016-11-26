#include "stdio.h"	
#include <stdlib.h>

typedef struct binaryTreeNode
{
	char data;
	struct binaryTreeNode *lChild, *rChild;
}binaryTreeNode, *binaryTree;

binaryTree createBinaryTree () {
	char data;
	scanf("%c", &data);
	binaryTree T;
	if (data == '#') {
		T = NULL;
	} else {
		T = (binaryTree)malloc(sizeof(binaryTreeNode));
		T -> data = data;
		T -> lChild = createBinaryTree();
		T -> rChild = createBinaryTree();
	}
	return T;
}

int main(int argc, char const *argv[])
{
	createBinaryTree();
	return 0;
}