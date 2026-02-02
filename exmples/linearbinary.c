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
                printf("Number was found at %d", n + 1);
                return 0;
            }
            else
            {
                printf("element was not found \n");
            }
        }
    }
    else if (choice == 2)
    {
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                printf("Number was found at %d", mid + 1);
                return 0;
            }
            else if (mid < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        printf("element was not found \n");
    }
    else
    {
        printf("Inavild Choice \n");
    }
    return 0;
}

// Enter a number of elemnetns5
// 2
// 4
// 5
// 7
// 9

// --Searching Menu----
// 1. Linear Search
// 2. Binary Search
//  Enter a choice
// 2

//  Enter a  number to find 7
// Number was found at 4