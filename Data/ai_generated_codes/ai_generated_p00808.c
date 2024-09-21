#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_CONNECTIONS 2000

// Structure to represent a city
typedef struct City {
    char name[17];
    int arrivalTime[MAX_CONNECTIONS];
    int departureTime[MAX_CONNECTIONS];
    int price[MAX_CONNECTIONS];
    int numConnections;
} City;

// Structure to represent a connection
typedef struct Connection {
    char startCity[17];
    int startHour, startMinute;
    char endCity[17];
    int endHour, endMinute;
    int price;
} Connection;

// Function to compare two times
int compareTimes(int hour1, int minute1, int hour2, int minute2) {
    if (hour1 < hour2) {
        return -1;
    } else if (hour1 > hour2) {
        return 1;
    } else {
        return minute1 - minute2;
    }
}

// Function to calculate the total cost of a route
int calculateCost(City *cities, int numCities, int route[], int routeLength) {
    int cost = 0;
    for (int i = 0; i < routeLength - 1; i++) {
        int startCityIndex = -1;
        int endCityIndex = -1;
        for (int j = 0; j < numCities; j++) {
            if (strcmp(cities[j].name, route[i]) == 0) {
                startCityIndex = j;
            }
            if (strcmp(cities[j].name, route[i + 1]) == 0) {
                endCityIndex = j;
            }
        }
        if (startCityIndex == -1 || endCityIndex == -1) {
            return -1;
        }
        for (int j = 0; j < cities[startCityIndex].numConnections; j++) {
            if (strcmp(cities[startCityIndex].name, route[i]) == 0 &&
                strcmp(cities[startCityIndex].name, route[i + 1]) == 0 &&
                compareTimes(cities[startCityIndex].departureTime[j] / 100,
                            cities[startCityIndex].departureTime[j] % 100,
                            cities[endCityIndex].arrivalTime[j] / 100,
                            cities[endCityIndex].arrivalTime[j] % 100) == 0) {
                cost += cities[startCityIndex].price[j];
                break;
            }
        }
    }
    return cost;
}

// Function to find the most economical meeting point
int findCheapestMeetingPoint(City *cities, int numCities, char *startCity, char *endCity) {
    int minCost = 1000000; // Initialize with a large value
    int route[MAX_CITIES]; // Array to store the route
    int routeLength = 0; // Length of the route

    // Iterate over all possible meeting points
    for (int i = 0; i < numCities; i++) {
        // Only consider cities that have connections to both start and end cities
        if (cities[i].numConnections > 0) {
            // Check if the city has connections to both start and end cities
            int hasStartConnection = 0;
            int hasEndConnection = 0;
            for (int j = 0; j < cities[i].numConnections; j++) {
                if (strcmp(cities[i].name, startCity) == 0 &&
                    strcmp(cities[i].name, cities[i].name) == 0 &&
                    compareTimes(cities[i].departureTime[j] / 100,
                                cities[i].departureTime[j] % 100,
                                cities[i].arrivalTime[j] / 100,
                                cities[i].arrivalTime[j] % 100) == 0) {
                    hasStartConnection = 1;
                }
                if (strcmp(cities[i].name, endCity) == 0 &&
                    strcmp(cities[i].name, cities[i].name) == 0 &&
                    compareTimes(cities[i].departureTime[j] / 100,
                                cities[i].departureTime[j] % 100,
                                cities[i].arrivalTime[j] / 100,
                                cities[i].arrivalTime[j] % 100) == 0) {
                    hasEndConnection = 1;
                }
            }

            if (hasStartConnection && hasEndConnection) {
                // Find the cheapest route to the meeting point
                // From the start city to the meeting point
                int startCost = 1000000;
                for (int j = 0; j < numCities; j++) {
                    if (strcmp(cities[j].name, startCity) == 0) {
                        for (int k = 0; k < cities[j].numConnections; k++) {
                            if (strcmp(cities[j].name, startCity) == 0 &&
                                strcmp(cities[j].name, cities[i].name) == 0 &&
                                compareTimes(cities[j].departureTime[k] / 100,
                                            cities[j].departureTime[k] % 100,
                                            cities[i].arrivalTime[k] / 100,
                                            cities[i].arrivalTime[k] % 100) == 0 &&
                                compareTimes(cities[j].departureTime[k] / 100,
                                            cities[j].departureTime[k] % 100, 8, 0) >= 0 &&
                                compareTimes(cities[i].arrivalTime[k] / 100,
                                            cities[i].arrivalTime[k] % 100, 18, 0) <= 0) {
                                if (startCost > cities[j].price[k]) {
                                    startCost = cities[j].price[k];
                                }
                            }
                        }
                    }
                }
                // From the meeting point to the end city
                int endCost = 1000000;
                for (int j = 0; j < numCities; j++) {
                    if (strcmp(cities[j].name, endCity) == 0) {
                        for (int k = 0; k < cities[j].numConnections; k++) {
                            if (strcmp(cities[j].name, cities[i].name) == 0 &&
                                strcmp(cities[j].name, endCity) == 0 &&
                                compareTimes(cities[j].departureTime[k] / 100,
                                            cities[j].departureTime[k] % 100,
                                            cities[i].arrivalTime[k] / 100,
                                            cities[i].arrivalTime[k] % 100) == 0 &&
                                compareTimes(cities[j].departureTime[k] / 100,
                                            cities[j].departureTime[k] % 100, 8, 0) >= 0 &&
                                compareTimes(cities[i].arrivalTime[k] / 100,
                                            cities[i].arrivalTime[k] % 100, 18, 0) <= 0) {
                                if (endCost > cities[j].price[k]) {
                                    endCost = cities[j].price[k];
                                }
                            }
                        }
                    }
                }

                // Calculate the total cost of the route
                int totalCost = startCost + endCost;
                // If the current route is cheaper than the best route found so far
                if (totalCost < minCost) {
                    minCost = totalCost;
                }
            }
        }
    }

    // Return the minimum cost found
    return minCost;
}

