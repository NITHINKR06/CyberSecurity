#include <stdio.h>
#define INF 9999
#define MAX 10

void bellmanFord(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int k = 0; k < V - 1; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Print result
    printf("Node\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, src;
    int graph[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (use 9999 for INF):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source node: ");
    scanf("%d", &src);

    bellmanFord(graph, V, src);
    
    return 0;
}

// gcc distance_vector_routing.c -o distance_vector_routing
// ./distance_vector_routing