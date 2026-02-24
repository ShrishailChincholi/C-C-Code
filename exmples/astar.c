#include <stdio.h>
#include <string.h>

#define MAX 10
#define INF 9999


struct Node {
    char name;
    int f;   
};


struct Edge {
    char to;
    int weight;
};


struct Node pq[MAX];
int pqSize = 0;


void push(char name, int f) {
    pq[pqSize].name = name;
    pq[pqSize].f = f;
    pqSize++;
}

char pop() {
    int minIndex = 0;
    for (int i = 1; i < pqSize; i++) {
        if (pq[i].f < pq[minIndex].f)
            minIndex = i;
    }
    char node = pq[minIndex].name;
    pq[minIndex] = pq[pqSize - 1];
    pqSize--;
    return node;
}


int idx(char c) {
    return c - 'A';
}


int main() {
    // Graph
    struct Edge graph[4][2] = {
        {{'B',1}, {'C',4}},   // A
        {{'D',3}},            // B
        {{'D',1}},            // C
        {}                    // D
    };
    int graphSize[4] = {2,1,1,0};

    
    int h[4] = {7,6,2,0};

    int gCost[4];
    char parent[4];
    int visited[4] = {0};

    for (int i = 0; i < 4; i++)
        gCost[i] = INF;

    char start = 'A', goal = 'D';

    gCost[idx(start)] = 0;
    push(start, h[idx(start)]);

    while (pqSize > 0) {
        char curr = pop();

        if (curr == goal)
            break;

        visited[idx(curr)] = 1;

        for (int i = 0; i < graphSize[idx(curr)]; i++) {
            char neigh = graph[idx(curr)][i].to;
            int w = graph[idx(curr)][i].weight;

            int newCost = gCost[idx(curr)] + w;

            if (newCost < gCost[idx(neigh)]) {
                gCost[idx(neigh)] = newCost;
                parent[idx(neigh)] = curr;
                push(neigh, newCost + h[idx(neigh)]);
            }
        }
    }

    
    printf("Path: ");
    char path[10];
    int p = 0;
    char curr = goal;

    while (curr != start) {
        path[p++] = curr;
        curr = parent[idx(curr)];
    }
    path[p++] = start;

    for (int i = p - 1; i >= 0; i--)
        printf("%c ", path[i]);

    return 0;
}