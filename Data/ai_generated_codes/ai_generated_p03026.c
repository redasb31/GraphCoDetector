#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000
#define MAX_C 100000

int N;
int a[MAX_N - 1], b[MAX_N - 1];
int c[MAX_N];

int parent[MAX_N];
int depth[MAX_N];
int sorted_c[MAX_N];
int d[MAX_N];

// Function to find the parent of a node in the tree
int find_parent(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

// Function to calculate the depth of each node in the tree
void calculate_depth(int root) {
    depth[root] = 0;
    for (int i = 0; i < N - 1; i++) {
        int u = find_parent(a[i]);
        int v = find_parent(b[i]);
        if (u != v) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
        }
    }
}

// Function to compare two integers
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Input the tree information
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
        sorted_c[i] = c[i];
    }

    // Initialize the parent array
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    // Calculate the depth of each node
    calculate_depth(0);

    // Sort the c array in ascending order
    qsort(sorted_c, N, sizeof(int), compare);

    // Assign the largest c values to the deepest nodes
    for (int i = 0; i < N; i++) {
        int node = i;
        d[node] = sorted_c[N - i - 1];
    }

    // Calculate the score
    int score = 0;
    for (int i = 0; i < N - 1; i++) {
        score += (d[a[i]] < d[b[i]]) ? d[a[i]] : d[b[i]];
    }

    // Output the result
    printf("%d\n", score);
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", d[i]);
    }
    printf("\n");

    return 0;
}