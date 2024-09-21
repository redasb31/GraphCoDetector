#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} City;

// Function to compare two cities based on their x-coordinate
int compare_x(const void *a, const void *b) {
    City *city1 = (City *)a;
    City *city2 = (City *)b;
    return city1->x - city2->x;
}

// Function to compare two cities based on their y-coordinate
int compare_y(const void *a, const void *b) {
    City *city1 = (City *)a;
    City *city2 = (City *)b;
    return city1->y - city2->y;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the cities
    City *cities = (City *)malloc(N * sizeof(City));
    if (cities == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    // Read the city coordinates
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    // Sort the cities based on their x-coordinate
    qsort(cities, N, sizeof(City), compare_x);

    // Calculate the cost based on x-coordinates
    long long cost_x = 0;
    for (int i = 1; i < N; i++) {
        cost_x += abs(cities[i].x - cities[i - 1].x);
    }

    // Sort the cities based on their y-coordinate
    qsort(cities, N, sizeof(City), compare_y);

    // Calculate the cost based on y-coordinates
    long long cost_y = 0;
    for (int i = 1; i < N; i++) {
        cost_y += abs(cities[i].y - cities[i - 1].y);
    }

    // Find the minimum cost
    long long min_cost = (cost_x < cost_y) ? cost_x : cost_y;

    // Print the minimum cost
    printf("%lld\n", min_cost);

    // Free the allocated memory
    free(cities);

    return 0;
}