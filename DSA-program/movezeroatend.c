// Move zeros to the end without changing order.
#include <stdio.h>

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int num = 5, index = 0;

    for (int i = 0; i < num; i++) {
        if (arr[i] != 0)
            arr[index++] = arr[i];
    }

    while (index < num)
        arr[index++] = 0;

    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);

    return 0;
}

// Output
// 1 3 12 0 0
