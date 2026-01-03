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

// Function to check if the circular queue is empty 
int isEmpty(struct CircularQueue* queue) { 
    return (queue->front == NULL && queue->rear == NULL); 
} 
 
// Function to enqueue (insert) an element into the circular queue 
void enqueue(struct CircularQueue* queue, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
 
    if (isEmpty(queue)) { 
        queue->front = newNode; 
        queue->rear = newNode; 
        newNode->next = queue->front; // Make it circular 
    } else { 
        queue->rear->next = newNode; 
        queue->rear = newNode; 
        newNode->next = queue->front; // Make it circular 
    } 
 
    printf("%d enqueued into the circular queue.\n", value); 
} 