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


// LeetCode #124 — Binary Tree Maximum Path Sum

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

int ans = -1000000000;

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(Node *root) {
    if (!root) return 0;

    int left = max(0, dfs(root->left));
    int right = max(0, dfs(root->right));

    ans = max(ans, root->val + left + right);

    return root->val + max(left, right);
}

Node *newNode(int x) {
    Node *p = malloc(sizeof(Node));
    p->val = x;
    p->left = p->right = NULL;
    return p;
}

int main() {
    Node *root = newNode(-10);

    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    dfs(root);

    printf("%d", ans);

    return 0;
}




// LeetCode #743 — Network Delay Time

#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int networkDelayTime(int times[][3], int m, int n, int k) {
    int g[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = INF;

    for (int i = 0; i < m; i++)
        g[times[i][0]][times[i][1]] = times[i][2];

    int dist[n + 1], used[n + 1] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[k] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;

        for (int i = 1; i <= n; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        if (u == -1 || dist[u] == INF)
            break;

        used[u] = 1;

        for (int v = 1; v <= n; v++)
            if (g[u][v] != INF &&
                dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return -1;

        if (dist[i] > ans)
            ans = dist[i];
    }

    return ans;
}

int main() {
    int times[][3] = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    printf("%d", networkDelayTime(times, 3, 4, 2));

    return 0;
}