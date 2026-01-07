// Print common elements from array

#include <stdio.h>

int main() {
    int x[] = {1, 2, 4, 5, 6};
    int y[] = {2, 3, 5, 7};
    int num1 = 5, num2 = 4;

    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            if (x[i] == y[j]) {
                printf("%d ", x[i]);
                break;
            }
        }
    }
    return 0;
}

// Output
// 2 5