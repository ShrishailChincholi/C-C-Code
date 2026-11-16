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




// LeetCode #115 — Distinct Subsequences

#include <stdio.h>
#include <string.h>

unsigned long long numDistinct(char *s, char *t) {
    int m = strlen(s), n = strlen(t);
    unsigned long long dp[n + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < m; i++)
        for (int j = n; j > 0; j--)
            if (s[i] == t[j - 1])
                dp[j] += dp[j - 1];

    return dp[n];
}

int main(void) {
    printf("%llu\n", numDistinct("rabbbit", "rabbit"));
    printf("%llu\n", numDistinct("babgbag", "bag"));
    return 0;
}



// LeetCode #410 — Split Array Largest Sum

#include <stdio.h>

int splitArray(int *a, int n, int k) {
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > low) low = a[i];
        high += a[i];
    }

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long sum = 0;
        int parts = 1;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                parts++;
                sum = 0;
            }
            sum += a[i];
        }

        if (parts <= k)
            high = mid;
        else
            low = mid + 1;
    }

    return (int)low;
}

int main(void) {
    int a[] = {7, 2, 5, 10, 8};

    printf("%d\n", splitArray(a, 5, 2));
    return 0;
}



// LeetCode #174 — Dungeon Game


#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int calculateMinimumHP(int d[][3], int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1000000000;

    dp[m][n - 1] = dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - d[i][j]);

    return dp[0][0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int d[3][3] = {
        {-2, -3,  3},
        {-5, -10, 1},
        {10,  30, -5}
    };

    printf("%d\n", calculateMinimumHP(d, 3, 3));
    return 0;
}



// LeetCode #862 — Shortest Subarray with Sum at Least K

#include <stdio.h>
#include <stdlib.h>

int shortestSubarray(int *a, int n, int k) {
    long long p[n + 1];
    int q[n + 1], front = 0, back = 0;
    int ans = n + 1;

    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    for (int i = 0; i <= n; i++) {
        while (front < back && p[i] - p[q[front]] >= k) {
            int len = i - q[front++];
            if (len < ans) ans = len;
        }

        while (front < back && p[i] <= p[q[back - 1]])
            back--;

        q[back++] = i;
    }

    return ans == n + 1 ? -1 : ans;
}

int main(void) {
    int a[] = {2, -1, 2};

    printf("%d\n", shortestSubarray(a, 3, 3));
    return 0;
}




// LeetCode #864 — Shortest Path to Get All Keys



#include <stdio.h>
#include <string.h>

#define MAX 100
#define STATES 64

typedef struct {
    int r, c, mask, dist;
} Node;

int shortestPathAllKeys(char grid[][MAX], int m, int n) {
    Node q[MAX * MAX * STATES];
    static int vis[MAX][MAX][STATES];

    int sr = 0, sc = 0, keys = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '@')
                sr = i, sc = j;
            if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                keys |= 1 << (grid[i][j] - 'a');
        }

    int front = 0, rear = 0;
    q[rear++] = (Node){sr, sc, 0, 0};
    vis[sr][sc][0] = 1;

    while (front < rear) {
        Node cur = q[front++];

        if (cur.mask == keys)
            return cur.dist;

        for (int d = 0; d < 4; d++) {
            int r = cur.r + dr[d];
            int c = cur.c + dc[d];
            int mask = cur.mask;

            if (r < 0 || r >= m || c < 0 || c >= n)
                continue;

            char ch = grid[r][c];

            if (ch == '#') continue;

            if (ch >= 'A' && ch <= 'F' &&
                !(mask & (1 << (ch - 'A'))))
                continue;

            if (ch >= 'a' && ch <= 'f')
                mask |= 1 << (ch - 'a');

            if (!vis[r][c][mask]) {
                vis[r][c][mask] = 1;
                q[rear++] = (Node){r, c, mask, cur.dist + 1};
            }
        }
    }

    return -1;
}

int main(void) {
    char grid[3][MAX] = {
        "@.a..",
        "###.#",
        "b.A.B"
    };

    printf("%d\n", shortestPathAllKeys(grid, 3, 5));
    return 0;
}



// LeetCode #133 — Clone Graph


#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct Node {
    int val;
    int count;
    struct Node *neighbors[100];
} Node;

Node *visited[MAX];

