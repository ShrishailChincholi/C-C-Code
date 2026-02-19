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

void inorder(struct Node* root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}

void preorder(struct Node* root){
    if (root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void postorder(struct Node* root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}

void menu(){
    printf("\n--menu---\n");
    printf("insert \n");
    printf("inorder  \n");
    printf("preorder \n");
    printf("postorder \n");
}
