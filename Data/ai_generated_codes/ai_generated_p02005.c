#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a colored liquid
typedef struct {
    char color[21];
    int density;
} Liquid;

// Function to compare the densities of two liquids
int compare_density(const void *a, const void *b) {
    Liquid *l1 = (Liquid *)a;
    Liquid *l2 = (Liquid *)b;
    return l1->density - l2->density;
}

int main() {
    int N, M;
    scanf("%d", &N);

    // Allocate memory for prepared liquids
    Liquid *liquids = (Liquid *)malloc(N * sizeof(Liquid));

    // Read the details of the prepared liquids
    for (int i = 0; i < N; i++) {
        scanf("%s %d", liquids[i].color, &liquids[i].density);
    }

    // Sort the liquids based on their density in ascending order
    qsort(liquids, N, sizeof(Liquid), compare_density);

    scanf("%d", &M);

    // Allocate memory for the requested drink layers
    char *layers[M];
    for (int i = 0; i < M; i++) {
        layers[i] = (char *)malloc(21 * sizeof(char));
    }

    // Read the color layers of the requested drink
    for (int i = 0; i < M; i++) {
        scanf("%s", layers[i]);
    }

    // Flag to indicate if the requested drink can be served
    int can_serve = 1;

    // Check if all the requested layers can be served
    int j = N - 1;  // Start from the densest liquid
    for (int i = M - 1; i >= 0 && j >= 0; i--) {
        // If the current layer's color matches the current liquid's color
        if (strcmp(layers[i], liquids[j].color) == 0) {
            j--; // Move to the next less dense liquid
        } else {
            can_serve = 0; // Cannot serve the request
            break;
        }
    }

    // Print the result
    if (can_serve) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
    free(liquids);
    for (int i = 0; i < M; i++) {
        free(layers[i]);
    }

    return 0;
}