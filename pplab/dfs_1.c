#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void initializeGraph() {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void dfs(int startVertex) {
    visited[startVertex] = 1;

    #pragma omp parallel shared(visited, startVertex)
    {
        #pragma omp single
        {
            dfsUtil(startVertex);
        }
    }
}

void dfsUtil(int vertex) {
    int i;
    #pragma omp task shared(vertex)
    {
        for (i = 0; i < numVertices; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = 1;
                dfsUtil(i);
            }
        }
    }
}

int main() {
    int i, j, startVertex;
    double startTime, endTime;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initializeGraph();

    printf("Enter the edges (source destination, -1 -1 to stop):\n");
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;
        addEdge(src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    startTime = omp_get_wtime();

    dfs(startVertex);

    endTime = omp_get_wtime();

    printf("Visited vertices: ");
    for (i = 0; i < numVertices; i++) {
        if (visited[i])
            printf("%d ", i);
    }
    printf("\n");

    printf("Execution time: %f seconds\n", endTime - startTime);

    return 0;
}