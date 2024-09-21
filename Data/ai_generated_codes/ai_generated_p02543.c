#include <stdio.h>

// Function to find the size of the union of all good sets for a given query
int find_union_size(int N, int K, int* X, int L, int R) {
    // Initialize the size of the union
    int union_size = 0;

    // Iterate over the points in the query range
    for (int i = L - 1; i < R; i++) {
        // Check if the current point is included in any good set
        if (i == L - 1 || X[i] - X[i - 1] >= K) {
            // If yes, increment the union size
            union_size++;
        }
    }

    // Return the size of the union
    return union_size;
}

int main() {
    // Input the number of points, K, and the points themselves
    int N, K;
    scanf("%d %d", &N, &K);

    int X[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    // Input the number of queries
    int Q;
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Input the query range
        int L, R;
        scanf("%d %d", &L, &R);

        // Find the size of the union of all good sets for the current query
        int union_size = find_union_size(N, K, X, L, R);

        // Output the size of the union
        printf("%d\n", union_size);
    }

    return 0;
}