#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

typedef struct Node {
    int deg;
    Edge *head;
} Node;

Node *nodes;
int N;

// Function to add an edge to the adjacency list
void addEdge(int u, int v) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->next = nodes[u].head;
    nodes[u].head = newEdge;
    nodes[u].deg++;

    newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = u;
    newEdge->next = nodes[v].head;
    nodes[v].head = newEdge;
    nodes[v].deg++;
}

// Function to perform Depth-First Search (DFS)
int dfs(int u, int p, int *visited) {
    visited[u] = 1;
    int count = 0;

    Edge *curr = nodes[u].head;
    while (curr != NULL) {
        if (curr->to != p && !visited[curr->to]) {
            count += dfs(curr->to, u, visited);
        }
        curr = curr->next;
    }

    // If the current node is a leaf node, return 1
    if (nodes[u].deg == 1) {
        count = 1;
    }

    return count;
}

// Function to calculate the number of ways to divide the vertices into pairs
int countPairs(int root) {
    int *visited = (int *)calloc(N + 1, sizeof(int));
    int count = dfs(root, -1, visited);

    // If the count of leaf nodes is not N / 2, there are no valid pairings
    if (count != N / 2) {
        return 0;
    }

    // Calculate the number of ways to divide the vertices into pairs
    long long ways = 1;
    for (int i = 2; i <= count; i++) {
        ways = (ways * i) % MOD;
    }

    free(visited);
    return (int)ways;
}

int main() {
    scanf("%d", &N);

    // Allocate memory for the adjacency list
    nodes = (Node *)malloc((N + 1) * sizeof(Node));

    // Initialize the adjacency list
    for (int i = 1; i <= N; i++) {
        nodes[i].head = NULL;
        nodes[i].deg = 0;
    }

    // Read the edges from input
    int u, v;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Find the root of the tree (any node with degree 1 can be the root)
    int root = 1;
    for (int i = 1; i <= N; i++) {
        if (nodes[i].deg == 1) {
            root = i;
            break;
        }
    }

    // Calculate the number of ways to divide the vertices into pairs
    int result = countPairs(root);

    // Print the result
    printf("%d\n", result);

    // Free allocated memory
    free(nodes);

    return 0;
}