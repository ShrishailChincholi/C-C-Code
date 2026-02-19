#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left =NULL;
    newnode->right =NULL;
    return newnode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return CreateNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left,data);
    }else if(data > root ->data){
        root->right = insert(root->right, data);
    }

    return root;
    
}