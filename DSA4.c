// Binary seaDrch tree and perform inorder,preorder and postorder traversals. 

#include <stdio.h> 
#include <stdlib.h> 
 
// Define a Node structure for the binary search tree 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
// Function to create a new node with the given data 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 

// Function to insert a new node into the binary search tree 
struct Node* insert(struct Node* root, int data) { 
    if (root == NULL) { 
        return createNode(data); 
    } 
 
    if (data < root->data) { 
        root->left = insert(root->left, data); 
    } else if (data > root->data) { 
        root->right = insert(root->right, data); 
    } 
 
    return root; 
}

// Function for inorder traversal of the binary search tree 
void inorderTraversal(struct Node* root) { 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
} 

// Function for preorder traversal of the binary search tree 
void preorderTraversal(struct Node* root) { 
    if (root != NULL) { 
        printf("%d ", root->data); 
        preorderTraversal(root->left); 
        preorderTraversal(root->right); 
    } 
} 
 
// Function for postorder traversal of the binary search tree 
void postorderTraversal(struct Node* root) { 
    if (root != NULL) { 
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
        printf("%d ", root->data); 
    } 
} 
 