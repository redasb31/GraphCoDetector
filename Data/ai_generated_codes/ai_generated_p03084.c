#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 200000

// Structure to represent a query
typedef struct {
    int a, b, c, d;
} Query;

// Function to calculate the distance between two intersections
int distance(int a1, int b1, int a2, int b2) {
    return abs(a1 - a2) + abs(b1 - b2);
}

// Function to check if a path exists from (a, b) to (c, d)
int check_path(char *S, char *T, int a, int b, int c, int d) {
    // Check if the directions allow moving horizontally
    if (a < c && S[a] != 'E') return 0;
    if (a > c && S[c] != 'W') return 0;
    // Check if the directions allow moving vertically
    if (b < d && T[b] != 'N') return 0;
    if (b > d && T[d] != 'S') return 0;
    return 1;
}

int main() {
    int N, M, Q;
    char S[MAX_N + 1], T[MAX_M + 1];
    Query queries[MAX_Q];

    // Read input
    scanf("%d %d %d\n", &N, &M, &Q);
    scanf("%s\n", S);
    scanf("%s\n", T);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d\n", &queries[i].a, &queries[i].b, &queries[i].c, &queries[i].d);
    }

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Check if a path exists
        if (check_path(S, T, queries[i].a, queries[i].b, queries[i].c, queries[i].d)) {
            // Calculate the distance
            printf("%d\n", distance(queries[i].a, queries[i].b, queries[i].c, queries[i].d));
        } else {
            // No path exists
            printf("-1\n");
        }
    }

    return 0;
}