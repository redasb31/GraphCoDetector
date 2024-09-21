#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a given point is inside the closed curve
int isInside(int x, int y, int *x_coords, int *y_coords, int L) {
    int i, j, count = 0;
    for (i = 0, j = L - 1; i < L; j = i++) {
        if (((y_coords[i] > y) != (y_coords[j] > y)) &&
            (x < (x_coords[j] - x_coords[i]) * (y - y_coords[i]) / (y_coords[j] - y_coords[i]) + x_coords[i])) {
            count++;
        }
    }
    return count % 2;
}

// Function to check if the given sequence A satisfies the condition
int checkCondition(int N, int *A, int *x_coords, int *y_coords, int L) {
    int i, x, S;
    for (i = 0; i < (1 << N); i++) {
        x = 0;
        S = i;
        for (int j = 0; j < N; j++) {
            if (S & 1) {
                x += 1 << j;
            }
            S >>= 1;
        }
        if (A[x] == 1) {
            // Check if any point in B_S is inside the curve
            for (int j = 0; j < N; j++) {
                if (S & 1) {
                    if (isInside(j + 1, 1, x_coords, y_coords, L)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int N, i, j, *A;
    scanf("%d", &N);

    // Allocate memory for the sequence A
    A = (int *)malloc((1 << N) * sizeof(int));
    char str[100];
    scanf("%s", str);
    for (i = 0; i < (1 << N); i++) {
        A[i] = str[i] - '0';
    }

    // Check if A_0 is 1
    if (A[0] != 1) {
        printf("Impossible\n");
        free(A);
        return 0;
    }

    // Define a closed curve that satisfies the condition
    int L = N + 1;
    int *x_coords = (int *)malloc(L * sizeof(int));
    int *y_coords = (int *)malloc(L * sizeof(int));
    for (i = 0; i <= N; i++) {
        x_coords[i] = i;
        y_coords[i] = (i == N) ? 0 : 1;
    }

    // Check if the curve satisfies the condition
    if (checkCondition(N, A, x_coords, y_coords, L)) {
        printf("Possible\n");
        printf("%d\n", L);
        for (i = 0; i < L; i++) {
            printf("%d %d\n", x_coords[i], y_coords[i]);
        }
    } else {
        printf("Impossible\n");
    }

    // Free the allocated memory
    free(A);
    free(x_coords);
    free(y_coords);
    return 0;
}