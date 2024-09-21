#include <stdio.h>
#include <stdlib.h>

#define MAX_W 10000
#define MAX_H 10000
#define MAX_N 100000

int W, H, K;
int N;
int dog_block[MAX_W + 1][MAX_H + 1]; // 1 if a dog is at the block, 0 otherwise

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Input
    scanf("%d %d %d", &W, &H, &K);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dog_block[x][y] = 1;
    }

    // Check if the number of houses is greater than the number of special pipes.
    int num_houses = (W + 1) / 2 * (H + 1) / 2;
    if (num_houses > K) {
        printf("-1\n");
        return 0;
    }

    // Initialize the cost of connecting each house to the water source.
    int cost[MAX_W + 1][MAX_H + 1];
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            cost[i][j] = 1000000000; // Initialize to a large value
        }
    }

    // Connect houses from the north to the south.
    for (int j = 1; j <= H; j += 2) {
        for (int i = 1; i <= W; i += 2) {
            if (j == 1) { // First row, connect to the water source
                cost[i][j] = 0;
            } else {
                // Connect to the previous house.
                cost[i][j] = min(cost[i - 2][j - 2] + dog_block[i - 1][j - 1],
                                 cost[i][j - 2] + dog_block[i][j - 1],
                                 cost[i + 2][j - 2] + dog_block[i + 1][j - 1]);
                if (dog_block[i - 1][j - 1]) {
                    cost[i][j] += 1;
                }
                if (dog_block[i][j - 1]) {
                    cost[i][j] += 1;
                }
                if (dog_block[i + 1][j - 1]) {
                    cost[i][j] += 1;
                }
            }
        }
    }

    // Compute the total cost.
    int total_cost = 0;
    for (int i = 1; i <= W; i += 2) {
        for (int j = 1; j <= H; j += 2) {
            total_cost += cost[i][j];
        }
    }

    printf("%d\n", total_cost);
    return 0;
}