// Check if number is power of 2.
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number\n");
    scanf("%d",&num);

    if (num > 0 && (num & (num - 1)) == 0)
        printf("Power of 2");
    else
        printf("Not Power of 2");

    return 0;
}

// Output
// Enter a number 16
// power of 2