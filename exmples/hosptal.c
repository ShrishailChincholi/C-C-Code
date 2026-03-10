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