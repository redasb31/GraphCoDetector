#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int N;
long long D[MAX_N];

// Function to find the parent of a vertex in the union-find data structure
int find(int *parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

// Function to merge two sets in the union-find data structure
void merge(int *parent, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    parent[px] = py;
}

// Function to check if a tree with the given distances exists and construct it
int construct_tree(long long *dist) {
    // Create an array to store the parent of each vertex in the union-find data structure
    int *parent = malloc(sizeof(int) * (N + 1));
    // Initialize the parent array
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    // Calculate the total distance in the tree
    long long total_distance = 0;
    for (int i = 1; i <= N; i++) {
        total_distance += dist[i];
    }
    // Check if the total distance is even
    if (total_distance % 2 != 0) {
        free(parent);
        return -1; // Tree cannot exist
    }
    // Sort the distances in descending order
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (dist[i] < dist[j]) {
                long long temp = dist[i];
                dist[i] = dist[j];
                dist[j] = temp;
            }
        }
    }
    // Connect vertices to form the tree based on the sorted distances
    int current_vertex = 1;
    for (int i = 1; i <= N - 1; i++) {
        // Find the parent of the current vertex
        int current_parent = find(parent, current_vertex);
        // Find the parent of the next vertex
        int next_parent = find(parent, current_vertex + 1);
        // If the parents are different, merge the sets and connect the vertices
        if (current_parent != next_parent) {
            printf("%d %d\n", current_vertex, current_vertex + 1);
            merge(parent, current_parent, next_parent);
        }
        // If the parents are the same, the current vertex is the leaf node of the tree
        else {
            current_vertex++;
        }
    }
    free(parent);
    return 0;
}

int main() {
    // Read the input
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &D[i]);
    }
    // Check if a tree exists and construct it
    int result = construct_tree(D);
    // Print the result
    if (result == -1) {
        printf("-1\n");
    }
    return 0;
}