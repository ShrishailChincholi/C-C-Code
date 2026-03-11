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


void updatePatient()
{
    int id,i,found=0;

    printf("Enter Patient ID to update: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id==id)
        {
            printf("Enter new Name: ");
            scanf("%s",p[i].name);

            printf("Enter new Age: ");
            scanf("%d",&p[i].age);

            printf("Enter new Disease: ");
            scanf("%s",p[i].disease);

            printf("Record Updated\n");
            found=1;
        }
    }

    if(found==0)
    printf("Patient not found\n");
}


void searchPatient()
{
    int id,i,found=0;

    printf("Enter Patient ID to search: ");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(p[i].id==id)
        {
            printf("\nPatient Found\n");
            printf("Name: %s\n",p[i].name);
            printf("Age: %d\n",p[i].age);
            printf("Disease: %s\n",p[i].disease);
            found=1;
        }
    }

    if(found==0)
    printf("Patient not found\n");
}

int main()
{
    int choice;

    addPatients();

    printf("\n1. Display Patients");
    printf("\n2. Search Patient");
    printf("\n3. Update Patient");
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: displayPatients(); break;
        case 2: searchPatient(); break;
        case 3: updatePatient(); break;
        default: printf("Invalid choice");
    }

    return 0;
}

// Output
// Enter number of patients: 2

// Enter details of patient 1
// Patient ID: 101
// Name: Ravi
// Age: 30
// Disease: Fever

// Enter details of patient 2
// Patient ID: 102
// Name: Sita
// Age: 25
// Disease: Cold

// 1. Display Patients
// 2. Search Patient
// 3. Update Patient
// Enter choice: 1

// Patient Records

// ID: 101
// Name: Ravi
// Age: 30
// Disease: Fever

// ID: 102
// Name: Sita
// Age: 25
// Disease: Cold