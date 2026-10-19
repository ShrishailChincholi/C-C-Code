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




// LeetCode #132 — Palindrome Partitioning II

#include <stdio.h>
#include <string.h>

int minCut(char *s) {
    int n = strlen(s);
    int pal[n][n], dp[n + 1];

    memset(pal, 0, sizeof(pal));

    for (int i = 0; i <= n; i++)
        dp[i] = i - 1;

    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (s[l] == s[r] &&
                (r - l < 2 || pal[l + 1][r - 1])) {
                pal[l][r] = 1;
                if (dp[l] + 1 < dp[r + 1])
                    dp[r + 1] = dp[l] + 1;
            }
        }
    }

    return dp[n];
}

int main(void) {
    printf("%d\n", minCut("aab"));
    printf("%d\n", minCut("a"));
    printf("%d\n", minCut("abccbc"));

    return 0;
}


// LeetCode #664 — Strange Printer

#include <stdio.h>
#include <string.h>

int strangePrinter(char *s) {
    int n = strlen(s), dp[n][n];

    if (!n) return 0;

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;

        for (int j = i + 1; j < n; j++) {
            dp[i][j] = dp[i + 1][j] + 1;

            for (int k = i + 1; k <= j; k++) {
                if (s[i] == s[k]) {
                    int cost = (k == i + 1 ? 0 : dp[i + 1][k - 1])
                             + dp[k][j];

                    if (cost < dp[i][j])
                        dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main(void) {
    printf("%d\n", strangePrinter("aaabbb"));
    printf("%d\n", strangePrinter("aba"));
    return 0;
}



// LeetCode #871 — Minimum Number of Refueling Stops



#include <stdio.h>

int minRefuelStops(int target, int fuel, int s[][2], int n) {
    int heap[n + 1], size = 0, stops = 0, i = 0;
    long long reach = fuel;

    while (reach < target) {
        while (i < n && s[i][0] <= reach) {
            int j = size++;
            heap[j] = s[i++][1];

            while (j > 0 && heap[(j - 1) / 2] < heap[j]) {
                int t = heap[j];
                heap[j] = heap[(j - 1) / 2];
                heap[(j - 1) / 2] = t;
                j = (j - 1) / 2;
            }
        }

        if (size == 0) return -1;

        reach += heap[0];
        heap[0] = heap[--size];

        int j = 0;
        while (1) {
            int l = 2 * j + 1, r = l + 1, largest = j;

            if (l < size && heap[l] > heap[largest]) largest = l;
            if (r < size && heap[r] > heap[largest]) largest = r;
            if (largest == j) break;

            int t = heap[j];
            heap[j] = heap[largest];
            heap[largest] = t;
            j = largest;
        }

        stops++;
    }

    return stops;
}

int main(void) {
    int stations[][2] = {
        {10, 60}, {20, 30}, {30, 30}, {60, 40}
    };

    printf("%d\n", minRefuelStops(100, 10, stations, 4));
    return 0;
}





// LeetCode #815 — Bus Routes

#include <stdio.h>
#include <string.h>

#define MAXS 1000
#define MAXR 500

int minBuses(int routes[][MAXS], int len[], int n,
             int source, int target) {
    if (source == target) return 0;

    int seenStop[MAXS * 2] = {0};
    int seenBus[MAXR] = {0};
    int q[MAXS * 2], front = 0, rear = 0, buses = 0;

    q[rear++] = source;
    seenStop[source] = 1;

    while (front < rear) {
        int end = rear;

        buses++;

        while (front < end) {
            int stop = q[front++];

            for (int i = 0; i < n; i++) {
                if (seenBus[i]) continue;

                int found = 0;
                for (int j = 0; j < len[i]; j++)
                    if (routes[i][j] == stop) {
                        found = 1;
                        break;
                    }

                if (!found) continue;
                seenBus[i] = 1;

                for (int j = 0; j < len[i]; j++) {
                    int next = routes[i][j];

                    if (next == target) return buses;

                    if (next < MAXS * 2 && !seenStop[next]) {
                        seenStop[next] = 1;
                        q[rear++] = next;
                    }
                }
            }
        }
    }

    return -1;
}

int main(void) {
    int routes[2][MAXS] = {
        {1, 2, 7},
        {3, 6, 7}
    };
    int len[] = {3, 3};

    printf("%d\n", minBuses(routes, len, 2, 1, 6));
    return 0;
}