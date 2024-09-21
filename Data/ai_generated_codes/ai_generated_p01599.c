#include <stdio.h>
#include <stdlib.h>

// Structure to represent a train
typedef struct {
    int cars; // Number of cars in the train
    int departureTime; // Departure time of the train
    int arrivalTime; // Arrival time of the train
} Train;

// Function to compare two trains based on departure time
int compareTrains(const void *a, const void *b) {
    Train *trainA = (Train *)a;
    Train *trainB = (Train *)b;
    return trainA->departureTime - trainB->departureTime;
}

int main() {
    int NAB, NBA; // Number of trains from A to B and B to A
    scanf("%d %d", &NAB, &NBA);

    // Allocate memory for trains from A to B
    Train *trainsAB = (Train *)malloc(NAB * sizeof(Train));
    if (trainsAB == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    // Allocate memory for trains from B to A
    Train *trainsBA = (Train *)malloc(NBA * sizeof(Train));
    if (trainsBA == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    // Read train information from A to B
    for (int i = 0; i < NAB; i++) {
        scanf("%d %d %d", &trainsAB[i].cars, &trainsAB[i].departureTime, &trainsAB[i].arrivalTime);
    }

    // Read train information from B to A
    for (int i = 0; i < NBA; i++) {
        scanf("%d %d %d", &trainsBA[i].cars, &trainsBA[i].departureTime, &trainsBA[i].arrivalTime);
    }

    // Sort trains from A to B based on departure time
    qsort(trainsAB, NAB, sizeof(Train), compareTrains);

    // Sort trains from B to A based on departure time
    qsort(trainsBA, NBA, sizeof(Train), compareTrains);

    // Initialize variables for tracking the maximum units transferred
    int maxUnits = 0;
    int currentUnits = 0;

    // Iterate through the trains from A to B
    for (int i = 0; i < NAB; i++) {
        // Find the latest train from B to A that departs before the current train from A to B
        int j = 0;
        while (j < NBA && trainsBA[j].departureTime <= trainsAB[i].departureTime) {
            j++;
        }

        // If a train from B to A is found, update the number of units transferred
        if (j > 0) {
            currentUnits++;
            // Update the departure time of the latest train from B to A
            trainsBA[j - 1].departureTime = trainsAB[i].arrivalTime;
        }
    }

    // Update the maximum units transferred
    maxUnits = currentUnits;

    // Free allocated memory
    free(trainsAB);
    free(trainsBA);

    // Print the maximum units transferred
    printf("%d\n", maxUnits);

    return 0;
}