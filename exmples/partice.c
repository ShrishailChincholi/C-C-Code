//  Linked List display count 
#include<stdio.h>
#include<stdlib.h>

struct  Node{
    int data;
    struct Node* next;
};

void displayNode(struct Node* head){
    while (head != NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

int countNode(struct Node* head){
    int count=0;
    while (head != NULL)
    {
        count++;
        head=head->next;
    }
    return count;
    
}

int main(){
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 2;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 4;
    second->next = NULL;
    head->next = second;

    struct Node* Third = (struct Node*)malloc(sizeof(struct Node));
    Third->data= 6;
    Third->next= NULL;
    second-> next= Third;

    displayNode(head);

    int NodeCount= countNode(head);
    printf("The total number in list is %d ",NodeCount);
    while (head !=NULL)
    {
       struct Node* temp = head;
       head = head->next;
       free(temp);
    }
    return 0;
    

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice, guess;

    // Generate random number (1–6)
    srand(time(0));
    dice = rand() % 6 + 1;

    printf("Dice Game\n");
    printf("Guess the dice number (1 to 6): ");
    scanf("%d", &guess);

    printf("Dice rolled: %d\n", dice);

    if(guess == dice) {
        printf("Correct guess\n");
    } else {
        printf("Wrong guess\n");
    }

    return 0;
}


// Output
// Dice Game
// Guess the dice number (1 to 6): 4
// Dice rolled: 2
// Wrong guess


//factorial 

#include <stdio.h>
int main() {
    int n, i, fact = 1;
    printf("Enter number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial = %d", fact);
    return 0;
}


//prime

#include <stdio.h>
int main() {
    int n, i, flag = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    for(i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            flag = 1;
            break;
        }
    }

    if(n == 1)
        printf("Not Prime");
    else if(flag == 0)
        printf("Prime");
    else
        printf("Not Prime");

    return 0;
}