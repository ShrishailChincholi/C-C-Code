#include <stdio.h>
#include <stdlib.h>

/* Definition of Node */
struct Node {
    int data;
    struct Node *next;
};

/* Front and Rear pointers */
struct Node *front = NULL;
struct Node *rear = NULL;

/* Enqueue operation */
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow (Memory not available)\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted: %d\n", value);
}