#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cake
typedef struct Cake {
    long long beauty;
    long long tastiness;
    long long popularity;
} Cake;

// Function to compare cakes based on beauty, then tastiness, then popularity
int compare_cakes(const void *a, const void *b) {
    Cake *cake_a = (Cake *)a;
    Cake *cake_b = (Cake *)b;

    // Compare beauty in descending order
    if (cake_a->beauty > cake_b->beauty) {
        return -1;
    } else if (cake_a->beauty < cake_b->beauty) {
        return 1;
    } else {
        // If beauty is equal, compare tastiness in descending order
        if (cake_a->tastiness > cake_b->tastiness) {
            return -1;
        } else if (cake_a->tastiness < cake_b->tastiness) {
            return 1;
        } else {
            // If beauty and tastiness are equal, compare popularity in descending order
            if (cake_a->popularity > cake_b->popularity) {
                return -1;
            } else if (cake_a->popularity < cake_b->popularity) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for cakes
    Cake *cakes = (Cake *)malloc(sizeof(Cake) * N);
    if (cakes == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Read cake data
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld %lld", &cakes[i].beauty, &cakes[i].tastiness, &cakes[i].popularity);
    }

    // Sort cakes based on beauty, tastiness, and popularity
    qsort(cakes, N, sizeof(Cake), compare_cakes);

    // Calculate the maximum value
    long long max_value = 0;
    long long total_beauty = 0;
    long long total_tastiness = 0;
    long long total_popularity = 0;

    for (int i = 0; i < M; i++) {
        total_beauty += cakes[i].beauty;
        total_tastiness += cakes[i].tastiness;
        total_popularity += cakes[i].popularity;
    }

    max_value = abs(total_beauty) + abs(total_tastiness) + abs(total_popularity);

    // Free allocated memory
    free(cakes);

    // Print the maximum value
    printf("%lld\n", max_value);

    return 0;
}