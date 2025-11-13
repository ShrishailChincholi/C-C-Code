// // Allocate memory to store 1st 5 odd numbers, then reallocate it to store first 6 even number.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *)calloc(5, sizeof(int));
    ptr[0] = 1;
    ptr[1] = 3;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 9;

    printf("calloc\n");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d \n", ptr[i]);
    }

    printf("realloc\n");
    ptr = realloc(ptr, 6);
    ptr[0] = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 8;
    ptr[4] = 10;
    ptr[5] = 12;

    for (int i = 0; i < 6; i++)
    {
        printf("  %d \n", ptr[i]);
    }

}

// output
// calloc
// 1
// 3
// 5
// 7
// 9
// realloc
// 2
// 4
// 6
// 8
// 10
// 12

#include <stdio.h>
int main()
{
    int car;
    int time;
    int signal;
    printf("enter a car speed range and time and single 0 = red  1= green ");
    scanf("%d %d %d", &car, &time, &signal);
    int state;
    if (signal == 1 && car <= 5)
    {
        state = 1;
    }
    else if (signal == 1 && car >= 5)
    {
        state = 2;
    }
    else if (signal == 0 && time < 10 && car <= 5)
    {
        state = 3;
    }
    else if (signal == 0 && time >= 10)
    {
        state = 4;
    }
    else if (signal == 0 && time < 10 && car >= 5)
    {
        state = 5;
    }else if(signal != 0 && signal != 1){
        state = 6;
    }
    switch (state)
    {
    case 1:
        printf("Go fast ");
        break;
    case 2:
        printf("Move slowly");
        break;
    case 3:
        printf("wati");
        break;
    case 4:
        printf("Ready ");
        break;
    case 5:
        printf("move fast sigal is red");
        break;
    case 6:
        printf("singal error ");
        break;

    default:
        break;
    }
}

// // Output
// // enter a car speed range and time and single 0 = red  1= green 7 5 0
////move fast sigal is red