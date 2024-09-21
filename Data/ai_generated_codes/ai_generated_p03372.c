#include <stdio.h>
#include <stdlib.h>

// Structure to store sushi information
typedef struct Sushi {
    long long int position; // Position of sushi on the counter
    long long int value;  // Nutritive value of the sushi
} Sushi;

// Function to compare two sushi by their position
int compareSushi(const void *a, const void *b) {
    Sushi *sushiA = (Sushi *)a;
    Sushi *sushiB = (Sushi *)b;
    return sushiA->position - sushiB->position;
}

// Function to calculate the maximum nutrition intake
long long int calculateMaxNutrition(Sushi *sushi, int n, long long int c) {
    // Sort sushi by their positions
    qsort(sushi, n, sizeof(Sushi), compareSushi);

    // Initialize variables for the maximum nutrition, current nutrition, and current position
    long long int maxNutrition = 0, currentNutrition = 0, currentPosition = 0;

    // Iterate over all sushi
    for (int i = 0; i < n; i++) {
        // Calculate the distance to the current sushi
        long long int distance = sushi[i].position - currentPosition;
        // Calculate the energy consumed while walking to the sushi
        long long int energyConsumed = distance;

        // If the nutrition gained from the sushi is more than the energy consumed
        if (sushi[i].value - energyConsumed > 0) {
            // Update the current nutrition
            currentNutrition += sushi[i].value - energyConsumed;
            // Update the current position
            currentPosition = sushi[i].position;
        }
        // Update the maximum nutrition
        maxNutrition = (currentNutrition > maxNutrition) ? currentNutrition : maxNutrition;
    }
    return maxNutrition;
}

int main() {
    // Read the number of sushi and the circumference of the counter
    int n;
    long long int c;
    scanf("%d %lld", &n, &c);

    // Create an array to store sushi information
    Sushi *sushi = (Sushi *)malloc(n * sizeof(Sushi));

    // Read sushi information
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &sushi[i].position, &sushi[i].value);
    }

    // Calculate the maximum nutrition intake
    long long int maxNutrition = calculateMaxNutrition(sushi, n, c);

    // Print the result
    printf("%lld\n", maxNutrition);

    // Free the allocated memory
    free(sushi);

    return 0;
}