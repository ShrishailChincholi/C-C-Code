Write a program to implement DFS graph traversal. 
 
#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_VERTICES 100 
 
// Function to perform Depth-First Search traversal 
void dfs(int **adjMatrix, int *visited, int vertices, int currentVertex) { 
    printf("%d ", currentVertex); 
    visited[currentVertex] = 1; 
 
    for (int i = 0; i < vertices; i++) { 
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) { 
            dfs(adjMatrix, visited, vertices, i); 
        } 
    } 
}