//  Pointer Mini Exmple
#include<stdio.h>
int main(){
    int age = 28;
    int *ptr = &age;
    int _age = *ptr;
    printf("%d \n ",_age);
    printf("%p \n ",ptr);  // pointers address printing
}
// OutPut
// 28

// Pointer to Pointer
// * when used for value geting and & used address needed
#include<stdio.h>
int main(){
    int age = 28;
    int *ptr = &age;
    int **pptr = &ptr; //Pointer to Pointer
    
    printf("%d \n ",**pptr);  
}

// OutPut 
// 22