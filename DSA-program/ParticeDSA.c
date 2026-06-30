#include <stdio.h>

int trap(int* h, int n) {
    int l = 0, r = n - 1;
    int ml = 0, mr = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            h[l] >= ml ? (ml = h[l]) : (water += ml - h[l]);
            l++;
        } else {
            h[r] >= mr ? (mr = h[r]) : (water += mr - h[r]);
            r--;
        }
    }
    return water;
}

int main() {
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(h) / sizeof(h[0]);
    printf("Water trapped: %d\n", trap(h, n));
    return 0;
}





//   Next Greater Element using Stack

#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop()        { return stack[top--]; }
int isEmpty()    { return top == -1; }

void nextGreater(int* arr, int n) {
    int res[MAX];
    for (int i = 0; i < n; i++) res[i] = -1;

    for (int i = 0; i < n; i++) {
        while (!isEmpty() && arr[stack[top]] < arr[i]) {
            res[pop()] = arr[i];        
        }
        push(i);                      
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n); 
    return 0;
}

  // Output: 5 10 10 -1 -1






//  Detect Cycle in Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}



// Two Sum using Hashing (Optimized)
#include <stdio.h>

void twoSum(int arr[], int n, int target) {
    int hash[1000] = {0};

    for (int i = 0; i < n; i++) {
        int diff = target - arr[i];

        if (hash[diff]) {
            printf("Pair: %d %d", arr[i], diff);
            return;
        }
        hash[arr[i]] = 1;
    }
}



//  Kadane’s Algorithm (Max Subarray)
#include <stdio.h>

int maxSubArray(int arr[], int n) {
    int max = arr[0], curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = (curr + arr[i] > arr[i]) ? curr + arr[i] : arr[i];
        max = (max > curr) ? max : curr;
    }
    return max;
}



// Fast Exponentiation (Binary Power)
#include <stdio.h>

long long power(long long a, int b) {
    long long res = 1;

    while (b > 0) {
        if (b % 2)
            res *= a;

        a *= a;
        b /= 2;
    }
    return res;
}







// Find Missing Number using XOR
#include <stdio.h>

int missing(int arr[], int n) {
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++)
        xor1 ^= arr[i];

    for (int i = 1; i <= n + 1; i++)
        xor2 ^= i;

    return xor1 ^ xor2;
}



// Longest Substring Without Repeating
#include <stdio.h>

int longestUnique(char *s) {
    int map[256] = {0}, left = 0, max = 0;

    for (int right = 0; s[right]; right++) {
        map[s[right]]++;

        while (map[s[right]] > 1)
            map[s[left++]]--;

        int len = right - left + 1;
        if (len > max) max = len;
    }
    return max;
}




// Bit Manipulation – Find Single Number
#include <stdio.h>

int single(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}





// Fast Power (Binary Exponentiation)
#include <stdio.h>

long long power(long long a, int b) {
    long long res = 1;

    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}




// Majority Element
#include <stdio.h>

int majority(int arr[], int n) {
    int count = 0, candidate;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = arr[i];

        count += (arr[i] == candidate) ? 1 : -1;
    }
    return candidate;
}



// Trap Rain Water

#include <stdio.h>

int trap(int h[], int n) {
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            leftMax = (h[l] > leftMax) ? h[l] : leftMax;
            water += leftMax - h[l++];
        } else {
            rightMax = (h[r] > rightMax) ? h[r] : rightMax;
            water += rightMax - h[r--];
        }
    }
    return water;
}



// Generate All Permutations
#include <stdio.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int r) {
    if (l == r) {
        printf("%s\n", s);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}

int main() {
    char s[] = "ABC";
    permute(s, 0, 2);
}



// Subset Sum Problem

#include <stdio.h>

void subset(int arr[], int n, int i, int sum, int target) {
    if (sum == target) {
        printf("Found\n");
        return;
    }

    if (i == n || sum > target)
        return;

    subset(arr, n, i + 1, sum + arr[i], target);
    subset(arr, n, i + 1, sum, target);
}

int main() {
    int arr[] = {2,4,6,8};
    subset(arr, 4, 0, 0, 10);
}



// Generate All Permutations
#include <stdio.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int r) {
    if (l == r) {
        printf("%s\n", s);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}

int main() {
    char s[] = "ABC";
    permute(s, 0, 2);
}



// K-th Grammar Symbol
#include <stdio.h>

int kth(int n, int k) {
    if (n == 1) return 0;

    int mid = 1 << (n - 2);

    if (k <= mid)
        return kth(n - 1, k);

    return !kth(n - 1, k - mid);
}





// Word Break Problem
#include <stdio.h>
#include <string.h>

char *dict[] = {"i","like","sam","sung"};

int check(char *s) {
    if (!*s) return 1;

    for (int i = 0; i < 4; i++) {
        int len = strlen(dict[i]);

        if (!strncmp(s, dict[i], len))
            if (check(s + len))
                return 1;
    }
    return 0;
}

int main() {
    printf("%d", check("ilikesam"));
}



//  Two Pointer Technique

int l = 0, r = n - 1;

