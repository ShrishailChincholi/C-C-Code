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

int longest(int a[],int n)
{
    sort(a,n);

    int ans=1,c=1;

    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            continue;

        if(a[i]==a[i-1]+1)
            c++;
        else
            c=1;

        if(c>ans)
            ans=c;
    }

    return ans;
}

int main()
{
    int a[]={100,4,200,1,3,2};

    int n=sizeof(a)/sizeof(a[0]);

    printf("%d",longest(a,n));

    return 0;
}



// LeetCode 315 – Count of Smaller Numbers After Self (C)
#include <stdio.h>

typedef struct{
    int val, idx;
}Node;

void merge(Node a[], int l, int m, int r, int ans[])
{
    int i=l,j=m+1,k=0,right=0;
    Node temp[r-l+1];

    while(i<=m && j<=r)
    {
        if(a[j].val<a[i].val)
        {
            temp[k++]=a[j++];
            right++;
        }
        else
        {
            ans[a[i].idx]+=right;
            temp[k++]=a[i++];
        }
    }

    while(i<=m)
    {
        ans[a[i].idx]+=right;
        temp[k++]=a[i++];
    }

    while(j<=r)
        temp[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=temp[k];
}


void mergeSort(Node a[], int l, int r, int ans[])
{
    if(l>=r) return;

    int m=(l+r)/2;

    mergeSort(a,l,m,ans);
    mergeSort(a,m+1,r,ans);

    merge(a,l,m,r,ans);
}

int main()
{
    int nums[]={5,2,6,1};
    int n=4;

    Node a[4];
    int ans[4]={0};

    for(int i=0;i<n;i++)
    {
        a[i].val=nums[i];
        a[i].idx=i;
    }

    mergeSort(a,0,n-1,ans);

    printf("Output: ");

    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);

    return 0;
}


// LeetCode 315 – Count of Smaller Numbers After Self (C)
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int index;
}Node;

void merge(Node a[], int l, int m, int r, int ans[])
{
    int i=l,j=m+1,k=0,count=0;

    Node temp[r-l+1];

    while(i<=m && j<=r)
    {
        if(a[j].val < a[i].val)
        {
            temp[k++]=a[j++];
            count++;
        }
        else
        {
            ans[a[i].index]+=count;
            temp[k++]=a[i++];
        }
    }

    while(i<=m)
    {
        ans[a[i].index]+=count;
        temp[k++]=a[i++];
    }

    while(j<=r)
        temp[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=temp[k];
}


void mergeSort(Node a[],int l,int r,int ans[])
{
    if(l>=r) return;

    int mid=(l+r)/2;

    mergeSort(a,l,mid,ans);
    mergeSort(a,mid+1,r,ans);

    merge(a,l,mid,r,ans);
}

int main()
{
    int nums[]={5,2,6,1};
    int n=sizeof(nums)/sizeof(nums[0]);

    Node a[n];
    int ans[n];

    for(int i=0;i<n;i++)
    {
        a[i].val=nums[i];
        a[i].index=i;
        ans[i]=0;
    }

    mergeSort(a,0,n-1,ans);

    printf("Output: ");

    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int hasCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));
    struct Node *d = malloc(sizeof(struct Node));

    a->data=1;
    b->data=2;
    c->data=3;
    d->data=4;

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;      

    if(hasCycle(a))
        printf("Cycle Found");
    else
        printf("No Cycle");

    return 0;
}


// LeetCode 3 – Longest Substring Without Repeating Characters
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char s[])
{
    int last[256];
    int start = 0, max = 0;

    for(int i=0;i<256;i++)
        last[i] = -1;

    for(int i=0;i<strlen(s);i++)
    {
        if(last[s[i]] >= start)
            start = last[s[i]] + 1;

        last[s[i]] = i;

        if(i-start+1 > max)
            max = i-start+1;
    }

    return max;
}

int main()
{
    char s[]="abcabcbb";

    printf("%d",lengthOfLongestSubstring(s));

    return 0;
}

//Remove Duplicates from Sorted Array

#include <stdio.h>

int main()
{
    int a[]={1,1,2,2,3,4,4};
    int n=7,k=1;

    for(int i=1;i<n;i++)
        if(a[i]!=a[i-1])
            a[k++]=a[i];

    for(int i=0;i<k;i++)
        printf("%d ",a[i]);
}

//jump game

#include <stdio.h>

int main()
{
    int a[]={2,3,1,1,4};
    int reach=0,n=5;

    for(int i=0;i<n;i++)
    {
        if(i>reach)
        {
            printf("False");
            return 0;
        }

        if(i+a[i]>reach)
            reach=i+a[i];
    }

    printf("True");
}
