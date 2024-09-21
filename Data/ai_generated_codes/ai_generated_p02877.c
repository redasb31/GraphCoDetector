#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum number of operations required to achieve the target sequence
int minOperations(int *A, int N) {
    // Calculate the number of operations required to make the prefix sum non-decreasing
    int operations = 0;
    int prefixSum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < prefixSum) {
            operations += prefixSum - A[i];
        }
        prefixSum = A[i];
    }

    // Calculate the number of operations required to make the suffix sum non-increasing
    int suffixSum = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] < suffixSum) {
            operations += suffixSum - A[i];
        }
        suffixSum = A[i];
    }

    return operations;
}

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int operations = minOperations(A, N);
    printf("%d\n", operations);

    free(A);
    return 0;
}