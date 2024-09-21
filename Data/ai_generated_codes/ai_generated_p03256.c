#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200000
#define MAX_M 200000

typedef struct {
    int a;
    int b;
} Edge;

int main() {
    int N, M;
    char s[MAX_N + 1];
    Edge edges[MAX_M];
    int visited[MAX_N + 1]; // Track visited nodes for a specific path
    int connected_components = 0;

    // Input
    scanf("%d %d\n", &N, &M);
    scanf("%s\n", s);
    for (int i = 0; i < M; i++) {
        scanf("%d %d\n", &edges[i].a, &edges[i].b);
    }

    // Connected components check (using Depth First Search - DFS)
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            connected_components++;
            // DFS to explore the connected component
            visited[i] = 1;
            int stack[MAX_N + 1], top = 0;
            stack[top++] = i;
            while (top) {
                int current = stack[--top];
                for (int j = 0; j < M; j++) {
                    if ((edges[j].a == current && !visited[edges[j].b]) || 
                        (edges[j].b == current && !visited[edges[j].a])) {
                        visited[edges[j].a] = visited[edges[j].b] = 1;
                        stack[top++] = (edges[j].a == current) ? edges[j].b : edges[j].a;
                    }
                }
            }
        }
    }

    // Check if the graph is connected and has both A and B labels
    if (connected_components == 1) {
        // Check for presence of both 'A' and 'B'
        int has_A = 0, has_B = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'A') {
                has_A = 1;
            } else if (s[i] == 'B') {
                has_B = 1;
            }
        }
        if (has_A && has_B) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No\n");
    }

    return 0;
}