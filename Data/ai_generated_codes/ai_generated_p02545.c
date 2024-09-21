#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum number of operations to transform A into B
int min_operations(int *A, int *B, int N) {
    // Create a map to store the positions of each element in B
    int *B_map = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i <= N; i++) {
        B_map[i] = -1;
    }
    for (int i = 0; i < 3 * N; i++) {
        B_map[B[i]] = i;
    }

    // Initialize the count of operations
    int operations = 0;

    // Iterate through each element in A
    for (int i = 0; i < 3 * N; i++) {
        int x = A[i];

        // Find the position of the corresponding element in B
        int target_pos = B_map[x];

        // If the current element is in the correct position, continue
        if (i == target_pos) {
            continue;
        }

        // If the element is not in the correct position, calculate the minimum operations required to move it
        int min_moves = 0;

        // Calculate the distance between the current position and the target position
        int dist1 = abs(i - target_pos);

        // Calculate the distance between the current position and the target position when moving the element to the beginning
        int dist2 = i + 1;

        // Calculate the distance between the current position and the target position when moving the element to the end
        int dist3 = (3 * N - i) + 1;

        // Find the minimum distance
        min_moves = dist1;
        if (dist2 < min_moves) {
            min_moves = dist2;
        }
        if (dist3 < min_moves) {
            min_moves = dist3;
        }

        // Update the count of operations
        operations += min_moves;

        // Update the position of the element in B
        B_map[x] = i;
    }

    // Free the memory allocated for the map
    free(B_map);

    // Return the count of operations
    return operations;
}

int main() {
    // Read the input values
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(sizeof(int) * 3 * N);
    int *B = (int *)malloc(sizeof(int) * 3 * N);
    for (int i = 0; i < 3 * N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < 3 * N; i++) {
        scanf("%d", &B[i]);
    }

    // Calculate the minimum number of operations
    int operations = min_operations(A, B, N);

    // Print the result
    printf("%d\n", operations);

    // Free the memory allocated for the arrays
    free(A);
    free(B);

    return 0;
}