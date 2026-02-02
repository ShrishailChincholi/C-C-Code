#include<stdio.h>

void display(int a, int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    
}

int partitiom(int a, int low, int high){
    int pivot = a[low];
    int i = low+1;
    int j = high;
    int temp;
    while (a[i]<=pivot)
    {
        i++;
    }
    while (a[j]>pivot)
    {
        j++
    }
    if (i<j)
    {
       temp = a[i];
       a[i] =a[j];
       a[j]=temp
    }
    while (i<j)
        temp = a[low];
        a[low] = a[j];
        a[j]= temp
    return j;   
}