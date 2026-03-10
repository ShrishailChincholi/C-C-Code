#include <stdio.h>

struct patient
{
    int id;
    char name[30];
    int age;
    char disease[30];
};

void display(struct patient p)
{
    printf("\nPatient Details\n");
    printf("Patient ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Disease: %s\n", p.disease);
}

int main()
{
    struct patient p;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf("%s", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf("%s", p.disease);

    display(p);

    return 0;
}

// Output
// Enter Patient ID: 501
// Enter Name: Ramesh
// Enter Age: 45
// Enter Disease: Fever

// Patient Details
// Patient ID: 501
// Name: Ramesh
// Age: 45
// Disease: Fever