#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];

int minDistance(int n) {
    int minDist = INT_MAX;
    int minIndex;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < minDist) {
            minDist = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int n, int source) {
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[source] = 0;
    for (int i = 0; i < n-1; i++) {
        int u = minDistance(n);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int n, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(n, source);
    printf("Shortest distances from vertex %d to all other vertices:\n", source);
    for (int i = 0; i < n; i++) {
        printf("%d -> %d: %d\n", source, i, distance[i]);
    }
    return 0;
}