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

// Display queue
void display()
{
    if (size == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Value\tPriority\n");

    for (int i = 0; i <= size; i++)
    {
        printf("%d\t%d\n", value[i], priority[i]);
    }
}

int main()
{
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);

    display();

    delete();

    display();

    return 0;
}


// Output
// Value   Priority
// 10      2
// 20      5
// 30      1

// Deleted element: 20

// Value   Priority
// 10      2
// 30      1
