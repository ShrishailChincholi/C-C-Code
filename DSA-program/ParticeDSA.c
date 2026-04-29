#include <stdio.h>

int trap(int* h, int n) {
    int l = 0, r = n - 1;
    int ml = 0, mr = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            h[l] >= ml ? (ml = h[l]) : (water += ml - h[l]);
            l++;
        } else {
            h[r] >= mr ? (mr = h[r]) : (water += mr - h[r]);
            r--;
        }
    }
    return water;
}

int main() {
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(h) / sizeof(h[0]);
    printf("Water trapped: %d\n", trap(h, n));
    return 0;
}





//   Next Greater Element using Stack

#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop()        { return stack[top--]; }
int isEmpty()    { return top == -1; }

void nextGreater(int* arr, int n) {
    int res[MAX];
    for (int i = 0; i < n; i++) res[i] = -1;

    for (int i = 0; i < n; i++) {
        while (!isEmpty() && arr[stack[top]] < arr[i]) {
            res[pop()] = arr[i];        
        }
        push(i);                      
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n); 
    return 0;
}

  // Output: 5 10 10 -1 -1






//  Detect Cycle in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}



// Two Sum using Hashing (Optimized)
#include <stdio.h>

void twoSum(int arr[], int n, int target) {
    int hash[1000] = {0};

    for (int i = 0; i < n; i++) {
        int diff = target - arr[i];

        if (hash[diff]) {
            printf("Pair: %d %d", arr[i], diff);
            return;
        }
        hash[arr[i]] = 1;
    }
}