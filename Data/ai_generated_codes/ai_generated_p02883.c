#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    // Input: N - number of team members and foods, K - maximum training sets
    int N, K;
    scanf("%d %d", &N, &K);

    // Input: Consumption coefficients of members (A)
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Input: Difficulty of foods (F)
    int *F = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &F[i]);
    }

    // Sort the consumption coefficients and food difficulties in descending order
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] < A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            if (F[i] < F[j]) {
                int temp = F[i];
                F[i] = F[j];
                F[j] = temp;
            }
        }
    }

    // Calculate the minimum possible score
    int score = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the maximum possible training sets for the current member
        int max_training = min(K, A[i]);

        // Reduce the consumption coefficient by the maximum possible training sets
        A[i] -= max_training;

        // Update the training sets remaining
        K -= max_training;

        // Calculate the time taken by the member to finish the food
        int time = A[i] * F[i];

        // Update the score
        score = max(score, time);
    }

    // Print the minimum possible score
    printf("%d\n", score);

    // Free the allocated memory
    free(A);
    free(F);

    return 0;
}