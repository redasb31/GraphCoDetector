#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define INF 1000000000

// Structure to represent a passageway
typedef struct {
    int from;
    int to;
    int cost;
} Passageway;

// Function to find the minimum cost to split the rooms into two groups
int min_cost(int n, Passageway passageways[], int m) {
    // Create an adjacency list to represent the passageways
    int adj_list[MAX_ROOMS][MAX_ROOMS] = {0};
    for (int i = 0; i < m; i++) {
        adj_list[passageways[i].from][passageways[i].to] = passageways[i].cost;
    }

    // Create a table to store the minimum cost to split the rooms into two groups
    int dp[1 << n][n];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    // Base case: If no rooms are selected, the cost is 0
    dp[0][0] = 0;

    // Iterate over all possible subsets of rooms
    for (int i = 1; i < (1 << n); i++) {
        // Iterate over all rooms
        for (int j = 0; j < n; j++) {
            // If the current room is in the subset
            if (i & (1 << j)) {
                // Iterate over all adjacent rooms
                for (int k = 0; k < n; k++) {
                    // If the adjacent room is in the subset and there is a passageway between them
                    if (i & (1 << k) && adj_list[j][k] != 0) {
                        // Update the minimum cost
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + adj_list[j][k]);
                    }
                }
            }
        }
    }

    // Find the minimum cost among all possible subsets
    int min_cost = INF;
    for (int i = 0; i < n; i++) {
        min_cost = min(min_cost, dp[(1 << n) - 1][i]);
    }

    // Return the minimum cost
    return min_cost;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) {
        Passageway passageways[MAX_ROOMS];
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &passageways[i].from, &passageways[i].to, &passageways[i].cost);
        }

        // Find the minimum cost to split the rooms into two groups
        int cost = min_cost(n, passageways, m);

        // Print the minimum cost
        printf("%d\n", cost);
    }
    return 0;
}