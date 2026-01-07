// Print Fibonacci series using recursion.
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int num = 6;

    for (int i = 0; i < num; i++)
        printf("%d ", fibonacci(i));

    return 0;
}

// Output
// 0 1 1 2 3 5 