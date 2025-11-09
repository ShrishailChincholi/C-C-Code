// Funcation and Recursion
#include<stdio.h>

// delcaration of Funcation
void funcation_name();

// Creating a Funcation
void funcation_name(){
    printf("hello ..");
}

// Calling Funcation
int main(){
    funcation_name();
    return 0;
}
// OutPut
// hello ..



#include <stdio.h>

void square(int n);
void circule(float r);
void rectangle(int l, int b);

void square(int n)
{
    int sum = n * n;
    printf("%d \n", sum);
}

void circule(float r)
{
    float cir = 3.14 * r * r;
    printf("%f \n", cir);
}

void rectangle(int l, int b)
{
    int res = l * b;
    printf("%d \n", res);
}

int main()
{
    int n,l, b;
    float r;
    printf("Enter a number to find area of squre : ");
    scanf("%d", &n);
    square(n);
   
    printf("Enter length og rectangle l : ");
    scanf("%d", &l);
    printf("Enter bridth of  recatngle b : ");
    scanf("%d", &b);
    rectangle(l,b);

     printf("Enter radius to find r^2  :  ");
    scanf("%f ", &r);
    circule(r);
    return 0;
}

// OutPut
// Enter a number to find area of squre : 5
// 25 
// Enter length og rectangle l : 6
// Enter bridth of  recatngle b : 7
// 42 
// Enter radius to find r^2  :  8
// 200.960007 