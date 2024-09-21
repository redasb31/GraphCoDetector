#include <stdio.h>
#include <limits.h>

#define MAX_TOWNS 1000
#define MAX_ROADS 1000

// Structure to represent a road
typedef struct Road {
    int u; // Starting town
    int v; // Destination town
    int e; // Experience points
    int t; // Time needed to travel
} Road;

// Structure to represent a path
typedef struct Path {
    int towns[MAX_TOWNS]; // Array of towns in the path
    int length; // Number of towns in the path
    int total_experience; // Total experience points earned
    int total_time; // Total time needed to travel
} Path;

// Function to find the shortest path from a source town to a destination town
void shortest_path(int n, Road roads[], int m, int source, int destination, int shortest_paths[][MAX_TOWNS], int shortest_times[][MAX_TOWNS]) {
    // Initialize the shortest path matrix and shortest time matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            shortest_paths[i][j] = INT_MAX;
            shortest_times[i][j] = INT_MAX;
        }
    }

    // Initialize the distance from the source town to itself
    shortest_paths[source][source] = 0;
    shortest_times[source][source] = 0;

    // Iterate over the roads
    for (int i = 0; i < m; i++) {
        // Update the shortest path and time for each road
        shortest_paths[roads[i].u][roads[i].v] = roads[i].t;
        shortest_times[roads[i].u][roads[i].v] = roads[i].t;
        shortest_paths[roads[i].v][roads[i].u] = roads[i].t;
        shortest_times[roads[i].v][roads[i].u] = roads[i].t;
    }

    // Apply Floyd-Warshall algorithm to find the shortest paths between all pairs of towns
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (shortest_paths[i][k] + shortest_paths[k][j] < shortest_paths[i][j]) {
                    shortest_paths[i][j] = shortest_paths[i][k] + shortest_paths[k][j];
                    shortest_times[i][j] = shortest_times[i][k] + shortest_times[k][j];
                }
            }
        }
    }
}

// Function to generate all possible straightforward paths from a source town to a destination town
void generate_paths(int n, Road roads[], int m, int source, int destination, int shortest_times[][MAX_TOWNS], Path paths[], int *path_count) {
    // Initialize the path array
    paths[0].towns[0] = source;
    paths[0].length = 1;
    paths[0].total_experience = 0;
    paths[0].total_time = 0;
    *path_count = 1;

    // Iterate over the paths
    for (int i = 0; i < *path_count; i++) {
        // Iterate over the roads
        for (int j = 0; j < m; j++) {
            // Check if the current town is connected to the destination town
            if (paths[i].towns[paths[i].length - 1] == roads[j].u && roads[j].v == destination) {
                // Create a new path by adding the destination town to the current path
                paths[*path_count].towns[paths[*path_count].length++] = destination;
                paths[*path_count].total_experience = paths[i].total_experience + roads[j].e;
                paths[*path_count].total_time = paths[i].total_time + roads[j].t;
                (*path_count)++;
            } else if (paths[i].towns[paths[i].length - 1] == roads[j].u && shortest_times[roads[j].v][destination] < shortest_times[paths[i].towns[paths[i].length - 1]][destination]) {
                // Create a new path by adding the next town to the current path
                paths[*path_count].towns[paths[*path_count].length++] = roads[j].v;
                paths[*path_count].total_experience = paths[i].total_experience + roads[j].e;
                paths[*path_count].total_time = paths[i].total_time + roads[j].t;
                (*path_count)++;
            }
        }
    }
}

int main() {
    int c; // Number of cases
    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        int n; // Number of towns
        int m; // Number of roads
        int s; // Starting town
        int t; // Destination town

        scanf("%d %d", &n, &m);
        scanf("%d %d", &s, &t);

        Road roads[MAX_ROADS]; // Array of roads
        int shortest_paths[MAX_TOWNS][MAX_TOWNS]; // Shortest path matrix
        int shortest_times[MAX_TOWNS][MAX_TOWNS]; // Shortest time matrix
        Path paths[MAX_TOWNS * MAX_TOWNS]; // Array of paths
        int path_count = 0; // Number of paths

        // Read the road information
        for (int j = 0; j < m; j++) {
            scanf("%d %d %d %d", &roads[j].u, &roads[j].v, &roads[j].e, &roads[j].t);
        }

        // Find the shortest paths between all pairs of towns
        shortest_path(n, roads, m, s, t, shortest_paths, shortest_times);

        // Generate all possible straightforward paths
        generate_paths(n, roads, m, s, t, shortest_times, paths, &path_count);

        // Find the path with the highest efficiency
        double highest_efficiency = 0.0;
        for (int j = 0; j < path_count; j++) {
            double efficiency = (double) paths[j].total_experience / paths[j].total_time;
            if (efficiency > highest_efficiency) {
                highest_efficiency = efficiency;
            }
        }

        // Print the highest efficiency
        printf("%.4lf\n", highest_efficiency);
    }

    return 0;
}