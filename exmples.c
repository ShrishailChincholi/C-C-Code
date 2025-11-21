// // // // Allocate memory to store 1st 5 odd numbers, then reallocate it to store first 6 even number.
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *ptr;
//     ptr = (int *)calloc(5, sizeof(int));
//     ptr[0] = 1;
//     ptr[1] = 3;
//     ptr[2] = 5;
//     ptr[3] = 7;
//     ptr[4] = 9;

//     printf("calloc\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf(" %d \n", ptr[i]);
//     }

//     printf("realloc\n");
//     ptr = realloc(ptr, 6);
//     ptr[0] = 2;
//     ptr[1] = 4;
//     ptr[2] = 6;
//     ptr[3] = 8;
//     ptr[4] = 10;
//     ptr[5] = 12;

//     for (int i = 0; i < 6; i++)
//     {
//         printf("  %d \n", ptr[i]);
//     }

// }

// // // output
// // // calloc
// // // 1
// // // 3
// // // 5
// // // 7
// // // 9
// // // realloc
// // // 2
// // // 4
// // // 6
// // // 8
// // // 10
// // // 12

// #include <stdio.h>
// int main()
// {
//     int car;
//     int time;
//     int signal;
//     printf("enter a car speed range and time and single 0 = red  1= green ");
//     scanf("%d %d %d", &car, &time, &signal);
//     int state;
//     if (signal == 1 && car <= 5)
//     {
//         state = 1;
//     }
//     else if (signal == 1 && car >= 5)
//     {
//         state = 2;
//     }
//     else if (signal == 0 && time < 10 && car <= 5)
//     {
//         state = 3;
//     }
//     else if (signal == 0 && time >= 10)
//     {
//         state = 4;
//     }
//     else if (signal == 0 && time < 10 && car >= 5)
//     {
//         state = 5;
//     }else if(signal != 0 && signal != 1){
//         state = 6;
//     }
//     switch (state)
//     {
//     case 1:
//         printf("Go fast ");
//         break;
//     case 2:
//         printf("Move slowly");
//         break;
//     case 3:
//         printf("wati");
//         break;
//     case 4:
//         printf("Ready ");
//         break;
//     case 5:
//         printf("move fast sigal is red");
//         break;
//     case 6:
//         printf("singal error ");
//         break;

//     default:
//         break;
//     }
// }

// // // // Output
// // // // enter a car speed range and time and single 0 = red  1= green 7 5 0
// // ////move fast sigal is red

// // // Write a function to find the greatest among three numbers

// #include <stdio.h>
// int maxno3(int a, int b, int c);

// int main()
// {
//     int a,b,c;
//     printf("Enter a three number ");
//     scanf("%d %d %d ",&a,&b,&c);
//      maxno3(a,b,c);
// }

// int maxno3(int a, int b, int c)
// {
//     if (a >= b && a >= c)
//     {
//         printf("A is gratest number %d", a);
//     }
//     else if (b >= a && b >= c)
//     {
//         printf("B is gratest number %d", b);
//     }else
//     {
//          printf("c is gratest number %d",c);
//     }

// }

// // // Output
// // // Enter a three number 6 8 6
// ////  B is gratest number 8

// // Simple Searching Techinque Examples
// #include <stdio.h>
// int main()
// {
//     int arr[5] = {10, 20, 30, 50, 70};
//     int key;
//     printf("Enter A Key to Find the Array Number : \n ");
//     scanf("%d", &key);
//     for (int i = 0; i <= 5; i++)
//     {
//         if (key == arr[i])
//         {
//             printf("You Enter Key Value  = %d and the find the Key = %d", arr[i], key);
//             return 0;
//         }
//     }
//     printf("Not Valid a number ");
// }

// // // OutPut
// // Enter A Key to Find the Array Number :
// //  50
// // You Enter Key Value  = 50 and the find the Key = 50

// // //Enter A Key to Find the Array Number :
// // // 60
// // //Not Valid a number

// // // Linear and Binary search
// #include <stdio.h>
// int main()
// {
//     int key, i, n, choice;
//     printf("Enter a n values :-");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter a number elements");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     };
//     printf("Enter A key value");
//     scanf("%d", &key);
//     printf("---Seraching Teachineques---\n");
//     printf("1,Choice Is for leanearsearch\n");
//     printf("2,Choice Is For Binnary Search\n");
//     printf("Enter Your Choices\n");
//     scanf("%d", &choice);
//     if (choice == 1)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (key == arr[i])
//             {
//                 printf("Element Found at mid postion %d\n",i+1);
//                 return 0;
//             }
//         }
//         printf("Invalid elements Number");
//     }
//     else if (choice == 2)
//     {
//         int low = 0, high = n - 1, mid;
//         while (low <= high)
//         {
//             mid = (low + high) / 2;
//             if (arr[mid]==key)
//             {
//                 printf("Element Found at mid postion %d\n",mid+1);
//                 return 0;
//             }else if (arr[mid]<key)
//             {
//                 low = mid+1;
//             }else
//             {
//                 high= mid-1;
//             }
            
//         }
//         printf("Invalid elements Number ");
//     }else
//     {
//         printf("Invalid chioce ");
//     }
//     return 0;
    
// }

// // // OutPut
// // Enter a n values :-5
// // Enter a number elements10
// // 20
// // 30
// // 40
// // 50
// // Enter A key value50
// // ---Seraching Teachineques---
// // 1,Choice Is for leanearsearch
// // 2,Choice Is For Binnary Search
// // Enter Your Choices
// // 2
// // Element Found at mid postion 5

// //Sum of elements in Array
#include<stdio.h>
int main(){
    int n,sum=0;
    printf("Enter A n number :--");
    scanf("%d",&n);
    int arr[n];
    printf("Enter  %d Elements :\n",n);
    for ( int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
    for (int  i = 0; i < n; i++)
    {
     sum = arr[i]+sum ; 
    }
    printf("Sum of array elemnts :- %d\n",sum);
    
}

// // Output
// Enter A n number :--5
// Enter  5 Elements :
// 2
// 3
// 4
// 5
// 6
// Sum of array elemnts :- 20