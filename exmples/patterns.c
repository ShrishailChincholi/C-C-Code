#include <stdio.h>

int main() {
    int n = 5;

    for (int i = n; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}

// output
// *********
//  *******
//   *****
//    ***
//     *


#include <stdio.h>

int main() {
    int n = 4;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}


// output
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf("  ");
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}


// Output
//         * 
//       * * 
//     * * * 
//   * * * * 
// * * * * * 



#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

// Output
// * * * * * 
// *       * 
// *       * 
// *       * 
// * * * * * 


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

// Output
// *       *
//   *   *
//     *
//   *   *
// *       *


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++) {
            if (j == 1 || j == 2*i - 1 || i == n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

// Output
//     *
//    * *
//   *   *
//  *     *
// *********



// Binary Search in C
#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;         
        else if (arr[mid] < key)
            low = mid + 1;       
        else
            high = mid - 1;     
    }
    return -1;                  
}

int main() {
    int arr[] = {5, 12, 18, 25, 33, 47, 59};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 25;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}

// Output
// Element 25 found at index 3