#include <stdio.h>

struct employee
{
    int id;
    char name[30];
    float basic, hra, da, total;
};


void calculate(struct employee *e)
{
    e->hra = 0.20 * e->basic;
    e->da = 0.10 * e->basic;
    e->total = e->basic + e->hra + e->da;
}

void display(struct employee e)
{
    printf("\nEmployee Details\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Salary: %.2f\n", e.basic);
    printf("HRA: %.2f\n", e.hra);
    printf("DA: %.2f\n", e.da);
    printf("Total Salary: %.2f\n", e.total);
}
int main()
{
    struct employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf("%s", e.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &e.basic);

    calculate(&e);

    display(e);

    return 0;
}

// Output
// Enter Employee ID: 101
// Enter Name: Rahul
// Enter Basic Salary: 20000

// Employee Details
// ID: 101
// Name: Rahul
// Basic Salary: 20000.00
// HRA: 4000.00
// DA: 2000.00
// Total Salary: 26000.00