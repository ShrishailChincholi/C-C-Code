// Merge Two Sorted Linked Lists (WITHOUT Extra Space)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node a3 = {5, NULL};
    struct Node a2 = {3, &a3};
    struct Node a1 = {1, &a2};

    struct Node b3 = {6, NULL};
    struct Node b2 = {4, &b3};
    struct Node b1 = {2, &b2};

    struct Node* head = merge(&a1, &b1);
    print(head);
}
// Output
// 1 2 3 4 5 6
