
#include <iostream>
#include <stdio.h>
#include <string.h>

#define STACK_INIT_SIZE 100;
#define STASCKINCREMENT 10;
#define TRUE 1;
#define FALSE 0;
#define OK 1;
#define ERROR 0;
#define OVERFLOW -2;

using namespace std;
typedef int Status;

//定义二叉树的数据结构
typedef struct binaryTreeNode {
    char data;
    struct binaryTreeNode *leftChild,*rightChild;
} binaryTreeNode, *binaryTree;

//定义二叉树栈的数据结构
typedef struct {
    binaryTreeNode *base;
    binaryTreeNode *top;
    int stackSize;
} treeStack;

Status initTreeStack (treeStack &treeStack) {
    treeStack.base = (binaryTree)malloc(STACK_INIT_SIZE * sizeof(binaryTreeNode));
    if (!treeStack.base)
        exit(OVERFLOW);
    treeStack.top = treeStack.base;
    treeStack.stackSize = STACK_INIT_SIZE;
    return OK;
    
}

//先序建立二叉树
binaryTree createBinaryTree() {
    char data;
    cin >> data;
    binaryTree T;
    if (data == '#') {
        T = NULL;
    } else {
        T = (binaryTree)malloc(sizeof(binaryTreeNode));
        T -> data = data;
        T -> leftChild = createBinaryTree();
        T -> rightChild = createBinaryTree();
    }
    return T;
}

//MARK: 递归方法遍历二叉树
//先序遍历二叉树
void preOrderTraverse(binaryTree T){
    if(T){
        cout << T -> data;
        preOrderTraverse(T->leftChild);
        preOrderTraverse(T->rightChild);
    }
}

//中序遍历二叉树
void inOrderTraverse(binaryTree T){
    if (T) {
        inOrderTraverse(T -> leftChild);
        cout << T -> data;
        inOrderTraverse(T -> rightChild);
        
    }
}

//后序遍历二叉树
void postOrderTraverse (binaryTree T) {
    if (T) {
        postOrderTraverse(T -> leftChild);
        postOrderTraverse(T -> rightChild);
        cout << T -> data;
        
    }
}

//MARK: 非递归方法遍历二叉树



int main(int argc, const char * argv[]) {
    // insert code here...
//     binaryTree tree;
//     tree = createBinaryTree(); //非递归创建二叉树
// //    tree = (binaryTree)malloc(sizeof(binaryTreeNode));
// //    
// //    
    cout << "Hello, World!\n";
//     preOrderTraverse(tree);
//     inOrderTraverse(tree);
//     postOrderTraverse(tree);
    return 0;
}


