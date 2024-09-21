#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a hashigo (ladder)
typedef struct {
    int length;
    int* vertices;
} Hashigo;

// Structure to represent an edge in the graph
typedef struct {
    int from;
    int to;
} Edge;

// Function to create a new hashigo
Hashigo* createHashigo(int length) {
    Hashigo* hashigo = (Hashigo*)malloc(sizeof(Hashigo));
    hashigo->length = length;
    hashigo->vertices = (int*)malloc((2 * length + 6) * sizeof(int));
    return hashigo;
}

// Function to add edges to a hashigo
void addEdgesToHashigo(Hashigo* hashigo) {
    int i;
    for (i = 0; i <= 2 * hashigo->length + 3; i++) {
        hashigo->vertices[i] = (hashigo->vertices[i - 1] + 2) % MOD;
    }
    for (i = 1; i <= hashigo->length + 1; i++) {
        hashigo->vertices[2 * i - 1] = (hashigo->vertices[2 * i - 2] + 1) % MOD;
    }
}

// Function to combine two hashigos
void combineHashigos(Hashigo* hashigo1, int p, Hashigo* hashigo2, int q) {
    int i;
    for (i = 0; i < 4; i++) {
        hashigo1->vertices[2 * p + 2 + i] = hashigo2->vertices[2 * q + 2 + i];
    }
}

// Function to count the number of valid colorings
int countColorings(Hashigo* hashigos[], int n, int k) {
    // Create an adjacency list to represent the graph
    int** adjList = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc((2 * hashigos[i]->length + 6) * sizeof(int));
        for (int j = 0; j < 2 * hashigos[i]->length + 6; j++) {
            adjList[i][j] = -1; // Initialize to -1 indicating no connection
        }
    }

    // Add edges to the adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * hashigos[i]->length + 3; j++) {
            adjList[i][hashigos[i]->vertices[j]] = hashigos[i]->vertices[j + 2];
            adjList[i][hashigos[i]->vertices[j + 2]] = hashigos[i]->vertices[j];
        }
        for (int j = 1; j <= hashigos[i]->length + 1; j++) {
            adjList[i][hashigos[i]->vertices[2 * j - 1]] = hashigos[i]->vertices[2 * j];
            adjList[i][hashigos[i]->vertices[2 * j]] = hashigos[i]->vertices[2 * j - 1];
        }
    }

    // Perform DFS to count the number of valid colorings
    int* visited = (int*)calloc(n * 30 + 6, sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * hashigos[i]->length + 6; j++) {
            if (!visited[hashigos[i]->vertices[j]]) {
                count = (count + dfs(adjList, visited, hashigos[i]->vertices[j], 0, k, 0)) % MOD;
            }
        }
    }

    free(visited);
    for (int i = 0; i < n; i++) {
        free(adjList[i]);
    }
    free(adjList);
    return count;
}

// Depth-first search function to count valid colorings
int dfs(int** adjList, int* visited, int vertex, int color, int k, int componentSize) {
    visited[vertex] = 1;
    int count = 1;
    for (int i = 0; i < 30 * 30 + 6; i++) {
        if (adjList[vertex / (2 * 30 + 6)][vertex % (2 * 30 + 6)] == i && !visited[i]) {
            if (color == 0) {
                count = (count + dfs(adjList, visited, i, 1, k, componentSize + 1)) % MOD;
            } else if (componentSize < k) {
                count = (count + dfs(adjList, visited, i, 0, k, componentSize + 1)) % MOD;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF && n != 0 && k != 0) {
        Hashigo* hashigos[30]; // Array to store hashigos
        int l[30]; // Array to store lengths of hashigos
        int f[30], p[30], t[30], q[30]; // Arrays to store combination information

        // Read the lengths of the hashigos
        for (int i = 0; i < n; i++) {
            scanf("%d", &l[i]);
            hashigos[i] = createHashigo(l[i]);
            addEdgesToHashigo(hashigos[i]);
        }

        // Read the combination information
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d %d %d", &f[i], &p[i], &t[i], &q[i]);
            combineHashigos(hashigos[f[i]], p[i], hashigos[t[i]], q[i]);
        }

        // Count the number of valid colorings
        int result = countColorings(hashigos, n, k);

        // Print the result
        printf("%d\n", result);

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(hashigos[i]->vertices);
            free(hashigos[i]);
        }
    }
    return 0;
}