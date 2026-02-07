#include <stdio.h>

int hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                return 1;  
        }
    }
    return 0;  
}

int main() {
    int arr[] = {1, 2, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n))
        printf("Duplicates found");
    else
        printf("No duplicates");

    return 0;
}

// output
// Duplicates found
