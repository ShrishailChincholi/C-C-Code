// Day 2 of Learning C programm
// Ternary Exmaple

#include<stdio.h>               
int main(){
    int age ;
    printf("Enter your age : \n");
    scanf("%d",&age);
    age>18?printf("Adult\n:"):printf("Not Adult\n");//Ternary Opreator
    return 0;
};
// OutPut 
// Enter your age : 
// 16
// Not Adult
 

// Looping Statments in C

// for loop mini Exmple
#include<stdio.h>
int main(){
    for (int i = 1; i < 4; i++)
    {
        printf("Hello World \n");
    }
    return 0;

}
// Output
// Hello World 
// Hello World 
// Hello World 
// Hello World 

// print 1 to 10 number in C
#include<stdio.h>
int main(){
    int num;
    for (int i = 0; i < 10; i++)
    {
       num = i+1;
       printf("%d\n",i);
    };
    
}


// Print A - Z
#include<stdio.h>
void main(){
    char num;

    for (char i = 'a'; i <= 'z'; i++)
    {
       printf( " %c ",i);
    };
    
}

// Using while loop 
#include<stdio.h>
int main(){
    char i='a';     //int i = 0
    while ( i <='i')    // i<=10
    {
        printf(" %c \n",i);  // printf("%c \n",i)
          i++;
    }
  return 0;
};

// OutPut
//  a 
//  b 
//  c
//  d
//  e


//using do while looop
#include<stdio.h>
int main(){
    char i = 'a';
    do
    {
        printf("%c \n",i);
        i++;
    } while (i<='f');
  return 0;
};



// wcp Take i/p user when stop user enter odd number
#include<stdio.h>
int main(){
    int n;
    do
    {
        printf("Enter a number : ");
        scanf("%d",&n);
        if (n %2 != 0)
        {
            break;
        }
        
    } while (1);
    printf("You Enter a Odd number ");
  return 0;
}

// Output
// Enter a number : 7
// You Enter a Odd number 

// Continue Control Statment

#include<stdio.h>
int main(){
    for (int i = 1; i <=5; i++)
    {
        if (i == 3)
        {
            continue;
        }
        printf("%d \n",i);        
    }
  return 0;
}

// Output
// 1 
// 2 
// 4 
// 5

// WCP multiplication table of n number in reverse order
#include<stdio.h>
int main(){
    int n,  multi;
    printf("Enter a number : ");
    scanf("%d",&n);
    for (int i = 10; i >=1; i--)
    {
       multi = n*i;
       printf("%d X %d = %d \n",n,i,multi) ;
    }
return 0;
}

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