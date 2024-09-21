#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000

int N, A, B;
int p[MAX_N + 1];

// Function to calculate the cost of shifting a segment to the left
int cost_left(int l, int r) {
    return A * (r - l);
}

// Function to calculate the cost of shifting a segment to the right
int cost_right(int l, int r) {
    return B * (r - l);
}

// Function to calculate the minimum cost to sort the permutation
int solve() {
    int cost = 0;

    // Iterate through the permutation
    for (int i = 1; i <= N; i++) {
        // Find the index of the element i
        int j = i;
        while (p[j] != i) {
            j++;
        }

        // If the element is not in its correct position
        if (j != i) {
            // Calculate the cost of shifting the segment to the left or right
            int cost_left_shift = cost_left(i, j);
            int cost_right_shift = cost_right(i, j);

            // Choose the operation with the minimum cost
            if (cost_left_shift < cost_right_shift) {
                // Shift the segment to the left
                for (int k = j - 1; k >= i; k--) {
                    p[k + 1] = p[k];
                }
                p[i] = i;
                cost += cost_left_shift;
            } else {
                // Shift the segment to the right
                for (int k = i; k < j; k++) {
                    p[k] = p[k + 1];
                }
                p[j] = i;
                cost += cost_right_shift;
            }
        }
    }

    return cost;
}

int main() {
    // Read the input
    scanf("%d %d %d", &N, &A, &B);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i]);
    }

    // Calculate and print the minimum cost
    printf("%d\n", solve());

    return 0;
}