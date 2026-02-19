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


int main(){
    struct Node* root = NULL;
    int data,choice;
    do
    {
        menu();
        printf("Enter u r choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            /* code */
            printf("Enter a value to be insert \n");
            scanf("%d",&data);
            root = insert(root,data);
            break;
        case 2:
            printf("Inorder------- \n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("preorder-------");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("postorder-------");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting program ");
            break;
        
        default:
           printf("wrong choice");
            break;
        }

    } while (choice != 5);
    
    return 0;
}

// Output
--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
1
Enter a value to be insert 
1

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
1
Enter a value to be insert 
2

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
1
Enter a value to be insert 
3

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
1
Enter a value to be insert 
4

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
2
Inorder-------
1 2 3 4

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
3
preorder-------
1 2 3 4

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
4
postorder-------
4 3 2 1

--menu---
insert 
inorder  
preorder 
postorder 
Enter u r choice
5
Exiting program
