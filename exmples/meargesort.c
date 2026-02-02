#include <stdio.h>

void merage(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1,k = 0;
    int temp[50];

    while (arr[i] <= mid && arr[j] <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (arr[i] <= mid)
        temp[k++] = arr[i++];
    while (arr[j] <= right)
        temp[k++] = arr[j++];

    for (int i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void meragesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        meragesort(arr, left, mid);
        meragesort(arr, mid + 1, right);
        merage(arr, left, mid, right);
    }
}

int main()
{
    int arr[50], n;
    printf("Enter number of elements :\n");
    scanf("%d", &n);
    printf("Enter a number to elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    meragesort(arr, 0, n - 1);
    printf("Sorted Arrays : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    return 0;
}