#include <stdio.h>
int main() {
 int num = 25;
    char name = 's';
    float pi = 3.28;
    printf("age is %d\n",num);
    printf("name is %c\n",name);
    printf("float is %f\n",pi);
}

#include <stdio.h>
int main() {
   char a[50];
   printf("enter u r name:=");
   scanf("%s",&a);
   printf("yor name is %s ",a);
    return 0;
    
}

// area of square
#include <stdio.h>
int main() {
int side;
    printf("Enter a number");
    scanf("%d",&side);
    int areaofsqure= side*side;
    printf("area of squres is %d");
}
    
// %%area of cirule

#include <stdio.h>
int main() {
 float side;
    printf("Enter a number");
    scanf("%f",&side);
    float radius= 3.14*side*side;
    printf("area of squres is %f",radius);
    return 0;
}
    
   

    // Area of Recatangle
#include <stdio.h>
int main(){
    int l,b,arofRect;
    printf("Enter a lenth of area: \n");
    scanf("%d",&l);
    printf("Enter a bridth of area b: \n ");
    scanf("%d",&b);
    arofRect = l*b;
    printf("area of recatangle is l*b : %d",arofRect);
   return 0;

}

// Cube of number
#include<stdio.h>
int main(){
    int a=10,b;
    b=a*a*a;
    printf("cube  value of a is %d",b);
    return 0;

}


// Instrucations and operators

#include<stdio.h>
int main(){
    int a = 4+9*10;     //right to left
    printf("%d",a);
    return 0;
}

#include<stdio.h>
// // associatevie presidenace
int main() {
    int a = 4*3/6*2;
    printf("%d",a);
    return 0;
}

// control Instructions,i)Sequance,ii)Decision,iii)loop,iv)case
// Realational opeartor
#include<stdio.h>
int main(){
    int a=3<9||3>9;
    int b= 5>=5;
    printf("%d \n",a);
    printf("%d \n",b);
    return 0;

}

//Eveen odd 
#include<stdio.h>
int main(){
    int a ;
    printf("Enter a number : \n");
    scanf("%d",&a);
    if(a%2==0){
        printf("Is a Eveen number %d =",a);
    } else{
        printf("Is a Odd number %d ",a);
    };
}
