#include <stdio.h>
#include <stdlib.h>

// Structure to store the information of a chocolate ball
typedef struct {
    int nutrition;
    int deliciousness;
} ChocolateBall;

// Function to calculate the maximum deliciousness that can be obtained by Alice and Brianna
// using dynamic programming
void calculateMaxDeliciousness(ChocolateBall *chocolateBalls, int N, int A, int B, int *aliceDeliciousness, int *briannaDeliciousness) {
    // Create a 2D array to store the maximum deliciousness that can be obtained
    // by Alice and Brianna at each step
    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int *)malloc((A + 1) * sizeof(int));
    }

    // Initialize the base case
    for (int i = 0; i <= A; i++) {
        dp[0][i] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= A; j++) {
            // Calculate the maximum deliciousness if Alice takes the chocolate ball
            int aliceEat = 0;
            if (j >= chocolateBalls[i - 1].nutrition) {
                aliceEat = dp[i - 1][j - chocolateBalls[i - 1].nutrition] + chocolateBalls[i - 1].deliciousness;
            }

            // Calculate the maximum deliciousness if Alice passes
            int alicePass = dp[i - 1][j];

            // Calculate the maximum deliciousness for Alice
            dp[i][j] = (aliceEat > alicePass) ? aliceEat : alicePass;

            // Calculate the maximum deliciousness for Brianna
            // by considering the maximum deliciousness that Alice can get
            // for each energy level of Brianna
            for (int k = 0; k <= B; k++) {
                int briannaEat = 0;
                if (k >= chocolateBalls[i - 1].nutrition) {
                    briannaEat = dp[i - 1][j - chocolateBalls[i - 1].nutrition + k - chocolateBalls[i - 1].nutrition] + chocolateBalls[i - 1].deliciousness;
                }

                int briannaPass = dp[i - 1][j + k - 1];

                dp[i][j] = (briannaEat > briannaPass) ? briannaEat : briannaPass;
            }
        }
    }

    // Store the maximum deliciousness for Alice and Brianna
    *aliceDeliciousness = dp[N][A];
    *briannaDeliciousness = dp[N][A + B];

    // Free the allocated memory
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    ChocolateBall *chocolateBalls = (ChocolateBall *)malloc(N * sizeof(ChocolateBall));

    // Read the input for each chocolate ball
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &chocolateBalls[i].nutrition, &chocolateBalls[i].deliciousness);
    }

    int aliceDeliciousness, briannaDeliciousness;
    calculateMaxDeliciousness(chocolateBalls, N, A, B, &aliceDeliciousness, &briannaDeliciousness);

    // Print the output
    printf("%d %d\n", aliceDeliciousness, briannaDeliciousness);

    // Free the allocated memory
    free(chocolateBalls);

    return 0;
}