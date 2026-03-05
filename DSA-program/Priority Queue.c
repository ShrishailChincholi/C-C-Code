#include <stdio.h>

#define MAX 5

int value[MAX];
int priority[MAX];
int size = -1;

// Insert element with priority
void insert(int val, int pr)
{
    if (size == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    size++;
    value[size] = val;
    priority[size] = pr;
}

// Delete highest priority element
void delete()
{
    if (size == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i <= size; i++)
    {
        if (priority[i] > priority[highest])
        {
            highest = i;
        }
    }

    printf("Deleted element: %d\n", value[highest]);

    for (int i = highest; i < size; i++)
    {
        value[i] = value[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}