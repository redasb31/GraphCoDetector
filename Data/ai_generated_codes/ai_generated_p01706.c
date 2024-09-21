#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 10000

int N, M, S, T;
int adj[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];

// Depth-first search to find the number of trucks that can be used
int dfs(int u) {
    visited[u] = 1;
    int count = 0;
    for (int v = 1; v <= N; v++) {
        if (adj[u][v] && !visited[v]) {
            count += dfs(v);
        }
    }
    return count + 1;
}

// Function to reverse the direction of a road
void reverse_road(int u, int v) {
    adj[u][v] = 0;
    adj[v][u] = 1;
}

// Function to calculate the maximum number of trucks that can be used after reversing a road
int calculate_max_trucks_after_reversal(int u, int v) {
    // Reverse the road
    reverse_road(u, v);

    // Find the maximum number of trucks that can be used after reversing the road
    int max_trucks = dfs(S);

    // Restore the original direction of the road
    reverse_road(u, v);

    return max_trucks;
}

int main() {
    while (1) {
        // Read input
        scanf("%d %d %d %d", &N, &M, &S, &T);
        if (N == 0 && M == 0 && S == 0 && T == 0) {
            break;
        }

        // Initialize adjacency matrix
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = 0;
            }
        }

        // Read roads
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][b] = 1;
        }

        // Find the initial maximum number of trucks
        int max_trucks = dfs(S);

        // Initialize variables to store the maximum number of trucks after reversal and the number of roads that can be reversed
        int max_trucks_after_reversal = max_trucks;
        int num_roads_to_reverse = 0;

        // Iterate over all roads to find the maximum number of trucks after reversing a road
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j]) {
                    int temp_max_trucks = calculate_max_trucks_after_reversal(i, j);
                    if (temp_max_trucks > max_trucks_after_reversal) {
                        max_trucks_after_reversal = temp_max_trucks;
                        num_roads_to_reverse = 1;
                    } else if (temp_max_trucks == max_trucks_after_reversal) {
                        num_roads_to_reverse++;
                    }
                }
            }
        }

        // Print output
        printf("%d %d\n", max_trucks_after_reversal, num_roads_to_reverse);
    }

    return 0;
}