#include <stdio.h>
#include <limits.h>

#define MAX_COUNTRIES 15
#define MAX_CITIES 15
#define MAX_FLIGHTS 225

int N, K; // Number of countries and flight routes
int M[MAX_COUNTRIES]; // Number of cities in each country
int F[MAX_COUNTRIES]; // Number of international airports in each country
int flights[MAX_FLIGHTS][5]; // Flight routes and prices

// Function to check if a city has an international airport
int hasInternationalAirport(int country, int city) {
    return city <= F[country - 1];
}

// Function to find the cheapest world trip using dynamic programming
int findCheapestTrip(int currentCountry, int currentCity, int visitedCountries, int visitedCities) {
    // Base case: All countries and cities visited
    if (visitedCountries == N && visitedCities == sum(M)) {
        return 0;
    }

    // Initialize minimum price to infinity
    int minPrice = INT_MAX;

    // Iterate through all flights
    for (int i = 0; i < K; i++) {
        // Check if the flight starts from the current city and country
        if (flights[i][0] == currentCountry && flights[i][1] == currentCity) {
            // Calculate the destination country and city
            int nextCountry = flights[i][2];
            int nextCity = flights[i][3];

            // Check if the destination city has an international airport if it's a different country
            if (nextCountry != currentCountry && !hasInternationalAirport(nextCountry, nextCity)) {
                continue;
            }

            // Check if the destination country and city have been visited
            int newVisitedCountries = visitedCountries;
            int newVisitedCities = visitedCities;
            if (visitedCountries & (1 << (nextCountry - 1)) == 0) {
                newVisitedCountries |= (1 << (nextCountry - 1));
            }
            if (visitedCities & (1 << (nextCity - 1)) == 0) {
                newVisitedCities |= (1 << (nextCity - 1));
            }

            // Recursively calculate the cheapest trip from the destination city
            int price = flights[i][4] + findCheapestTrip(nextCountry, nextCity, newVisitedCountries, newVisitedCities);

            // Update the minimum price if a cheaper trip is found
            if (price < minPrice) {
                minPrice = price;
            }
        }
    }

    // Return the minimum price if a trip is possible, otherwise return -1
    return (minPrice == INT_MAX) ? -1 : minPrice;
}

// Function to calculate the sum of an array
int sum(int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Read the input
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &F[i]);
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &flights[i][j]);
        }
    }

    // Find the cheapest world trip starting from the first city in the first country
    int cheapestPrice = findCheapestTrip(1, 1, 1, 1);

    // Print the result
    printf("%d\n", cheapestPrice);

    return 0;
}