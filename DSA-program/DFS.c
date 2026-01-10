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
     // Input the edges and update the adjacency matrix 
    printf("Enter the edges (startVertex endVertex):\n"); 
    for (int i = 0; i < edges; i++) { 
        int startVertex, endVertex; 
        scanf("%d %d", &startVertex, &endVertex); 
        adjMatrix[startVertex][endVertex] = 1; 
        adjMatrix[endVertex][startVertex] = 1; // For an undirected graph 
    } 
 
    // Initialize the visited array 
    int visited[MAX_VERTICES]; 
    for (int i = 0; i < MAX_VERTICES; i++) { 
        visited[i] = 0; 
    } 
 
    // Perform DFS traversal starting from vertex 0 
    printf("DFS Traversal starting from vertex 0:\n"); 
    dfs(adjMatrix, visited, vertices, 0); 
    printf("\n"); 
 
    // Free the allocated memory 
    for (int i = 0; i < MAX_VERTICES; i++) { 
        free(adjMatrix[i]); 
    } 
    free(adjMatrix); 
 
    return 0; 
} 
 
// Output
// Enter the number of vertices: 5
// Enter the number of edges: 4
// Enter the edges (startVertex endVertex):
// 0 1
// 0 2
// 1 3
// 1 4
// DFS Traversal starting from vertex 0:
// 0 1 3 4 2
