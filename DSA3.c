// Circular queue using Linked list 

#include <stdio.h> 
#include <stdlib.h> 
 
// Define a structure for a node in the circular queue 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Define a structure for the circular queue 
struct CircularQueue { 
    struct Node* front; 
    struct Node* rear; 
}; 
 
// Function to initialize a circular queue 
void initializeQueue(struct CircularQueue* queue) { 
    queue->front = NULL; 
    queue->rear = NULL; 
} 