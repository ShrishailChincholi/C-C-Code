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
int main() { 
    int vertices, edges; 
 
    // Get the number of vertices and edges from the user 
    printf("Enter the number of vertices: "); 
    scanf("%d", &vertices); 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
 
    // Allocate memory for the adjacency matrix 
    int **adjMatrix = (int **)malloc(MAX_VERTICES * sizeof(int *)); 
    for (int i = 0; i < MAX_VERTICES; i++) { 
        adjMatrix[i] = (int *)malloc(MAX_VERTICES * sizeof(int)); 
    } 
 
    // Initialize the adjacency matrix 
    for (int i = 0; i < MAX_VERTICES; i++) { 
        for (int j = 0; j < MAX_VERTICES; j++) { 
            adjMatrix[i][j] = 0; 
        } 
    }