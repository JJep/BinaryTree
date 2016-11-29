//
//  main.cpp
//  BinaryTree
//
//  Created by Jep Xia on 16/11/20.
//  Copyright © 2016年 Jep Xia. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define OVERFLOW        -2

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

Status initTreeStack (treeStack &stack) {
    stack.base = (binaryTreeNode * )malloc( STACK_INIT_SIZE * sizeof(binaryTreeNode) );
    if (!stack.base)
        exit(OVERFLOW);
    stack.top = stack.base;
    stack.stackSize = STACK_INIT_SIZE;
    return OK;
    
}

Status getTop (treeStack stack, binaryTreeNode &element) {
    if (stack.top == stack.base) {
        return ERROR;
    }
    element = * (stack.top - 1);
    return OK;
}

Status push (treeStack &stack, binaryTreeNode element) {
    if (stack.top - stack.base >= stack.stackSize) {
        stack.base = (binaryTree)realloc(stack.base, (stack.stackSize + STACKINCREMENT) * sizeof(binaryTreeNode));
        stack.top = stack.base + stack.stackSize;
        stack.stackSize += STACKINCREMENT;
    }
    * stack.top++ = element;
    return OK;
}

Status pop (treeStack &stack, binaryTreeNode element) {
    if (stack.top == stack.base)  return ERROR;
    element = *--stack.top;
    return OK;
    
}

Status empty(treeStack stack) {
    if (stack.base == stack.top) {
        return OK;
    }
    return ERROR;
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
void preOrderTraverse2 (binaryTree T, treeStack &treeStack){
//    while ( T != NULL) {
//        push(treeStack, *T);
//        cout << T -> data;
//        preOrderTraverse2(T -> leftChild, treeStack);
//        preOrderTraverse2(T -> rightChild, treeStack);
//        pop(treeStack, *T);
//        getTop(treeStack, *T);
////        preOrderTraverse2(T -> rightChild, treeStack);
////        pop(treeStack, *T);
////        getTop(treeStack, *T);
//        
//    }
    binaryTree Tree;
    Tree = (binaryTree)malloc(sizeof(binaryTreeNode));
    while(T!=NULL||!empty(treeStack))
    {
        while(T!=NULL)
        {
            cout<<T->data<<" ";
            push(treeStack, *T);
            T = T -> leftChild;
        }
        if(empty(treeStack) != OK)
        {
            getTop(treeStack, *Tree);
            pop(treeStack, *Tree);
            T = Tree;
            T = T -> rightChild;
        }
    }
}


int main(int argc, const char * argv[]) {
    binaryTree tree;
    treeStack stack;
    initTreeStack(stack);
    tree = createBinaryTree();
    cout << "Hello, World!\n";
    preOrderTraverse(tree);
    preOrderTraverse2(tree, stack);
//    inOrderTraverse(tree);
//    postOrderTraverse(tree);
    return 0;
}


