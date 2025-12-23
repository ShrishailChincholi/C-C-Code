// Write A C Program Linked List Insert,deleteion,search
#include <stdio.h> 
#include <stdlib.h> 
 
// Define a structure for a node in the linked list 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Function to display the nodes in the linked list 
void displayNodes(struct Node* head) { 
    if (head == NULL) { 
        printf("Linked List is empty.\n"); 
        return; 
    } 
 
    printf("Linked List nodes: "); 
    while (head != NULL) { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
    printf("\n"); 
} 

 
// Function to insert a node at the beginning of the linked list 
struct Node* insertAtBeginning(struct Node* head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = head; 
    return newNode; 
} 
 

// Function to insert a node at the end of the linked list 
struct Node* insertAtEnd(struct Node* head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
 
    if (head == NULL) { 
        return newNode; 
    } 
 
    struct Node* current = head; 
    while (current->next != NULL) { 
        current = current->next; 
    } 
 
    current->next = newNode; 
    return head; 
} 

 
// Function to delete a node with a specific value from the linked list 
struct Node* deleteNode(struct Node* head, int value) { 

    //If linked List is Emoty Check
    if (head == NULL) { 
        printf("Linked List is empty. Deletion failed.\n"); 
        return NULL; 
    } 

    // 
    if (head->data == value) { 
        struct Node* temp = head; 
        head = head->next; 
        free(temp); 
        printf("Node with value %d deleted.\n", value); 
        return head; 
    } 
 
    struct Node* current = head; 
    while (current->next != NULL && current->next->data != value) { 
        current = current->next; 
    } 
 
    if (current->next == NULL) { 
        printf("Node with value %d not found.\n", value); 
        return head; 
    } 
 
    struct Node* temp = current->next; 
    current->next = current->next->next; 
    free(temp); 
    printf("Node with value %d deleted.\n", value); 
    return head; 
} 
 

// Function to search for a node with a specific value in the linked list 
void searchNode(struct Node* head, int value) { 
    if (head == NULL) { 
        printf("Linked List is empty. Search failed.\n"); 
        return; 
    } 
 
    int position = 1; 
    struct Node* current = head; 
    while (current != NULL && current->data != value) { 
        current = current->next; 
        position++; 
    } 
 
    if (current == NULL) { 
        printf("Node with value %d not found.\n", value); 
    } else { 
        printf("Node with value %d found at position %d.\n", value, position); 
    } 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, value; 
 
    while (1) { 
        printf("\n Menu:\n"); 
        printf("1. Display Nodes\n"); 
        printf("2. Insert at Beginning\n"); 
        printf("3. Inser At End \n"); 
        printf("4. Delete Node\n"); 
        printf("5. Search Node\n"); 
        printf("6. Exit\n"); 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                displayNodes(head);
                break; 
 
            case 2: 
                printf("Enter the value to insert at the beginning: "); 
                scanf("%d", &value); 
                head = insertAtBeginning(head, value); 
                printf("Node with value %d inserted at the beginning.\n", value); 
                break; 
 
            case 3: 
                printf("Enter the value to insert at the end: "); 
                scanf("%d", &value); 
                head = insertAtEnd(head, value); 
                printf("Node with value %d inserted at the end.\n", value); 
                break; 
 
            case 4: 
                printf("Enter the value to delete: "); 
                scanf("%d", &value); 
                head = deleteNode(head, value); 
                break; 
 
            case 5: 
                printf("Enter the value to search: "); 
                scanf("%d", &value); 
                searchNode(head, value); 
                break; 
 
            case 6: 
                printf("Exiting the program.\n"); 
                return 0; 
 
            default: 
                printf("Invalid choice. Please enter a valid option.\n"); 
        } 
    } 
 
    return 0; 
} 

// OutPut
// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 2
// Enter the value to insert at the beginning: 5
// Node with value 5 inserted at the beginning.

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 3
// Enter the value to insert at the end: 6
// Node with value 6 inserted at the end.

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 1
// Linked List nodes: 5 6 

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 4
// Enter the value to delete: 6
// Node with value 6 deleted.

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 1
// Linked List nodes: 5 

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 5
// Enter the value to search: 5
// Node with value 5 found at position 1.

// Menu:
// 1. Display Nodes
// 2. Insert at Beginning
// 3. Insert at End
// 4. Delete Node
// 5. Search Node
// 6. Exit
// Enter your choice: 6
// Exiting the program.