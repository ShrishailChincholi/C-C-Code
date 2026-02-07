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


