#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ", p);
}

int main() {
    int n = 30;
    sieveOfEratosthenes(n);
    return 0;
}

// output
// 2 3 5 7 11 13 17 19 23 29
