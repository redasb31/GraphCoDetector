#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 1000
#define MAX_F 200

int N, M, s, t, f;
int s_i[MAX_M], t_i[MAX_M], a_i[MAX_M], b_i[MAX_M], d_i[MAX_M];

// Function to calculate the cost of carrying 'u' units of freight by the 'i'th pigeon
int cost(int i, int u) {
    if (u <= d_i[i]) {
        return u * a_i[i];
    } else {
        return d_i[i] * a_i[i] + (u - d_i[i]) * b_i[i];
    }
}

// Function to find the minimum cost to carry 'f' units of freight from 's' to 't'
int min_cost(int f) {
    int dp[MAX_F + 1]; // dp[i] stores the minimum cost to carry 'i' units of freight
    for (int i = 0; i <= f; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    // Iterate over all pigeons
    for (int i = 0; i < M; i++) {
        // Iterate over possible freight amounts
        for (int j = f; j >= 0; j--) {
            // If the pigeon can carry 'j' units of freight
            if (s_i[i] == s && t_i[i] == t) {
                // Update the minimum cost to carry 'j' units
                dp[j] = (dp[j] < cost(i, j)) ? dp[j] : cost(i, j);
            }
        }
    }

    // Check if it's possible to carry 'f' units of freight
    if (dp[f] == INT_MAX) {
        return -1;
    } else {
        return dp[f];
    }
}

int main() {
    // Input
    scanf("%d %d %d %d %d", &N, &M, &s, &t, &f);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &s_i[i], &t_i[i], &a_i[i], &b_i[i], &d_i[i]);
    }

    // Calculate the minimum cost
    int cost = min_cost(f);

    // Output
    if (cost == -1) {
        printf("Impossible\n");
    } else {
        printf("%d\n", cost);
    }

    return 0;
}