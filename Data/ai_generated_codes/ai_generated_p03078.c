#include <stdio.h>
#include <stdlib.h>

// Function to compare two arrays of integers
int compare_arrays(const void *a, const void *b) {
    int *arr1 = (int *)a;
    int *arr2 = (int *)b;
    // Compare the sum of elements in the arrays in descending order
    return (arr2[0] + arr2[1] + arr2[2]) - (arr1[0] + arr1[1] + arr1[2]);
}

int main() {
    int X, Y, Z, K;
    scanf("%d %d %d %d", &X, &Y, &Z, &K);

    // Allocate memory for arrays of deliciousness values
    int *A = (int *)malloc(X * sizeof(int));
    int *B = (int *)malloc(Y * sizeof(int));
    int *C = (int *)malloc(Z * sizeof(int));

    // Read deliciousness values from input
    for (int i = 0; i < X; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < Y; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < Z; i++) {
        scanf("%d", &C[i]);
    }

    // Allocate memory for an array to store combinations of cakes
    int **combinations = (int **)malloc(X * Y * Z * sizeof(int *));
    for (int i = 0; i < X * Y * Z; i++) {
        combinations[i] = (int *)malloc(3 * sizeof(int));
    }

    // Generate all combinations of cakes
    int index = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                combinations[index][0] = A[i];
                combinations[index][1] = B[j];
                combinations[index][2] = C[k];
                index++;
            }
        }
    }

    // Sort combinations in descending order of deliciousness sum
    qsort(combinations, X * Y * Z, sizeof(int *), compare_arrays);

    // Print the sum of deliciousness for the first K combinations
    for (int i = 0; i < K; i++) {
        printf("%d\n", combinations[i][0] + combinations[i][1] + combinations[i][2]);
    }

    // Free allocated memory
    free(A);
    free(B);
    free(C);
    for (int i = 0; i < X * Y * Z; i++) {
        free(combinations[i]);
    }
    free(combinations);

    return 0;
}