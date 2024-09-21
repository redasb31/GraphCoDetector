#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_E 200000

int N;
int E[MAX_N][MAX_E];
int c[MAX_N];

int visited[MAX_N];
int stack[MAX_N];
int top;

// Function to perform Depth First Search (DFS)
void dfs(int u) {
    visited[u] = 1;
    stack[top++] = u;

    for (int i = 0; i < c[u - 1]; i++) {
        int v = E[u - 1][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// Function to check if a graph is a tree
int isTree() {
    top = 0;
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }

    dfs(1);

    // Check if all vertices are visited and the stack size is N
    if (top != N) {
        return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &N);

    // Input the subsets
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &c[i]);
        for (int j = 0; j < c[i]; j++) {
            scanf("%d", &E[i][j]);
        }
    }

    // Check if a tree can be formed
    if (!isTree()) {
        printf("-1\n");
        return 0;
    }

    // Construct the tree edges (u_i, v_i)
    for (int i = 0; i < N - 1; i++) {
        // Choose the first two elements from each subset
        printf("%d %d\n", E[i][0], E[i][1]);
    }

    return 0;
}