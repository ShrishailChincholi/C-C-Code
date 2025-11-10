// Array
// Example01
#include<stdio.h>
int main(){
    int price[]= {100,200,300};
    printf("Price 0 added gst %f\n",price[0]+(price[0]*0.18));
    printf("Price 1 added gst %f\n",price[1]+(price[1]*0.18));
    printf("Price 2 added gst %f\n",price[2]+(price[2]*0.18));
    return 0;
}

// Output
// Price 0 added gst 118.000000
// Price 1 added gst 236.000000
// Price 2 added gst 354.000000


 // Write a funcation to count the number of odd number in array

#include<stdio.h>
int count(int arr[],int n);
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    printf("%d",count(arr,10));
};

int count(int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2 != 0)
        {
            count++;
        }
        
    }
    return count;
}

// Output
// 5


