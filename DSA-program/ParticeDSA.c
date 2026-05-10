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



//  Kadane’s Algorithm (Max Subarray)
#include <stdio.h>

int maxSubArray(int arr[], int n) {
    int max = arr[0], curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = (curr + arr[i] > arr[i]) ? curr + arr[i] : arr[i];
        max = (max > curr) ? max : curr;
    }
    return max;
}



// Fast Exponentiation (Binary Power)
#include <stdio.h>

long long power(long long a, int b) {
    long long res = 1;

    while (b > 0) {
        if (b % 2)
            res *= a;

        a *= a;
        b /= 2;
    }
    return res;
}







// Find Missing Number using XOR
#include <stdio.h>

int missing(int arr[], int n) {
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++)
        xor1 ^= arr[i];

    for (int i = 1; i <= n + 1; i++)
        xor2 ^= i;

    return xor1 ^ xor2;
}



// Longest Substring Without Repeating
#include <stdio.h>

int longestUnique(char *s) {
    int map[256] = {0}, left = 0, max = 0;

    for (int right = 0; s[right]; right++) {
        map[s[right]]++;

        while (map[s[right]] > 1)
            map[s[left++]]--;

        int len = right - left + 1;
        if (len > max) max = len;
    }
    return max;
}




// Bit Manipulation – Find Single Number
#include <stdio.h>

int single(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}





// Fast Power (Binary Exponentiation)
#include <stdio.h>

long long power(long long a, int b) {
    long long res = 1;

    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}




// Majority Element
#include <stdio.h>

int majority(int arr[], int n) {
    int count = 0, candidate;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = arr[i];

        count += (arr[i] == candidate) ? 1 : -1;
    }
    return candidate;
}



// Trap Rain Water

#include <stdio.h>

int trap(int h[], int n) {
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            leftMax = (h[l] > leftMax) ? h[l] : leftMax;
            water += leftMax - h[l++];
        } else {
            rightMax = (h[r] > rightMax) ? h[r] : rightMax;
            water += rightMax - h[r--];
        }
    }
    return water;
}



// Generate All Permutations
#include <stdio.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int r) {
    if (l == r) {
        printf("%s\n", s);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}

int main() {
    char s[] = "ABC";
    permute(s, 0, 2);
}



// Subset Sum Problem

#include <stdio.h>

void subset(int arr[], int n, int i, int sum, int target) {
    if (sum == target) {
        printf("Found\n");
        return;
    }

    if (i == n || sum > target)
        return;

    subset(arr, n, i + 1, sum + arr[i], target);
    subset(arr, n, i + 1, sum, target);
}

int main() {
    int arr[] = {2,4,6,8};
    subset(arr, 4, 0, 0, 10);
}



// Generate All Permutations
#include <stdio.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int r) {
    if (l == r) {
        printf("%s\n", s);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}

int main() {
    char s[] = "ABC";
    permute(s, 0, 2);
}
