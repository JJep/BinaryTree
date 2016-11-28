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

typedef struct binaryTreeNode {
    char data;
    int leftFlag = 0,rightFlag = 0;
    struct binaryTreeNode *leftChild,*rightChild,*father;
} binaryTreeNode, *binaryTree;

//先序建立二叉树
binaryTree createBinaryTree() {
    char data;
    std::cin >> data;
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

//非递归建立二叉树
binaryTree noRecursionCreateBinaryTree (binaryTree Tree) {
    char data;
    std::cin >> data;
    binaryTree T;
    if (data == '#') {
        T = NULL;
    } else {
        T = (binaryTree)malloc(sizeof(binaryTreeNode));
        T -> data = data;
        T -> leftChild -> father = Tree;
        T -> leftChild = noRecursionCreateBinaryTree(T);
        T -> rightChild -> father = Tree;
        T -> rightChild = noRecursionCreateBinaryTree(T);
    }
    return T;
}
//MARK: 递归方法遍历二叉树
//先序遍历二叉树
void preOrderTraverse(binaryTree T){
    if(T){
        std::cout << T -> data;
        preOrderTraverse(T->leftChild);
        preOrderTraverse(T->rightChild);
    }
}

//中序遍历二叉树
void inOrderTraverse(binaryTree T){
    if (T) {
        inOrderTraverse(T -> leftChild);
        std::cout << T -> data;
        inOrderTraverse(T -> rightChild);
        
    }
}

//后序遍历二叉树
void postOrderTraverse (binaryTree T) {
    if (T) {
        postOrderTraverse(T -> leftChild);
        postOrderTraverse(T -> rightChild);
        std::cout << T -> data;
        
    }
}

//MARK: 非递归方法遍历二叉树


void noRecursionPreOrderTraverse (binaryTree T){
    while (T != NULL) {
        std::cout << T -> data;
        if (T -> leftChild != NULL && T -> leftFlag == 1) {
            T -> leftFlag = 1;
            T = T -> leftChild;
        } else if ( T -> rightChild != NULL && T -> rightFlag == 1){
            T -> rightFlag = 1;
            T = T -> rightChild;
        } else {
            T = T -> father;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    binaryTree tree;
//    tree = createBinaryTree(); //非递归创建二叉树
    tree = (binaryTree)malloc(sizeof(binaryTreeNode));
    char data;
    std::cin >> data;
    if (data != '#') {
        tree -> data = data;
        tree -> leftChild = noRecursionCreateBinaryTree(tree);
        tree -> rightChild = noRecursionCreateBinaryTree(tree);
    }
    std::cout << "Hello, World!\n";
    preOrderTraverse(tree);
    noRecursionPreOrderTraverse(tree);
    inOrderTraverse(tree);
    postOrderTraverse(tree);
    return 0;
}


