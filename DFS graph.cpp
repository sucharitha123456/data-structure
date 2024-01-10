#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int visited[MAX_VERTICES];
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;
void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = 0; j < MAX_VERTICES; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}
void addEdge(int start, int end) {
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
int main() {
    int vertices, edges, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    initializeGraph(vertices);
    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (int i = 0; i < edges; ++i) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFS(startVertex);
    return 0;
}