Node *newNode(int val) {
    Node *p = calloc(1, sizeof(Node));
    p->val = val;
    return p;
}

Node *cloneGraph(Node *node) {
    if (!node) return NULL;

    if (visited[node->val])
        return visited[node->val];

    Node *copy = newNode(node->val);
    visited[node->val] = copy;

    for (int i = 0; i < node->count; i++)
        copy->neighbors[copy->count++] =
            cloneGraph(node->neighbors[i]);

    return copy;
}

void printGraph(Node *node, int seen[]) {
    if (!node || seen[node->val]) return;

    seen[node->val] = 1;
    printf("%d: ", node->val);

    for (int i = 0; i < node->count; i++)
        printf("%d ", node->neighbors[i]->val);

    printf("\n");

    for (int i = 0; i < node->count; i++)
        printGraph(node->neighbors[i], seen);
}

int main(void) {
    Node *a = newNode(1);
    Node *b = newNode(2);
    Node *c = newNode(3);
    Node *d = newNode(4);

    a->neighbors[a->count++] = b;
    a->neighbors[a->count++] = d;

    b->neighbors[b->count++] = a;
    b->neighbors[b->count++] = c;

    c->neighbors[c->count++] = b;
    c->neighbors[c->count++] = d;

    d->neighbors[d->count++] = a;
    d->neighbors[d->count++] = c;

    Node *copy = cloneGraph(a);

    int seen[MAX] = {0};
    printGraph(copy, seen);

    return 0;
}




// LeetCode #97 — Interleaving String


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isInterleave(char *s1, char *s2, char *s3) {
    int m = strlen(s1);
    int n = strlen(s2);

    if (m + n != strlen(s3))
        return false;

    bool dp[n + 1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;

    for (int j = 1; j <= n; j++)
        dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];

    for (int i = 1; i <= m; i++) {
        dp[0] = dp[0] && s1[i - 1] == s3[i - 1];

        for (int j = 1; j <= n; j++) {
            char c = s3[i + j - 1];

            dp[j] = (dp[j] && s1[i - 1] == c) ||
                    (dp[j - 1] && s2[j - 1] == c);
        }
    }

    return dp[n];
}

int main() {
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";

    if (isInterleave(s1, s2, s3))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}




// LeetCode #407 — Trapping Rain Water II



#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int height, row, col;
} Node;

Node heap[MAX * MAX * 4];
int size = 0;

void push(int h, int r, int c) {
    int i = ++size;

    while (i > 1 && heap[i / 2].height > h) {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = (Node){h, r, c};
}

Node pop() {
    Node result = heap[1];
    Node last = heap[size--];

    int i = 1, child;

    while (i * 2 <= size) {
        child = i * 2;

        if (child + 1 <= size &&
            heap[child + 1].height < heap[child].height)
            child++;

        if (last.height <= heap[child].height)
            break;

        heap[i] = heap[child];
        i = child;
    }

    heap[i] = last;
    return result;
}

int trapRainWater(int h[MAX][MAX], int m, int n) {
    int visited[MAX][MAX] = {0};
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int water = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                if (!visited[i][j]) {
                    push(h[i][j], i, j);
                    visited[i][j] = 1;
                }
            }
        }
    }

    while (size > 0) {
        Node cur = pop();

        for (int k = 0; k < 4; k++) {
            int r = cur.row + dr[k];
            int c = cur.col + dc[k];

            if (r < 0 || c < 0 || r >= m || c >= n ||
                visited[r][c])
                continue;

            visited[r][c] = 1;

            if (cur.height > h[r][c])
                water += cur.height - h[r][c];

            int nextHeight = h[r][c] > cur.height
                           ? h[r][c] : cur.height;

            push(nextHeight, r, c);
        }
    }

    return water;
}

int main() {
    int m = 3, n = 6;

    int heightMap[MAX][MAX] = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    printf("Trapped Water: %d\n",
           trapRainWater(heightMap, m, n));

    return 0;
}







#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
} Envelope;

int compare(const void *a, const void *b) {
    Envelope *x = (Envelope *)a;
    Envelope *y = (Envelope *)b;

    if (x->width != y->width)
        return x->width < y->width ? -1 : 1;

    return x->height > y->height ? -1 :
           x->height < y->height ? 1 : 0;
}

