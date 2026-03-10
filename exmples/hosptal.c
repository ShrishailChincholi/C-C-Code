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