while (l < r) {
    int s = arr[l] + arr[r];

    if (s == target)
        break;

    s < target ? l++ : r--;
}



//  Tower of Hanoi

#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if (n == 0)
        return;

    hanoi(n - 1, a, c, b);

    printf("%c -> %c\n", a, c);

    hanoi(n - 1, b, a, c);
}

int main() {
    hanoi(3, 'A', 'B', 'C');
}



// Recursive Gray Code Generator
#include <stdio.h>

void gray(int n) {
    if (n == 0) {
        printf("0 ");
        return;
    }

    int size = 1 << n;

    for (int i = 0; i < size; i++)
        printf("%d ", i ^ (i >> 1));
}

int main() {
    gray(3);
}


// Ackermann Function
#include <stdio.h>

int ack(int m, int n) {
    if (m == 0)
        return n + 1;

    if (n == 0)
        return ack(m - 1, 1);

    return ack(m - 1, ack(m, n - 1));
}

int main() {
    printf("%d", ack(2,2));
}


// Recursive Matrix Path Count
#include <stdio.h>

int paths(int i, int j, int n, int m) {
    if (i == n - 1 && j == m - 1)
        return 1;

    if (i >= n || j >= m)
        return 0;

    return paths(i + 1, j, n, m)
         + paths(i, j + 1, n, m);
}

int main() {
    printf("%d", paths(0,0,3,3));
}


// K-th Symbol in Grammar
#include <stdio.h>

int kth(int n, int k) {
    if (n == 1)
        return 0;

    if (k % 2 == 0)
        return !kth(n - 1, k / 2);

    return kth(n - 1, (k + 1) / 2);
}

int main() {
    printf("%d", kth(4, 5));
}




// Minimum Operations to Make Equal

#include <stdio.h>

int solve(int a, int b) {
    if (a >= b)
        return a - b;

    if (b % 2 == 0)
        return 1 + solve(a, b / 2);

    return 1 + solve(a, b + 1);
}

int main() {
    printf("%d", solve(4,7));
}



// Recursive Game Winner
#include <stdio.h>

int win(int n) {
    if (n == 1)
        return 0;

    for (int i = 1; i < n; i++)
        if (!win(n - i))
            return 1;

    return 0;
}

int main() {
    printf(win(5) ? "Win" : "Lose");
}


// Sieve of Eratosthenes

#include <stdio.h>

int main() {
    int n = 50, prime[51];

    for (int i = 2; i <= n; i++)
        prime[i] = 1;

    for (int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;

    for (int i = 2; i <= n; i++)
        if (prime[i])
            printf("%d ", i);
}


// Digit DP Style Recursion
#include <stdio.h>

int sum(int n) {
    if (!n)
        return 0;

    return n % 10 + sum(n / 10);
}

int main() {
    printf("%d", sum(9876));
}


// Matrix Diagonal Sum Trick

#include <stdio.h>

int main() {
    int a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int sum = 0;

    for (int i = 0; i < 3; i++)
        sum += a[i][i] + a[i][2-i];

    printf("%d", sum - a[1][1]);
}




// GCD + Euclid Algorithm
#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    printf("%d", gcd(48,18));
}


// Sieve of Eratosthenes
#include <stdio.h>

int main() {
    int n = 50, prime[51];

    for (int i = 2; i <= n; i++)
        prime[i] = 1;

    for (int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;

    for (int i = 2; i <= n; i++)
        if (prime[i])
            printf("%d ", i);
}



// Inversion Count
#include <stdio.h>

int bit[100];

void update(int i) {
    while (i < 100) {
        bit[i]++;
        i += i & -i;
    }
}

int query(int i) {
    int s = 0;

    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }

    return s;
}

int main() {
    int a[] = {3,1,2};
    int inv = 0;

    for (int i = 2; i >= 0; i--) {
        inv += query(a[i] - 1);
        update(a[i]);
    }

    printf("%d", inv);
}


#include <stdio.h>

int bit[100], n = 5;

void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & -i;
    }
}

int query(int i) {
    int sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }

    return sum;
}

int main() {
    int a[] = {0,1,2,3,4,5};

    for (int i = 1; i <= n; i++)
        update(i, a[i]);

    printf("%d", query(3)); 
}



#include <stdio.h>

int duplicate(int a[]) {
    int slow = a[0], fast = a[0];

    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);

    return slow;
}



#include <stdio.h>

int xorN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

#include <stdio.h>

int duplicate(int a[]) {
    int slow = a[0], fast = a[0];

    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);

    return slow;
}




// KMP Algorithm in C

#include <stdio.h>
#include <string.h>

void lps(char p[], int m, int l[]) {
    int len = 0, i = 1;

    l[0] = 0;

    while (i < m) {
        if (p[i] == p[len])
            l[i++] = ++len;

        else if (len)
            len = l[len - 1];

        else
            l[i++] = 0;
    }
}


void kmp(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);

    int l[m];
    lps(p, m, l);

    int i = 0, j = 0;

    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Found at %d\n", i - j);
            j = l[j - 1];
        }

        else if (i < n && t[i] != p[j]) {
            if (j)
                j = l[j - 1];
            else
                i++;
        }
    }
}


