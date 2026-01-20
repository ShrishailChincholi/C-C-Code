//   Memory Leak Detector (Simple Simulation)

#include <stdio.h>
#include <stdlib.h>

static int allocCount = 0;

void* myMalloc(size_t size) {
    allocCount++;
    return malloc(size);
}

void myFree(void* ptr) {
    if (ptr) {
        allocCount--;
        free(ptr);
    }
}

int main() {
    int* a = myMalloc(sizeof(int));
    int* b = myMalloc(sizeof(int));

    myFree(a);

    printf("Leaks = %d\n", allocCount);
    return 0;
}

// Output 
// Leaks = 1
