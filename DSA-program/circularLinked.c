// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void display() {
    struct Node* temp = head;
    if (head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    insert(5);
    insert(10);
    insert(15);

    printf("Circular Linked List:\n");
    display();

    return 0;
}

//output
// Circular Linked List:
// 5 -> 10 -> 15 -> (back to head)