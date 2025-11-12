// Dyanmic memory allocation
// Malloc
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    ptr =(int*) malloc(5*sizeof(int));

    ptr[0] =1;
    ptr[1] = 2;
    ptr[2] =6;
    for (int i = 0; i < 3; i++)
    {
       printf("%d ",ptr[i]);
    }

}

//
// 126

// calloc
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    ptr =(int*) calloc(5,sizeof(int));

    for (int i = 0; i < 3; i++)
    {
       printf("%d ",ptr[i]);
    }

}
// output
// 000

// free()
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr =(int*) calloc(5,sizeof(int));

    for (int i = 0; i < 3; i++)
    {
       printf("%d ",ptr[i]);
    }
    free(ptr);
    ptr =(int*) calloc(1,sizeof(int));

    for (int i = 0; i < 1; i++)
    {
       printf("%d ",ptr[i]);
    }

}

// // output
//  // 0 0 0 0

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    ptr = (int *)calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    printf("realloc part \n");
    ptr = realloc(ptr, 9);

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", ptr[i]);
    }
}

//// output
// 0 0 0 0 0 
// realloc part 
// 0 0 0 0 0 0 0 0 0 