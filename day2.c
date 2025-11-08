// Day 2 of Learning C programm
// Ternary Exmaple

// #include<stdio.h>               
// int main(){
//     int age ;
//     printf("Enter your age : \n");
//     scanf("%d",&age);
//     age>18?printf("Adult\n:"):printf("Not Adult\n");//Ternary Opreator
//     return 0;
// };
// OutPut 
// Enter your age : 
// 16
// Not Adult


// Switch Case Example
// #include<stdio.h>
// int main(){
//     int Id;
//     printf("Enter your Id 1-5:\n");
//     scanf("%d",&Id);
//     switch (Id)
//     {
//         case 1 : printf("Shrishail  ");
//         break;
//         case 2 : printf("Raju  ");
//         break;
//         case 3 : printf("Shanshank  ");
//         break;
//         case 4 : printf("Vishal  ");
//         break;
//         case 5 : printf("Vinod  ");
//         break;

//         default : printf("Invalid Id Plzz try agian.........");
//     }

//     return 0;
// }

// Output
// Enter your Id:
// 4
// Vishal  

// Example WCP to give Grades to a Student
// #include<stdio.h>
// int main(){
//     int Mark;
//     printf("Enter Your Marks 30 to 100 \n");
//     scanf("%d",&Mark);
//     if(Mark<=30){
//         printf("Your Grade is C \n");
//         printf("  Fail.... \n");
//     } else if (Mark>30 && Mark<=70)
//     {
//         printf("Your Grade is B \n");
//         printf(" Not Bad Give More your best \n");
//     }else if (Mark>70 && Mark<=90)
//     {
//        printf("Your Grade is A \n");
//        printf("Very Good:-)");
//     }else if (Mark>90 && Mark<=100)
//     {
//         printf("Your Grade is A+ \n");
//         printf("Excellent well Done ");
//     }
    
//     return 0;
// }

// OutPut
// Enter Your Marks 30 to 100 
// 30
// Your Grade is C 
//   Fail.... 

// WPP the Enter Charcter is upper case or lower case Letter
// #include<stdio.h>
// int main() {
//     char ch;
//     printf("Enter Letter :- \n ");
//     scanf("%c",&ch);
//     if(ch >= 'A' && ch<='Z'){
//         printf("%c is Upper Case Letter",ch);
//     }else if (ch >= 'a' && ch <= 'z' )
//     {
//          printf("%c is Lower Case Letter",ch);
//     } else{
//         printf("Not A English Letter");
//     }
    
//     return 0;
// }

// OutPut 
// Enter Letter :- 
//  M
// M is Upper Case Letter


// Looping Statments in C

// for loop mini Exmple
// #include<stdio.h>
// int main(){
//     for (int i = 1; i < 4; i++)
//     {
//         printf("Hello World \n");
//     }
    

// }
// Output
// Hello World 
// Hello World 
// Hello World 
// Hello World 

// print 1 to 10 number in C
// #include<stdio.h>
// int main(){
//     int num;
//     for (int i = 0; i < 10; i++)
//     {
//        num = i+1;
//        printf("%d\n",i);
//     };
    
// }


// Print A - Z
// #include<stdio.h>
// void main(){
//     char num;

//     for (char i = 'a'; i <= 'z'; i++)
//     {
//        printf( " %c ",i);
//     };
    
// }

// Using while loop 
// #include<stdio.h>
// int main(){
//     char i='a';     //int i = 0
//     while ( i <='i')    // i<=10
//     {
//         printf(" %c \n",i);  // printf("%c \n",i)
//           i++;
//     }
//   return 0;
// };

//OutPut
//  a 
//  b 
//  c
//  d
//  e


//using do while looop
// #include<stdio.h>
// int main(){
//     char i = 'a';
//     do
//     {
//         printf("%c \n",i);
//         i++;
//     } while (i<='f');
//   return 0;
// };

// Exmple print the sum of 1st natural number also print them in reverse

// #include<stdio.h>
// int main(){
//     int i;
//     printf("Enter a number :");
//     scanf("%d",&i);
//     int sum=0 ,n=1;
//     do
//     {
//       sum = sum+n;
//       n++;
//     } while (n<=i);
//     printf("%d \n",sum);
//   return 0;
// }
//Output 
// Enter a number :5
// 15 

// wcp Take i/p user when stop user enter odd number
// #include<stdio.h>
// int main(){
//     int n;
//     do
//     {
//         printf("Enter a number : ");
//         scanf("%d",&n);
//         if (n %2 != 0)
//         {
//             break;
//         }
        
//     } while (1);
//     printf("You Enter a Odd number ");
//   return 0;
// }

// Output
// Enter a number : 7
// You Enter a Odd number 

// Continue Control Statment

// #include<stdio.h>
// int main(){
//     for (int i = 1; i <=5; i++)
//     {
//         if (i == 3)
//         {
//             continue;
//         }
//         printf("%d \n",i);        
//     }
//   return 0;
// }

// Output
// 1 
// 2 
// 4 
// 5


// Exmple WCP Print the all odd number from 5 to 50
// #include<stdio.h>
// int main(){

//    for (int i = 5; i <=50; i++)
//    {
//     if (i %2 != 0)
//     {
//     printf("%d ",i);
//     }
    
//    }
//    return 0;
    
// }

// Output
// 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 

// WCP factoroial of number n
// #include<stdio.h>
// int main(){
//     int n,fact=1;
//     printf("Enter A number : ");
//     scanf("%d",&n);
//     for (int i = 1; i <=n; i++)
//     {
//        fact = fact*i;
//     }
//     printf("The Factorial is %d ",fact);
    
//     return 0;
// }
// Output
// Enter A number : 5
// The Factorial is 120 


// WCP multiplication table of n number in reverse order
// #include<stdio.h>
// int main(){
//     int n,  multi;
//     printf("Enter a number : ");
//     scanf("%d",&n);
//     for (int i = 10; i >=1; i--)
//     {
//        multi = n*i;
//        printf("%d X %d = %d \n",n,i,multi) ;
//     }
// return 0;
// }

// Output
// Enter a number : 2
// 2 X 10 = 20 
// 2 X 9 = 18 
// 2 X 8 = 16 
// 2 X 7 = 14 
// 2 X 6 = 12 
// 2 X 5 = 10 
// 2 X 4 = 8 
// 2 X 3 = 6
// 2 X 2 = 4
// 2 X 1 = 2