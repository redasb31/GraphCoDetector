#include <stdio.h>
#include <stdlib.h>

// Function to check if a graph is connected using Depth First Search (DFS)
int isConnected(int** graph, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    int count = 0;

    // Start DFS from vertex 1
    visited[0] = 1;
    count++;
    int stack[n];
    int top = -1;
    stack[++top] = 0;

    while (top != -1) {
        int current = stack[top--];
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                count++;
                stack[++top] = i;
            }
        }
    }

    free(visited);
    // If all vertices are visited, the graph is connected
    return (count == n);
}

// Function to count the number of pairs of vertices with shortest distance 2
int countPairsDistance2(int** graph, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 1) {
                // Check if there is a path of length 2 between vertices i and j
                for (int k = 0; k < n; k++) {
                    if (graph[i][k] == 1 && graph[k][j] == 1 && i != k && j != k) {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // If there are more pairs of vertices with shortest distance 2 than possible
    if (k > n * (n - 1) / 2) {
        printf("-1\n");
        return 0;
    }

    // Create an adjacency matrix for the graph
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Construct a graph with the desired properties
    int m = n - 1; // Minimum number of edges required for a connected graph
    for (int i = 1; i < n; i++) {
        graph[i - 1][i] = 1;
        graph[i][i - 1] = 1;
    }

    // Add extra edges to create pairs of vertices with shortest distance 2
    int addedEdges = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 2; j < n; j++) {
            if (addedEdges == k) {
                break;
            }
            graph[i][j] = 1;
            graph[j][i] = 1;
            addedEdges++;
            m++;
        }
    }

    // Check if the constructed graph satisfies the conditions
    if (isConnected(graph, n) && countPairsDistance2(graph, n) == k) {
        // Print the graph
        printf("%d\n", m);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] == 1) {
                    printf("%d %d\n", i + 1, j + 1);
                }
            }
        }
    } else {
        printf("-1\n");
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}