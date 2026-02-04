#include <stdio.h>

int main() {
    int x = 1;
    char *c = (char*)&x;

    if (*c)
        printf("Little Endian");
    else
        printf("Big Endian");

    return 0;
}

// Output
// Little Endian
