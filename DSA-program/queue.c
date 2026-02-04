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

/* Dequeue operation */
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow (Queue is empty)\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


// output
// --- Queue Using Linked List ---
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice: 1
// Enter value to insert: 10
// Inserted: 10

// Enter your choice: 1
// Enter value to insert: 20
// Inserted: 20

// Enter your choice: 3
// Queue elements: 10 -> 20 -> NULL

// Enter your choice: 2
// Deleted: 10

// Enter your choice: 3
// Queue elements: 20 -> NULL

