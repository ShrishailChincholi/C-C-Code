#include <stdio.h>

int main()
{
    int n, choice, key;
    printf("Enter a number of elemnetns");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n--Searching Menu----\n");
    printf("1. Linear Search \n");
    printf("2. Binary Search \n");
    printf(" Enter a choice \n");
    scanf("%d", &choice);
    printf("\n Enter a  number to find ");
    scanf("%d", &key);
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                printf("Number was found at %d", n+ 1);
                return 0;
            }
            else
            {
                printf("element was not found \n");
            }
        }
    }