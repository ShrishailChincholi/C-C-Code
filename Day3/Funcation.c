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

// Exmple
#include <stdio.h>

int square(int n);
float circule(float r);
int rectangle(int l, int b);

int square(int n)
{
    int sum = n * n;
    printf("%d \n", sum);
}

float circule(float r)
{
    float cir = 3.14 * r * r;
    printf("%f \n", cir);
}

int rectangle(int l, int b)
{
    int res = l * b;
    printf("%d \n", res);
}

int main()
{
    int n, l, b;
    float r;
    printf("Enter a number to find area of squre : ");
    scanf("%d", &n);
    square(n);

    printf("Enter radius to find r^2  :  ");
    scanf("%f", &r);
    circule(r);

    printf("Enter length og rectangle l : ");
    scanf("%d", &l);
    printf("Enter bridth of  recatngle b : ");
    scanf("%d", &b);
    rectangle(l, b);

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

// Recursive Funcation
#include <stdio.h>

void printHW(int count);

int main()
{
    int count = 5;
    printHW(count);
    return 0;
}

// Recursive Funcation
void printHW(int count)
{
    if (count == 0)
    {
        return;
    }
    printf("hi shrishail\n");
    printHW(count - 1);
}

// Output
// hi shrishail
// hi shrishail
// hi shrishail
// hi shrishail
// hi shrishail

#include<stdio.h>

int sum(int n);

int main(){
    printf("sum is %d",sum(5));
}

int sum (int n){
    if (n==1)
    {
       return 1;
    }
    

    int sumn_1 = sum(n-1);
    // printf("%d",sumn_1);
    int sumN = sumn_1 +n;
    // printf("%d",sumN);
    return;
} 

