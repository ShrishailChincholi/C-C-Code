#include <stdio.h>

int main()
{
    int arr[5] = {25, 10, 30, 15, 5};
    int i, j, temp;

    printf("Original array:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}