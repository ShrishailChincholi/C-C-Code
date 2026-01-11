// Merge Two Sorted Linked Lists (WITHOUT Extra Space)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


// Function to merge two sorted linked lists
struct Node* merge(struct Node* a, struct Node* b) {

    // Base case: if first list is empty and  return second list
    if (!a) return b;

     // Base case: if second list is empty, return first list
    if (!b) return a;


     // If data of first list is smaller
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
          // Recursively merge remaining elements
        b->next = merge(a, b->next);
        return b;  // return current node of list B
    }
}


// Function to print the merged linked list
void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    // First sorted linked list: 1 -> 3 -> 5
    struct Node a3 = {5, NULL};
    struct Node a2 = {3, &a3};
    struct Node a1 = {1, &a2};


    // Second sorted linked list: 2 -> 4 -> 6
    struct Node b3 = {6, NULL};
    struct Node b2 = {4, &b3};
    struct Node b1 = {2, &b2};

     // Merge both lists
    struct Node* head = merge(&a1, &b1);
    print(head);
}
// Output
// 1 2 3 4 5 6
