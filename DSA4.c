// Binary search tree and perform inorder,preorder and postorder traversals. 

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