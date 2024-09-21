#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

// Function to calculate the number of ways to arrange numbers
long long countWays(int N, int M, int *A, int *B) {
    // Create a table to store the number of ways to arrange numbers in each row and column
    int **table = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i <= N; i++) {
        table[i] = (int *)malloc(sizeof(int) * (M + 1));
        for (int j = 0; j <= M; j++) {
            table[i][j] = 0;
        }
    }

    // Initialize the table with the maximum values in each row and column
    for (int i = 1; i <= N; i++) {
        table[i][0] = A[i - 1];
    }
    for (int j = 1; j <= M; j++) {
        table[0][j] = B[j - 1];
    }

    // Fill the table with the number of ways to arrange numbers
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // If the current cell is greater than or equal to the maximum value in the row and column
            if (table[i][j - 1] >= table[i - 1][j]) {
                table[i][j] = table[i][j - 1];
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    // Calculate the number of ways to arrange numbers
    long long ways = factorial(N * M);
    for (int i = 1; i <= N; i++) {
        ways = (ways * factorial(table[i][M] - 1)) % MOD;
    }
    for (int j = 1; j <= M; j++) {
        ways = (ways * factorial(table[N][j] - 1)) % MOD;
    }

    // Free the allocated memory
    for (int i = 0; i <= N; i++) {
        free(table[i]);
    }
    free(table);

    return ways;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *A = (int *)malloc(sizeof(int) * N);
    int *B = (int *)malloc(sizeof(int) * M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int j = 0; j < M; j++) {
        scanf("%d", &B[j]);
    }

    long long ways = countWays(N, M, A, B);

    printf("%lld\n", ways);

    free(A);
    free(B);

    return 0;
}