// // calucluate to sum of  two vectors using struct
#include<stdio.h>

struct vectors
{
    int x;
    int y;
};

void calsum(struct vectors v1,struct vectors v2,struct vectors sum);

int main(){
    struct vectors v1 = {10,36};
    struct vectors v2 = {30,10};
    struct vectors sum = {0};
    calsum(v1,v2,sum);
}

void calsum(struct vectors v1,struct vectors v2,struct vectors sum){
    sum.x = v1.x+v2.x;
    sum.y = v1.y+v2.y;
    printf("sum of x vectors %d \n",sum.x);
    printf("sum of y vectors %d \n",sum.y);
}

// // Output
// //sum of x vectors 40 
// //sum of y vectors 46 