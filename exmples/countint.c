// Count Set Bits in an Integer

#include <stdio.h>

int main() {
    int n = 15, count = 0;

    while (n) {
        count += n & 1;
        n >>= 1;
    }

    printf("Set bits = %d", count);
    return 0;
}

// Output
// Set bits = 4
