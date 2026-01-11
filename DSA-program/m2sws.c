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