int main() {
    int numConnections;
    while (scanf("%d", &numConnections) != EOF && numConnections != 0) {
        Connection connections[MAX_CONNECTIONS];
        City cities[MAX_CITIES];
        int numCities = 0;
        int cityIndex[MAX_CITIES]; // Array to store the indices of cities in the cities array

        // Read the connections from the input
        for (int i = 0; i < numConnections; i++) {
            scanf("%s %d:%d %s %d:%d %d",
                  connections[i].startCity,
                  &connections[i].startHour,
                  &connections[i].startMinute,
                  connections[i].endCity,
                  &connections[i].endHour,
                  &connections[i].endMinute,
                  &connections[i].price);
        }

        // Create a city for each unique city
        for (int i = 0; i < numConnections; i++) {
            int found = 0;
            for (int j = 0; j < numCities; j++) {
                if (strcmp(connections[i].startCity, cities[j].name) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(cities[numCities].name, connections[i].startCity);
                cities[numCities].numConnections = 0;
                cityIndex[numCities] = numCities;
                numCities++;
            }
            found = 0;
            for (int j = 0; j < numCities; j++) {
                if (strcmp(connections[i].endCity, cities[j].name) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(cities[numCities].name, connections[i].endCity);
                cities[numCities].numConnections = 0;
                cityIndex[numCities] = numCities;
                numCities++;
            }
        }

        // Add the connections to the cities
        for (int i = 0; i < numConnections; i++) {
            for (int j = 0; j < numCities; j++) {
                if (strcmp(connections[i].startCity, cities[j].name) == 0) {
                    cities[j].arrivalTime[cities[j].numConnections] = connections[i].endHour * 100 + connections[i].endMinute;
                    cities[j].departureTime[cities[j].numConnections] = connections[i].startHour * 100 + connections[i].startMinute;
                    cities[j].price[cities[j].numConnections] = connections[i].price;
                    cities[j].numConnections++;
                }
            }
        }

        // Find the cheapest meeting point
        int cheapestCost = findCheapestMeetingPoint(cities, numCities, "Hakodate", "Tokyo");

        // Print the cheapest cost
        printf("%d\n", cheapestCost);
    }

    return 0;
}