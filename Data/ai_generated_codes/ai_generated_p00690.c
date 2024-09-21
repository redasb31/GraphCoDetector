#include <stdio.h>
#include <stdlib.h>

#define MAX_STATIONS 10
#define MAX_ROUTES 20

// Structure to represent a station
typedef struct {
    int name;
    int connected_stations[4]; // Array to store connected stations
    int connected_routes[4];  // Array to store distances to connected stations
    int num_connections; // Number of connections
} Station;

// Structure to represent a route
typedef struct {
    int start;
    int end;
    int distance;
} Route;

// Function to find the longest path using Depth-First Search (DFS)
int findLongestPath(Station stations[], Route routes[], int num_stations, int num_routes, int start, int visited[], int current_path_length, int* max_path_length, int* path) {
    // Mark the current station as visited
    visited[start] = 1;

    // Iterate through all connections of the current station
    for (int i = 0; i < stations[start].num_connections; i++) {
        int next_station = stations[start].connected_stations[i];
        int route_distance = stations[start].connected_routes[i];

        // If the next station is not visited
        if (!visited[next_station]) {
            // Update current path length
            current_path_length += route_distance;

            // Add the next station to the path
            path[current_path_length / route_distance] = next_station;

            // Recursively call the function for the next station
            findLongestPath(stations, routes, num_stations, num_routes, next_station, visited, current_path_length, max_path_length, path);

            // Backtrack: remove the last station from the path
            path[current_path_length / route_distance] = 0;

            // Update current path length
            current_path_length -= route_distance;
        }
    }

    // Check if the current path length is greater than the maximum path length
    if (current_path_length > *max_path_length) {
        // Update maximum path length
        *max_path_length = current_path_length;
    }

    // Mark the current station as unvisited for future paths
    visited[start] = 0;

    return *max_path_length;
}

int main() {
    int num_stations, num_routes;
    while (1) {
        scanf("%d %d", &num_stations, &num_routes);
        
        // If input is 0 0, terminate the program
        if (num_stations == 0 && num_routes == 0) {
            break;
        }

        // Create arrays to store stations and routes
        Station stations[MAX_STATIONS];
        Route routes[MAX_ROUTES];

        // Initialize station data
        for (int i = 0; i < num_stations; i++) {
            stations[i].name = i + 1;
            stations[i].num_connections = 0;
        }

        // Read route data
        for (int i = 0; i < num_routes; i++) {
            int start, end, distance;
            scanf("%d %d %d", &start, &end, &distance);

            // Store route information
            routes[i].start = start;
            routes[i].end = end;
            routes[i].distance = distance;

            // Add connections to stations
            stations[start - 1].connected_stations[stations[start - 1].num_connections] = end - 1;
            stations[start - 1].connected_routes[stations[start - 1].num_connections] = distance;
            stations[start - 1].num_connections++;

            stations[end - 1].connected_stations[stations[end - 1].num_connections] = start - 1;
            stations[end - 1].connected_routes[stations[end - 1].num_connections] = distance;
            stations[end - 1].num_connections++;
        }

        // Find the longest path
        int max_path_length = 0;
        int path[MAX_STATIONS] = {0};
        int visited[MAX_STATIONS] = {0};
        
        // Start DFS from each station
        for (int i = 0; i < num_stations; i++) {
            findLongestPath(stations, routes, num_stations, num_routes, i, visited, 0, &max_path_length, path);
        }

        // Print the longest path length
        printf("%d\n", max_path_length);

        // Print the lexicographically least station list for the longest path
        for (int i = 0; i < MAX_STATIONS; i++) {
            if (path[i] != 0) {
                printf("%d ", path[i] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}