#include <stdio.h>
#include <stdlib.h>

// Function to check if a multiset S can be formed by the healths of slimes after N seconds
int is_possible(int N, int *S) {
    // Check if the number of elements in S is 2^N
    if (1 << N != (1 << N)) {
        return 0;
    }

    // Sort the elements of S in descending order
    for (int i = 0; i < (1 << N) - 1; i++) {
        for (int j = i + 1; j < (1 << N); j++) {
            if (S[i] < S[j]) {
                int temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }

    // Check if the healths of the slimes can be formed from S
    for (int i = 0; i < (1 << N); i++) {
        // The health of a slime must be greater than the health of the slime spawned from it
        if (i > 0 && S[i] >= S[i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the multiset S
    int *S = (int *)malloc((1 << N) * sizeof(int));
    if (S == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read the elements of S
    for (int i = 0; i < (1 << N); i++) {
        scanf("%d", &S[i]);
    }

    // Check if it is possible to form S
    if (is_possible(N, S)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free the allocated memory
    free(S);

    return 0;
}