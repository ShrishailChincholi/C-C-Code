// LeetCode #188 — Best Time to Buy and Sell Stock IV

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int k, int *prices, int n) {
    if (n == 0 || k == 0) return 0;

    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }

    int *buy = malloc((k + 1) * sizeof(int));
    int *sell = calloc(k + 1, sizeof(int));

    for (int j = 0; j <= k; j++)
        buy[j] = -1000000000;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (sell[j - 1] - prices[i] > buy[j])
                buy[j] = sell[j - 1] - prices[i];

            if (buy[j] + prices[i] > sell[j])
                sell[j] = buy[j] + prices[i];
        }
    }

    int ans = sell[k];

    free(buy);
    free(sell);

    return ans;
}

int main() {
    int prices[] = {3, 2, 6, 5, 0, 3};

    printf("%d", maxProfit(2, prices, 6));

    return 0;
}


// LeetCode #72 — Edit Distance


#include <stdio.h>
#include <string.h>

int min3(int a, int b, int c) {
    if (a < b && a < c) return a;
    return b < c ? b : c;
}

int minDistance(char *a, char *b) {
    int m = strlen(a), n = strlen(b);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min3(
                    dp[i - 1][j],     // delete
                    dp[i][j - 1],     // insert
                    dp[i - 1][j - 1]  // replace
                );
        }
    }

    return dp[m][n];
}

int main() {
    printf("%d", minDistance("horse", "ros"));
    return 0;
}