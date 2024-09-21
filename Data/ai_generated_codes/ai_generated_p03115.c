#include <stdio.h>
#include <stdlib.h>

// Structure to represent a lamp
typedef struct {
    long long x;
    long long y;
} Lamp;

// Function to compare two lamps based on their x-coordinates
int compare_lamps(const void *a, const void *b) {
    Lamp *lamp_a = (Lamp *)a;
    Lamp *lamp_b = (Lamp *)b;
    return lamp_a->x - lamp_b->x;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for N lamps
    Lamp *lamps = (Lamp *)malloc(N * sizeof(Lamp));
    if (lamps == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Read the coordinates of the lit lamps
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &lamps[i].x, &lamps[i].y);
    }

    // Sort the lamps based on their x-coordinates
    qsort(lamps, N, sizeof(Lamp), compare_lamps);

    // Find the initial lamp position (X, 0)
    long long X = -1;
    for (int i = 0; i < N; i++) {
        // Check if the current lamp is on the x-axis and has no other lamps above it
        if (lamps[i].y == 0 && (i == N - 1 || lamps[i + 1].x != lamps[i].x)) {
            X = lamps[i].x;
            break;
        }
    }

    // If X is not found, it means there was an error in the input
    if (X == -1) {
        fprintf(stderr, "Invalid input.\n");
        exit(1);
    }

    // Print the initial lamp position (X, 0)
    printf("%lld\n", X);

    // Free the allocated memory
    free(lamps);

    return 0;
}