#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum number of balloons to change size
int min_change(int N, int K, int *a, int *r, int *b) {
    // Create a 2D array to store the available balloons for each size and color
    int **available = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++) {
        available[i] = (int *)malloc((K + 1) * sizeof(int));
    }

    // Initialize the available balloons array
    for (int i = 1; i <= K; i++) {
        available[0][i] = r[i - 1]; // Red balloons
        available[1][i] = b[i - 1]; // Black balloons
    }

    // Sort the problems in decreasing order of acceptance count
    int *problem_order = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        problem_order[i] = i;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[problem_order[j]] > a[problem_order[i]]) {
                int temp = problem_order[i];
                problem_order[i] = problem_order[j];
                problem_order[j] = temp;
            }
        }
    }

    // Assign balloons to problems
    int changes = 0; // Count of balloons to change size
    int current_size = 1; // Start with size 1
    for (int i = 0; i < N; i++) {
        int problem_index = problem_order[i]; // Get the problem index
        int required = a[problem_index]; // Number of balloons needed for the problem
        // Find the color with maximum available balloons for the current size
        int color = (available[0][current_size] > available[1][current_size]) ? 0 : 1;
        if (available[color][current_size] >= required) {
            // Assign balloons from the chosen color
            available[color][current_size] -= required;
        } else {
            // Not enough balloons of the chosen color, need to change size
            int diff = required - available[color][current_size]; // Difference in required and available
            changes += diff; // Increment the change count
            available[color][current_size] = 0; // Set the available balloons to 0
            // Find the next size with available balloons
            current_size++;
            while (available[0][current_size] == 0 && available[1][current_size] == 0 && current_size <= K) {
                current_size++;
            }
            if (current_size > K) {
                // No more available balloons, return -1
                free(problem_order);
                for (int j = 0; j < 2; j++) {
                    free(available[j]);
                }
                free(available);
                return -1;
            }
            // Assign the remaining balloons from the next size
            available[color][current_size] -= required - diff;
        }
    }
    // Free allocated memory
    free(problem_order);
    for (int i = 0; i < 2; i++) {
        free(available[i]);
    }
    free(available);
    return changes; // Return the minimum number of balloons to change size
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *a = (int *)malloc(N * sizeof(int));
    int *r = (int *)malloc(K * sizeof(int));
    int *b = (int *)malloc(K * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &b[i]);
    }

    int changes = min_change(N, K, a, r, b);
    printf("%d\n", changes);

    free(a);
    free(r);
    free(b);
    return 0;
}