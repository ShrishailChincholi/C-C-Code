#include <stdio.h>

int safe_first(int arr[], int n, int *exists) {
    if (n == 0) {
        *exists = 0;
        return 0;
    }
    *exists = 1;
    return arr[0];
}

int safe_last(int arr[], int n, int *exists) {
    if (n == 0) {
        *exists = 0;
        return 0;
    }
    *exists = 1;
    return arr[n - 1];
}

void safe_middle(int arr[], int n) {
    if (n <= 2) {
        printf("Middle: []\n");
        return;
    }

    printf("Middle: ");
    for (int i = 1; i < n - 1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int exists;

    int first = safe_first(arr, n, &exists);
    if (exists)
        printf("First: %d\n", first);
    else
        printf("First: None\n");

    int last = safe_last(arr, n, &exists);
    if (exists)
        printf("Last: %d\n", last);
    else
        printf("Last: None\n");

    safe_middle(arr, n);

    return 0;
}

// output
// First: 10
// Last: 50
// Middle: 20 30 40

