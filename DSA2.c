#include <stdio.h> 
#include <stdlib.h> 
 
// Define a structure for a node in the stack 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Function to create a new node 
struct Node* createNode(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    return newNode; 
} 
 
// Function to push an element onto the stack 
struct Node* push(struct Node* top, int value) { 
    struct Node* newNode = createNode(value); 
    newNode->next = top; 
    return newNode; 
} 
 
// Function to pop an element from the stack 
struct Node* pop(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack underflow. Cannot pop from an empty stack.\n");
           return NULL; 
    } 
 
    struct Node* temp = top; 
    top = top->next; 
    free(temp); 
    return top; 
} 
 
// Function to display the elements in the stack 
void display(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
 
    printf("Stack elements: "); 
    while (top != NULL) { 
        printf("%d ", top->data); 
        top = top->next; 
    } 
    printf("\n"); 
} 
 
int main() { 
    struct Node* top = NULL; 
    int choice, value; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Display\n"); 
        printf("4. Exit\n"); 
 
        printf("Enter your choice: ");
         scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter the value to push onto the stack: "); 
                scanf("%d", &value); 
                top = push(top, value); 
                printf("%d pushed onto the stack.\n", value); 
                break; 
 
            case 2: 
                top = pop(top); 
                break; 
 
            case 3: 
                display(top); 
                break; 
 
            case 4: 
                printf("Exiting the program.\n"); 
                // Free memory for remaining nodes in the stack 
                while (top != NULL) { 
                    struct Node* temp = top; 
                    top = top->next; 
                    free(temp); 
                } 
                return 0; 
 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } 
 
    return 0; 
}