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