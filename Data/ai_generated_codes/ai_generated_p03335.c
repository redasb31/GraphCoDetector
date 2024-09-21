#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000
#define MAX_M 2000

// Structure to represent an edge in the tree
typedef struct Edge {
    int u, v;
} Edge;

// Structure to represent a walk
typedef struct Walk {
    int u, v;
    int direction; // 1: u to v, -1: v to u
} Walk;

// Adjacency list representation of the tree
Edge edges[MAX_N - 1];
int adj[MAX_N][MAX_N];

// Array to store the direction of each walk
int walk_directions[MAX_M];

// Function to add an edge to the adjacency list
void add_edge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to find the shortest path from u to v using Depth First Search
int dfs(int u, int v, int visited[], int path[], int path_index) {
    visited[u] = 1;
    path[path_index++] = u;

    if (u == v) {
        return 1; // Path found
    }

    for (int i = 1; i <= MAX_N; i++) {
        if (adj[u][i] && !visited[i]) {
            if (dfs(i, v, visited, path, path_index)) {
                return 1; // Path found
            }
        }
    }

    return 0; // Path not found
}

// Function to find the shortest path between two vertices
void find_path(int u, int v, int path[]) {
    int visited[MAX_N] = {0};
    int path_index = 0;

    dfs(u, v, visited, path, path_index);
}

// Function to calculate the happiness gained from a walk
int calculate_happiness(Walk walk, int walk_index) {
    int happiness = 0;
    int path[MAX_N];
    int path_index = 0;

    find_path(walk.u, walk.v, path);

    for (int i = 0; i < path_index - 1; i++) {
        // Check if the edge has been traversed before
        int u = path[i];
        int v = path[i + 1];

        int traversed = 0;

        for (int j = 0; j < walk_index; j++) {
            if (walk_directions[j] == 1 && (edges[j].u == u && edges[j].v == v || edges[j].u == v && edges[j].v == u)) {
                traversed++;
            } else if (walk_directions[j] == -1 && (edges[j].u == u && edges[j].v == v || edges[j].u == v && edges[j].v == u)) {
                traversed--;
            }
        }

        if (traversed == 0 || traversed == -1) {
            happiness++;
        }
    }

    return happiness;
}

// Function to find the maximum total happiness and the directions of the walks
void find_max_happiness(int N, int M, Walk walks[]) {
    int total_happiness = 0;

    // Initialize the direction of each walk to be from u to v
    for (int i = 0; i < M; i++) {
        walk_directions[i] = 1;
    }

    // Try all possible directions for each walk
    for (int i = 0; i < M; i++) {
        int happiness_1 = calculate_happiness(walks[i], i);
        int happiness_2 = calculate_happiness(walks[i], i);

        if (happiness_1 > happiness_2) {
            walk_directions[i] = 1;
            total_happiness += happiness_1;
        } else {
            walk_directions[i] = -1;
            total_happiness += happiness_2;
        }
    }

    // Print the results
    printf("%d\n", total_happiness);

    for (int i = 0; i < M; i++) {
        if (walk_directions[i] == 1) {
            printf("%d %d\n", walks[i].u, walks[i].v);
        } else {
            printf("%d %d\n", walks[i].v, walks[i].u);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the edges of the tree
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
        add_edge(edges[i].u, edges[i].v);
    }

    // Read the walks
    Walk walks[MAX_M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &walks[i].u, &walks[i].v);
    }

    // Find the maximum total happiness and the directions of the walks
    find_max_happiness(N, M, walks);

    return 0;
}