int maxEnvelopes(Envelope e[], int n) {
    if (n <= 0)
        return 0;

    qsort(e, n, sizeof(Envelope), compare);

    int *tails = malloc(n * sizeof(int));
    if (tails == NULL)
        return -1;

    int len = 0;

    for (int i = 0; i < n; i++) {
        int left = 0, right = len;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (tails[mid] < e[i].height)
                left = mid + 1;
            else
                right = mid;
        }

        tails[left] = e[i].height;

        if (left == len)
            len++;
    }

    free(tails);
    return len;
}

int main() {
    Envelope e[] = {
        {5, 4},
        {6, 4},
        {6, 7},
        {2, 3}
    };

    int n = sizeof(e) / sizeof(e[0]);

    printf("Maximum Nested Envelopes: %d\n",
           maxEnvelopes(e, n));

    return 0;
}








#include <stdio.h>

#define MAXN 105
#define MAXE 10005

typedef struct {
    int to, next;
} Edge;

typedef struct {
    int node, color;
} State;

Edge graph[2][MAXE];
int head[2][MAXN];
int edgeCount[2];
int dist[MAXN][2];

void addEdge(int color, int u, int v) {
    int id = edgeCount[color]++;

    graph[color][id].to = v;
    graph[color][id].next = head[color][u];
    head[color][u] = id;
}

void shortestAlternatingPaths(
    int n,
    int red[][2], int redCount,
    int blue[][2], int blueCount,
    int result[]
) {
    for (int i = 0; i < n; i++) {
        head[0][i] = -1;
        head[1][i] = -1;
        dist[i][0] = -1;
        dist[i][1] = -1;
    }

    edgeCount[0] = edgeCount[1] = 0;

    for (int i = 0; i < redCount; i++)
        addEdge(0, red[i][0], red[i][1]);

    for (int i = 0; i < blueCount; i++)
        addEdge(1, blue[i][0], blue[i][1]);

    State queue[2 * MAXN];
    int front = 0, rear = 0;

    queue[rear++] = (State){0, 0};
    queue[rear++] = (State){0, 1};

    dist[0][0] = 0;
    dist[0][1] = 0;

    while (front < rear) {
        State cur = queue[front++];

        int nextColor = 1 - cur.color;

        for (int e = head[nextColor][cur.node];
             e != -1;
             e = graph[nextColor][e].next) {

            int v = graph[nextColor][e].to;

            if (dist[v][nextColor] == -1) {
                dist[v][nextColor] =
                    dist[cur.node][cur.color] + 1;

                queue[rear++] = (State){v, nextColor};
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int a = dist[i][0];
        int b = dist[i][1];

        if (a == -1)
            result[i] = b;
        else if (b == -1)
            result[i] = a;
        else
            result[i] = a < b ? a : b;
    }
}

int main() {
    int n = 5;

    int red[][2] = {
        {0, 1},
        {2, 3}
    };

    int blue[][2] = {
        {1, 2},
        {3, 4}
    };

    int result[MAXN];

    shortestAlternatingPaths(
        n, red, 2, blue, 2, result
    );

    printf("Shortest Distances: ");

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}




//  LeetCode #1235 — Maximum Profit in Job Scheduling




#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start, end, profit;
} Job;

int compare(const void *a, const void *b) {
    Job *x = (Job *)a;
    Job *y = (Job *)b;

    return (x->end > y->end) - (x->end < y->end);
}

int findPrevious(Job jobs[], int index) {
    int left = 0, right = index - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (jobs[mid].end <= jobs[index].start) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}

int jobScheduling(int start[], int end[],
                  int profit[], int n) {

    Job jobs[MAX];

    for (int i = 0; i < n; i++) {
        jobs[i].start = start[i];
        jobs[i].end = end[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compare);

    int dp[MAX + 1] = {0};

    for (int i = 1; i <= n; i++) {
        int prev = findPrevious(jobs, i - 1);

        int take = jobs[i - 1].profit + dp[prev + 1];
        int skip = dp[i - 1];

        dp[i] = take > skip ? take : skip;
    }

    return dp[n];
}

int main() {
    int start[]  = {1, 2, 3, 3};
    int end[]    = {3, 4, 5, 6};
    int profit[] = {50, 10, 40, 70};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Maximum Profit: %d\n",
           jobScheduling(start, end, profit, n));

    return 0;
}
