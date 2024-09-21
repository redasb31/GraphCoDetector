#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TICKETS 8
#define MAX_CITIES 30
#define MAX_ROADS 1000

typedef struct {
  int city1;
  int city2;
  int distance;
} Road;

typedef struct {
  int horses;
  int used;
} Ticket;

// Function to calculate the time taken for a journey
double calculate_time(int distance, int horses) {
  return (double)distance / horses;
}

// Function to find the shortest path using Dijkstra's algorithm
double find_shortest_path(int start_city, int destination_city,
                         Ticket tickets[], int num_tickets,
                         Road roads[], int num_roads,
                         int num_cities) {
  // Initialize distance array to infinity for all cities
  double distances[MAX_CITIES];
  for (int i = 0; i < num_cities; i++) {
    distances[i] = INT_MAX;
  }
  distances[start_city - 1] = 0;

  // Initialize visited array to false for all cities
  int visited[MAX_CITIES] = {0};

  // Create a priority queue to store cities and their distances
  int queue[MAX_CITIES];
  int front = 0, rear = 0;

  // Add the starting city to the queue
  queue[rear++] = start_city - 1;

  // Loop until all cities are visited or the destination is reached
  while (front < rear) {
    // Get the city with the minimum distance from the queue
    int current_city = queue[front++];
    if (current_city == destination_city - 1) {
      // Destination reached, return the minimum distance
      return distances[current_city];
    }

    // Mark the current city as visited
    visited[current_city] = 1;

    // Explore all roads connected to the current city
    for (int i = 0; i < num_roads; i++) {
      // Check if the road connects to the current city
      if (roads[i].city1 == current_city + 1 ||
          roads[i].city2 == current_city + 1) {
        // Get the other city connected by the road
        int neighbor_city = (roads[i].city1 == current_city + 1) ?
                            roads[i].city2 : roads[i].city1;

        // Find the unused ticket with the maximum number of horses
        int max_horses = 0;
        int ticket_index = -1;
        for (int j = 0; j < num_tickets; j++) {
          if (!tickets[j].used && tickets[j].horses > max_horses) {
            max_horses = tickets[j].horses;
            ticket_index = j;
          }
        }

        // Calculate the time taken to reach the neighbor city
        double time_taken = calculate_time(roads[i].distance, max_horses);

        // Update the distance to the neighbor city if a shorter path is found
        if (distances[neighbor_city - 1] >
            distances[current_city] + time_taken) {
          distances[neighbor_city - 1] =
              distances[current_city] + time_taken;

          // Add the neighbor city to the queue if it's not visited
          if (!visited[neighbor_city - 1]) {
            queue[rear++] = neighbor_city - 1;
          }
        }

        // Mark the used ticket
        if (ticket_index != -1) {
          tickets[ticket_index].used = 1;
        }
      }
    }
  }

  // Destination not reached, return "Impossible"
  return -1;
}

int main() {
  int num_tickets, num_cities, num_roads, start_city, destination_city;
  while (1) {
    // Read input data
    scanf("%d %d %d %d %d", &num_tickets, &num_cities, &num_roads,
          &start_city, &destination_city);
    if (num_tickets == 0 && num_cities == 0 && num_roads == 0 &&
        start_city == 0 && destination_city == 0) {
      break;
    }

    // Check if the input is valid
    if (num_tickets < 1 || num_tickets > MAX_TICKETS ||
        num_cities < 2 || num_cities > MAX_CITIES ||
        num_roads < 0 || num_roads > MAX_ROADS ||
        start_city < 1 || start_city > num_cities ||
        destination_city < 1 || destination_city > num_cities ||
        start_city == destination_city) {
      printf("Invalid input\n");
      continue;
    }

    // Read coach ticket information
    Ticket tickets[MAX_TICKETS];
    for (int i = 0; i < num_tickets; i++) {
      scanf("%d", &tickets[i].horses);
      tickets[i].used = 0;
    }

    // Read road network information
    Road roads[MAX_ROADS];
    for (int i = 0; i < num_roads; i++) {
      scanf("%d %d %d", &roads[i].city1, &roads[i].city2,
            &roads[i].distance);
    }

    // Calculate the shortest path and print the result
    double shortest_time = find_shortest_path(start_city, destination_city,
                                              tickets, num_tickets, roads,
                                              num_roads, num_cities);
    if (shortest_time == -1) {
      printf("Impossible\n");
    } else {
      printf("%.3f\n", shortest_time);
    }
  }

  return 0;
}