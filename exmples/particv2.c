//  Stack operations using linekd list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Createnode(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
};

struct Node *Push(struct Node *top, int value)
{
    struct Node *newnode = Createnode(value);
    newnode->next = top;
    return newnode;
}

struct Node *Pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty ");
        return NULL;
    }
    struct Node *temp = top;
    top = temp->next;
    free(temp);
    return top;
}









struct Node *Display(struct Node *top)
{
    if (top == NULL)
    {
        printf("stack is empty");
        return NULL;
    }
    while (top != NULL)
    {
        printf(" %d , ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main()
{
    struct Node *top = NULL;
    int choice, value;
    while (1)
    {
        printf("\n Menu\n");
        printf("\n 1. Push");
        printf("\n 2.Pop");
        printf("\n 3.Dispaly");
        printf("\n 4. Exite");

        printf("\n Enter Your u choice :\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to in add in the stack \n");
            scanf("%d", &value);
            top = Push(top, value);
            printf("The element added in stacke is : %d", value);
            break;
        case 2:
            top = Pop(top);
            printf("deketed %d",top);
            break;
        case 3:
            Display(top);
            break;
        case 4:
            printf("Exiteing the program ......");
            while (top !=NULL)
            {
                struct Node *temp = top;
                top = top->next;
                free(temp);
            }
            return 0;
            break;

        default:
            printf("Inavlid Choice :-( \n ");
            break;
        }
    }
    return 0;
}