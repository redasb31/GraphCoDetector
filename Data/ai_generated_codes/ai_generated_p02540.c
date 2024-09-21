#include <stdio.h>
#include <stdlib.h>

// Structure to store the coordinates of a city
typedef struct {
    int x;
    int y;
} City;

// Function to compare two cities based on their x-coordinates
int compare_x(const void *a, const void *b) {
    City *city1 = (City *)a;
    City *city2 = (City *)b;
    return city1->x - city2->x;
}

// Function to compare two cities based on their y-coordinates
int compare_y(const void *a, const void *b) {
    City *city1 = (City *)a;
    City *city2 = (City *)b;
    return city1->y - city2->y;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the cities
    City *cities = (City *)malloc(sizeof(City) * N);

    // Read the coordinates of the cities
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    // Sort the cities based on their x-coordinates
    qsort(cities, N, sizeof(City), compare_x);

    // Create an array to store the reachable cities for each city
    int *reachable_cities = (int *)malloc(sizeof(int) * N);

    // Initialize reachable_cities array
    for (int i = 0; i < N; i++) {
        reachable_cities[i] = 1; // Initially, each city is reachable from itself
    }

    // Iterate through the sorted cities
    for (int i = 0; i < N; i++) {
        // Find the index of the city with the same y-coordinate but a larger x-coordinate
        int j = i + 1;
        while (j < N && cities[j].y == cities[i].y) {
            // Update the reachable cities count for the current city
            reachable_cities[i] += reachable_cities[j];
            j++;
        }
    }

    // Sort the cities based on their y-coordinates
    qsort(cities, N, sizeof(City), compare_y);

    // Iterate through the sorted cities again
    for (int i = 0; i < N; i++) {
        // Find the index of the city with the same x-coordinate but a larger y-coordinate
        int j = i + 1;
        while (j < N && cities[j].x == cities[i].x) {
            // Update the reachable cities count for the current city
            reachable_cities[i] += reachable_cities[j];
            j++;
        }
    }

    // Print the reachable cities count for each city
    for (int i = 0; i < N; i++) {
        printf("%d\n", reachable_cities[i]);
    }

    // Free allocated memory
    free(cities);
    free(reachable_cities);

    return 0;
}