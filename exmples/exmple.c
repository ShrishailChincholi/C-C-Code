#include <stdio.h>

int main() {
    unsigned int x = 1;
    char *c = (char*)&x;

    if (*c)
        printf("Little Endian");
    else
        printf("Big Endian");

    return 0;
}

// Output

// Little Endian

// Stack operation
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;


int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}


int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}


void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}