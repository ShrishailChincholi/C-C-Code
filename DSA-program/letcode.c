//  LeetCode 139 – Word Break

#include <stdio.h>
#include <string.h>

int search(char *s, int start, int end, char *dict[], int size)
{
    char temp[100];
    int len = end - start;

    strncpy(temp, s + start, len);
    temp[len] = '\0';

    for(int i = 0; i < size; i++)
        if(strcmp(temp, dict[i]) == 0)
            return 1;

    return 0;
}

int wordBreak(char *s, char *dict[], int size)
{
    int n = strlen(s);
    int dp[101] = {0};

    dp[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(dp[j] && search(s, j, i, dict, size))
            {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{
    char str[] = "leetcode";
    char *dict[] = {"leet", "code"};

    if(wordBreak(str, dict, 2))
        printf("True");
    else
        printf("False");

    return 0;
}


// LeetCode 128 – Longest Consecutive Sequence

#include <stdio.h>

void sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
}
