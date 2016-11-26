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

#define ElemType char

typedef struct binaryTreeNode {
    char data;
    struct binaryTreeNode *leftChild,*rightChild;
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

void postOrderTraverse (binaryTree T) {
    if (T) {
        postOrderTraverse(T -> leftChild);
        postOrderTraverse(T -> rightChild);
        std::cout << T -> data;
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    binaryTree tree;
    tree = createBinaryTree();
    std::cout << "Hello, World!\n";
    preOrderTraverse(tree);
    inOrderTraverse(tree);
    postOrderTraverse(tree);
    return 0;
}


