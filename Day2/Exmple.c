// Switch Case Example
#include<stdio.h>
int main(){
    int Id;
    printf("Enter your Id 1-5:\n");
    scanf("%d",&Id);
    switch (Id)
    {
        case 1 : printf("Shrishail  ");
        break;
        case 2 : printf("Raju  ");
        break;
        case 3 : printf("Shanshank  ");
        break;
        case 4 : printf("Vishal  ");
        break;
        case 5 : printf("Vinod  ");
        break;

        default : printf("Invalid Id Plzz try agian.........");
    }

    return 0;
}

// Output
// Enter your Id:
// 4
// Vishal 

// Example WCP to give Grades to a Student
#include<stdio.h>
int main(){
    int Mark;
    printf("Enter Your Marks 30 to 100 \n");
    scanf("%d",&Mark);
    if(Mark<=30){
        printf("Your Grade is C \n");
        printf("  Fail.... \n");
    } else if (Mark>30 && Mark<=70)
    {
        printf("Your Grade is B \n");
        printf(" Not Bad Give More your best \n");
    }else if (Mark>70 && Mark<=90)
    {
       printf("Your Grade is A \n");
       printf("Very Good:-)");
    }else if (Mark>90 && Mark<=100)
    {
        printf("Your Grade is A+ \n");
        printf("Excellent well Done ");
    }
    
    return 0;
}

// OutPut
// Enter Your Marks 30 to 100 
// 30
// Your Grade is C 
//   Fail.... 

// WPP the Enter Charcter is upper case or lower case Letter
#include<stdio.h>
int main() {
    char ch;
    printf("Enter Letter :- \n ");
    scanf("%c",&ch);
    if(ch >= 'A' && ch<='Z'){
        printf("%c is Upper Case Letter",ch);
    }else if (ch >= 'a' && ch <= 'z' )
    {
         printf("%c is Lower Case Letter",ch);
    } else{
        printf("Not A English Letter");
    }
    
    return 0;
}

// OutPut 
// Enter Letter :- 
//  M
// M is Upper Case Letter

// Exmple print the sum of 1st natural number also print them in reverse
#include<stdio.h>
int main(){
    int i;
    printf("Enter a number :");
    scanf("%d",&i);
    int sum=0 ,n=1;
    do
    {
      sum = sum+n;
      n++;
    } while (n<=i);
    printf("%d \n",sum);
  return 0;
}
// Output 
// Enter a number :5
// 15 

// Exmple WCP Print the all odd number from 5 to 50
#include<stdio.h>
int main(){

   for (int i = 5; i <=50; i++)
   {
    if (i %2 != 0)
    {
    printf("%d ",i);
    }
    
   }
   return 0;
    
}

// Output
// 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 

// WCP factoroial of number n
#include<stdio.h>
int main(){
    int n,fact=1;
    printf("Enter A number : ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
       fact = fact*i;
    }
    printf("The Factorial is %d ",fact);
    
    return 0;
}
// Output
// Enter A number : 5
// The Factorial is 120 


// wcp Take i/p user when stop user enter odd number Using For Loop
#include<stdio.h>
int main(){
    int n;
   for (int i = 0; i <=1; i++)
   {
     printf("Enter a number : ");
        scanf("%d",&n);
        if (n %2 != 0)
        {
            break;
        }
   }
   printf("You Enter a Odd number ");
   
  return 0;
}

// Output
// Enter a number : 4
// Enter a number : 5
// You Enter a Odd number 