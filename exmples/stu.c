#include <stdio.h>

struct student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct student s[3];
    int i;

  
    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details of student %d\n", i+1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

 
    printf("\nStudent Records:\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }

    return 0;
}

// Output
// Enter details of student 1
// Enter Roll Number: 101
// Enter Name: Rahul
// Enter Marks: 85

// Enter details of student 2
// Enter Roll Number: 102
// Enter Name: Ankit
// Enter Marks: 90

// Enter details of student 3
// Enter Roll Number: 103
// Enter Name: Neha
// Enter Marks: 88

// Student Records:

// Roll Number: 101
// Name: Rahul
// Marks: 85.00




// Bank Account Sytem mini_projects
#include <stdio.h>

struct bank
{
    int acc_no;
    char name[50];
    float balance;
};

int main()
{
    struct bank customer;
    int choice;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &customer.acc_no);

    printf("Enter Name: ");
    scanf("%s", customer.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &customer.balance);

    printf("\n1. Deposit\n2. Withdraw\n3. Display\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customer.balance += amount;
            printf("Updated Balance: %.2f\n", customer.balance);
            break;

        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount > customer.balance)
                printf("Insufficient Balance\n");
            else
            {
                customer.balance -= amount;
                printf("Remaining Balance: %.2f\n", customer.balance);
            }
            break;

        case 3:
            printf("\nAccount Number: %d\n", customer.acc_no);
            printf("Name: %s\n", customer.name);
            printf("Balance: %.2f\n", customer.balance);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}