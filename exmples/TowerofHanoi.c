#include <stdio.h>

// Function to solve Tower of Hanoi
void hanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    hanoi(n-1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    hanoi(n-1, auxiliary, source, destination);
}

int main()
{
    int n = 3;   // number of disks

    hanoi(n, 'A', 'B', 'C');

    return 0;
}

// Output
// Move disk 1 from A to C
// Move disk 2 from A to B
// Move disk 1 from C to B
// Move disk 3 from A to C
// Move disk 1 from B to A
// Move disk 2 from B to C
// Move disk 1 from A to C