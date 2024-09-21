#include <stdio.h>
#include <stdlib.h>

// Structure to store energy drink information
typedef struct {
    int climb;
    int slide;
} EnergyDrink;

// Function to compare two energy drinks based on climbing distance
int compare(const void *a, const void *b) {
    EnergyDrink *drinkA = (EnergyDrink *)a;
    EnergyDrink *drinkB = (EnergyDrink *)b;
    return drinkB->climb - drinkA->climb; // Sort in descending order of climb
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    // Allocate memory for energy drinks and sinner climb distances
    EnergyDrink *drinks = (EnergyDrink *)malloc(sizeof(EnergyDrink) * N);
    int *sinnerClimbs = (int *)malloc(sizeof(int) * N);

    // Read energy drink information
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &drinks[i].climb, &drinks[i].slide);
    }

    // Read sinner climb distances
    for (int i = 0; i < N; i++) {
        scanf("%d", &sinnerClimbs[i]);
    }

    // Sort energy drinks by climbing distance in descending order
    qsort(drinks, N, sizeof(EnergyDrink), compare);

    // Initialize variables for current height and sinner position
    int currentHeight = 0;
    int sinnerPosition = 0;

    // Iterate through energy drinks
    for (int i = 0; i < N; i++) {
        // Calculate the height after climbing with the current energy drink
        currentHeight += drinks[i].climb;

        // Check if the worker can escape
        if (currentHeight >= L) {
            printf("%d\n", i + 1); // Output the day of escape
            free(drinks);
            free(sinnerClimbs);
            return 0;
        }

        // Update the sinner position
        sinnerPosition += sinnerClimbs[i];

        // Check if the sinner has caught up
        if (sinnerPosition >= currentHeight) {
            free(drinks);
            free(sinnerClimbs);
            printf("-1\n"); // Output -1 if the sinner catches up
            return 0;
        }

        // Update the height after sliding down
        currentHeight -= drinks[i].slide;
    }

    // If the worker hasn't escaped after using all energy drinks, output -1
    free(drinks);
    free(sinnerClimbs);
    printf("-1\n");
    return 0;
}