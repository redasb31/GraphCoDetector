#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300
#define MAX_M 5000
#define MAX_L 16

// Structure to represent a station
typedef struct {
  int station;
  int time;
} Station;

// Structure to represent an edge in the graph
typedef struct {
  int from;
  int to;
  int cost;
} Edge;

// Function to compare two stations based on their time
int compare_stations(const void *a, const void *b) {
  Station *station_a = (Station *)a;
  Station *station_b = (Station *)b;
  return station_a->time - station_b->time;
}

// Function to perform Dijkstra's algorithm to find the shortest paths from the starting station
void dijkstra(int n, Edge *edges, int m, int start, int *distances) {
  // Initialize distances to all stations as infinity
  for (int i = 0; i < n; i++) {
    distances[i] = 100000;
  }

  // Initialize the starting station's distance to 0
  distances[start - 1] = 0;

  // Create a priority queue to store stations and their distances
  Station *queue = (Station *)malloc(sizeof(Station) * n);
  int queue_size = 0;

  // Add the starting station to the priority queue
  queue[queue_size++] = (Station){start, 0};

  // Iterate until the priority queue is empty
  while (queue_size > 0) {
    // Get the station with the minimum distance
    qsort(queue, queue_size, sizeof(Station), compare_stations);
    Station current = queue[0];

    // Remove the station from the priority queue
    queue_size--;
    for (int i = 0; i < queue_size; i++) {
      queue[i] = queue[i + 1];
    }

    // Iterate over edges connected to the current station
    for (int i = 0; i < m; i++) {
      if (edges[i].from == current.station) {
        // Calculate the distance to the neighboring station
        int neighbor_distance = current.time + edges[i].cost;

        // Update the distance if the new distance is shorter
        if (neighbor_distance < distances[edges[i].to - 1]) {
          distances[edges[i].to - 1] = neighbor_distance;

          // Add the neighboring station to the priority queue
          queue[queue_size++] = (Station){edges[i].to, neighbor_distance};
        }
      }
    }
  }

  // Free the allocated memory
  free(queue);
}

int main() {
  int n, m, l, s, t;
  Edge edges[MAX_M];
  int siro_stations[MAX_L];
  int siro_times[MAX_L];
  int distances[MAX_N];

  // Read input until the end of the input is reached
  while (scanf("%d %d %d %d %d", &n, &m, &l, &s, &t) != EOF && n != 0) {
    // Read the edges connecting the stations
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
    }

    // Read the stations with SIRO restaurants and their eating times
    for (int i = 0; i < l; i++) {
      scanf("%d %d", &siro_stations[i], &siro_times[i]);
    }

    // Perform Dijkstra's algorithm to find the shortest paths from the starting station
    dijkstra(n, edges, m, s, distances);

    // Sort the SIRO stations based on their eating times
    qsort(siro_stations, l, sizeof(int), compare_stations);

    // Calculate the maximum number of SIRO restaurants that can be visited
    int max_siro = 0;
    int current_time = 0;
    for (int i = 0; i < l; i++) {
      // If the time to reach the SIRO station and eat ramen is less than the time limit
      if (current_time + distances[siro_stations[i] - 1] + siro_times[i] <= t) {
        // Increment the count of visited SIRO restaurants
        max_siro++;

        // Update the current time
        current_time += distances[siro_stations[i] - 1] + siro_times[i];
      } else {
        // Stop if the time limit is exceeded
        break;
      }
    }

    // Print the maximum number of SIRO restaurants that can be visited
    printf("%d\n", max_siro);
  }

  return 0;
}