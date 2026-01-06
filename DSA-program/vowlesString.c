// Program to count vowels in string
#include<stdio.h>
int main(){
    char str[] = "hello iam shree";
    int count = 0;
    for (int  i = 0; str[i]!='\0'; i++)
    {
        if (str[i]=='a'|| str[i]=='e' || str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            count++;
        }
    }
    printf("%d",count);
    
}

// Output
// 6