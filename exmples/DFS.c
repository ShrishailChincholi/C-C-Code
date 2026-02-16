#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[10];
int visited[10] = {0};

void dfs(int v) {
    struct Node* temp;
    printf("%d ", v);
    visited[v] = 1;

    temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->data])
            dfs(temp->data);
        temp = temp->next;
    }
}

void addEdge(int src, int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = adj[src];
    adj[src] = newNode;
}

int main() {
    int edges, i, u, v, start;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < 10; i++)
        adj[i] = NULL;

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}