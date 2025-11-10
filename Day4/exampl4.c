//WCP conevert celsius to fahrenheit
#include<stdio.h>

float far(float celsius);

int main(){
    float celsius = 35;
    printf("celsius of %f ->  fahrenteit is  = %f",celsius,far(celsius));
    return 0;
}

float far(float celsius){
float far =celsius*(9.0/5.0)+32;
return far;
}

// Output
// celsius of 35.000000 ->  fahrenteit is  = 95.000000

// WCP a funcation to calculate Parcentage of student from marks in scince , math,hindi
#include<stdio.h>

float result(float sci,float math,float hindi);

int main(){
    float sci=76;
    float math = 86;
    float hindi =38;

    printf("Parcentage of Student is %f",result(sci,math,hindi));
    return 0;
}
float result(float sci,float math,float hindi ){
    float res = ((sci+math+hindi)/300)*100;
    return res;
}

// Output
// Parcentage of Student is 66.666664


// // WCP a function to print HOT or COLD depending on the temperature user enter
#include<stdio.h>

float hotclod(float temp);

int main(){
    float T ;
    printf("Enter a Temprature \n");
    scanf("%f",&T);
    hotclod(T);
    return 0;
}

float hotclod(float temp){
    if (temp >= 30)
    {
        printf("Its Hot%f",temp);
    }else{
        printf("Its Cold %f",temp);
    }
   
}

//// Output 
// // Its Hot67.000000