int main() {
    char t[] = "ABABDABACDABABCABAB";
    char p[] = "ABABCABAB";

    kmp(t,p);
}


#include <stdio.h>
#include <stdlib.h>

struct Trie {
    struct Trie *child[26];
    int end;
};

struct Trie* node() {
    struct Trie *t = calloc(1,sizeof(struct Trie));
    return t;
}

void insert(struct Trie *root, char *s) {
    while (*s) {
        int i = *s - 'a';

        if (!root->child[i])
            root->child[i] = node();

        root = root->child[i];
        s++;
    }

    root->end = 1;
}

int search(struct Trie *root, char *s) {
    while (*s) {
        int i = *s - 'a';

        if (!root->child[i])
            return 0;

        root = root->child[i];
        s++;
    }

    return root->end;
}


int main() {
    struct Trie *root = node();

    insert(root,"cat");

    printf("%d", search(root,"cat"));
}




#include <stdio.h>

struct Power {
    long long (*calc)(long long,int);
};


long long solve(long long a, int b) {
    long long r = 1;

    while (b) {
        if (b & 1)
            r *= a;

        a *= a;
        b >>= 1;
    }

    return r;
}

int main() {
    struct Power p = {solve};

    printf("%lld", p.calc(2,10));
}



#include <stdio.h>

struct Kadane {
    int (*max)(int[],int);
};

int solve(int a[], int n) {
    int sum = a[0], mx = a[0];

    for (int i = 1; i < n; i++) {
        sum = (a[i] > sum + a[i]) ? a[i] : sum + a[i];

        if (sum > mx)
            mx = sum;
    }

    return mx;
}

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};

    struct Kadane k = {solve};

    printf("%d", k.max(a,9));
}


#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*ptr)(int, int) = add;

    printf("%d", ptr(10, 20));
}



#include <stdio.h>

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }

int main() {
    int choice = 1;

    int (*fun[])(int,int) = {add, sub};

    printf("%d", fun[choice](10,5));
}




#include <stdio.h>

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }

int main() {
    int choice = 1;

    int (*fun[])(int,int) = {add, sub};

    printf("%d", fun[choice](10,5));
}



#include <stdio.h>

typedef struct {
    int (*square)(int);
} Math;

int sq(int x) {
    return x*x;
}

int main() {
    Math m = {sq};

    printf("%d", m.square(5));
}





#include <stdio.h>

unsigned int reverseBits(unsigned int n) {
    unsigned int rev = 0;

    while (n) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }

    return rev;
}

int main() {
    printf("%u", reverseBits(13));
}






#include <stdio.h>

int main() {
    int a[] = {2,2,2,5,5,5,9};
    int ones = 0, twos = 0;

    for(int i=0;i<7;i++) {
        ones = (ones ^ a[i]) & ~twos;
        twos = (twos ^ a[i]) & ~ones;
    }

    printf("%d", ones);
}


#include <stdio.h>

int f(int x) {
    return (x * x + 1) % 255;
}

int main() {
    int slow = 2, fast = 2;

    do {
        slow = f(slow);
        fast = f(f(fast));
    } while (slow != fast);

    printf("Cycle Found");
}



#include <stdio.h>

long long moves(int n){
    return (1LL<<n)-1;
}

int main(){
    printf("%lld", moves(20));
}


#include <stdio.h>

int main() {
    int n = 156;

    while(n & (n-1))
        n &= (n-1);

    printf("%d", n);
}



#include <stdio.h>

int dp[1000];

int fib(int n) {
    if(n <= 1)
        return n;

    if(dp[n])
        return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}

int main() {
    printf("%d", fib(40));
}



#include <stdio.h>
#include <string.h>

int main() {
    char p[]="ababaca";
    int lps[100]={0};

    for(int i=1,len=0;p[i];){
        if(p[i]==p[len])
            lps[i++]=++len;
        else if(len)
            len=lps[len-1];
        else
            i++;
    }

    for(int i=0;i<7;i++)
        printf("%d ",lps[i]);
}


#include <stdio.h>

int partition(int a[], int l, int r) {
    int p = a[r], i = l;

    for(int j=l;j<r;j++)
        if(a[j] <= p) {
            int t=a[i]; a[i]=a[j]; a[j]=t;
            i++;
        }

    int t=a[i]; a[i]=a[r]; a[r]=t;

    return i;
}

int kth(int a[], int l, int r, int k) {
    int p = partition(a,l,r);

    if(p == k) return a[p];

    return p > k ?
           kth(a,l,p-1,k) :
           kth(a,p+1,r,k);
}

int main() {
    int a[]={7,4,6,3,9,1};

    printf("%d", kth(a,0,5,2));
}


#include <stdio.h>

int main() {
    int n=3;

    for(int mask=0; mask<(1<<n); mask++) {
        for(int i=0;i<n;i++)
            if(mask&(1<<i))
                printf("%d ",i);

        printf("\n");
    }
}


#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    printf("%d", josephus(7, 3) + 1);
}



#include <stdio.h>

int dp[100];

int fib(int n) {
    if (n < 2)
        return n;

    if (dp[n])
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    printf("%d", fib(40));
}