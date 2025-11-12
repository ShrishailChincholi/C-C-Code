// Structure
// collection of values of different data types
#include<stdio.h>
#include<string.h>

struct Student
{
    int roll;
    char name[100];
    float CGPA;
};

int main(){
    struct Student s1;
    s1.roll = 143;
    strcpy(s1.name,"shrishail");
    s1.CGPA = 8.7;
    printf("Student name is %s \n",s1.name);
    printf("Student name is %d \n",s1.roll);
    printf("Student name is %f \n",s1.CGPA);
    return 0;
}

// Output
// Student name is shrishail
//Student name is 143
//Student name is 8.700000

//Array of Structure
#include<stdio.h>
#include<string.h>

struct Student
{
    int roll;
    char name[100];
    float CGPA;
};

int main(){
    struct Student cs[100];  //Array
    cs[0].roll = 143;
    strcpy(cs[0].name,"shrishail");
    cs[0].CGPA = 8.7;

    // // using pointers
    struct Student s1 = {144,"shrishail",8.6};
    struct Student *ptr = &s1;
    printf("Student name is %s \n",cs[0].name);
    printf("Student CGPA using ponters is %f \n",(*ptr).CGPA);
    return 0;
}

// Output
// Student name is shrishail

// Structure using funcation
#include<stdio.h>
#include<string.h>

struct Student
{
    int roll;
    char name[100];
    float CGPA;
};

void printinfo(struct Student s1);

int main(){
    struct Student s1 = {144,"shrishail",8.6};
    printinfo(s1);
}

 void printinfo(struct Student s1){
    printf("Student info :\n");
    printf("Student name is %s \n",s1.name);
    printf("Student name is %d \n",s1.roll);
    printf("Student name is %f \n",s1.CGPA);

 }

 // Output
// Student info :
//Student name is shrishail
//Student name is 144
// Student name is 8.600000

//// Enter address (houseno,block,city,state) of 5 pepole
#include <stdio.h>
struct address
{
    int houseno;
    int block;
    char city[100];
    char state[100];
};

void addinfo(struct address add);

int main()
{
    struct address adds[100];
    printf("Enter a 1st person details ;\n");
    scanf("%d", &adds[0].houseno);
    scanf("%d", &adds[0].block);
    scanf("%s", adds[0].city);
    scanf("%s", adds[0].state);

    printf("Enter a 2nd person details ;\n");
    scanf("%d", &adds[1].houseno);
    scanf("%d", &adds[1].block);
    scanf("%s", adds[1].city);
    scanf("%s", adds[1].state);

    printf("Enter a 3rd person details ;\n");
    scanf("%d", &adds[2].houseno);
    scanf("%d", &adds[2].block);
    scanf("%s", adds[2].city);
    scanf("%s", adds[2].state);

    printf("Enter a 4th person details ;\n");
    scanf("%d", &adds[3].houseno);
    scanf("%d", &adds[3].block);
    scanf("%s", adds[3].city);
    scanf("%s", adds[3].state);

    printf("Enter a 5 person details ;\n");
    scanf("%d", &adds[4].houseno);
    scanf("%d", &adds[4].block);
    scanf("%s", adds[4].city);
    scanf("%s", adds[4].state);

    addinfo(adds[0]);
    addinfo(adds[1]);
    addinfo(adds[2]);
    addinfo(adds[3]);
    addinfo(adds[4]);
}

void addinfo(struct address add){
    printf("address is %d, %d , %s , %s \n",add.houseno,add.block,add.city,add.state);
}

// // Output

// // address is 1, 11 , kalaburagi , karanataka
// //address is 2, 11 , bengalour , karanataka
//// address is 3, 12 , mumbai , Maharastra
//// address is 4, 12 , kalaburagi , karantaka
////  address is 5, 13 , sikam , utrapradiesh