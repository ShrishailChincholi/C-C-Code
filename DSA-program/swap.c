// C program for swapping two numbers using pointers,
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 20, b = 30;
    printf("Before Swapping:\n");
    printf("a:%d , b:%d\n", a, b);
    swap(&a, &b);
    printf("After Swapping:\n");
    printf("a : %d , b : %d\n", a, b);
    return 0;
}
// output
// Before swapping:
// a : 20, b: 30
// After swapping:
// a : 30, b : 20
