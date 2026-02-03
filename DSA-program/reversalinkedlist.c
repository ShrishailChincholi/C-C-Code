// Reverse a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // store next node
        curr->next = prev; // reverse link
        prev = curr;       // move prev ahead
        curr = next;       // move curr ahead
    }
    return prev; // new head
}

int main()
{
    struct Node *head = NULL;

    /* Creating linked list */
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original Linked List:\n");
    display(head);

    /* Reversing linked list */
    head = reverseList(head);

    printf("Reversed Linked List:\n");
    display(head);

    return 0;
}

// Output
// Original Linked List:
// 10 -> 20 -> 30 -> 40 -> NULL
// Reversed Linked List:
// 40 -> 30 -> 20 -> 10 -> NULL
