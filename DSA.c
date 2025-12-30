// Write C Program Linked List - display and count

#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to display the nodes in the linked list

void displayNodes(struct Node *head)
{
    printf("Linked List nodes: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    // Initialize an empty linked list
    struct Node *head = NULL;
    // Add nodes to the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    // Second Node
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = NULL;
    head->next = second;

    // Third node
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->data = 3;
    third->next = NULL;
    second->next = third;

    // Display nodes in the linked list
    displayNodes(head);

    // Count number of nodes in the linked list
    int nodeCount = countNodes(head);

    printf("Number of nodes in the linked list: %d\n", nodeCount);
    // Free allocated memory for the linked list nodes
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

// OutPut 
// Linked List nodes: 1 2 3 
// Number of nodes in the linked list: 3