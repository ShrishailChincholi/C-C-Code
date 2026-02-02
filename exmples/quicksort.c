#include <stdio.h>

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i < j) {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high) {
    int pi;
    if (low < high) {
        pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main() {
    int a[] = {4, 6, 2, 8, 3};
    int n = 5;

    printf("Before sorting:\n");
    display(a, n);

    quicksort(a, 0, n - 1);

    printf("After sorting:\n");
    display(a, n);

    return 0;
}


// OutPut
// Before sorting ;--
//  4  6  2  8  3 
// After sorting ;--
//  2  3  4  6  8 