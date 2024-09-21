#include <stdio.h>
#include <stdlib.h>

// Function to calculate the time taken to travel to a specific coordinate
long long travel_time(long long current_position, long long destination, long long L) {
  long long distance = abs(destination - current_position);
  long long time = distance;
  // If the destination is beyond the endpoint L, then the train will take a longer time to reach the destination
  if (destination > L) {
    time += 2 * (destination - L);
  }
  // If the destination is before the starting point 0, then the train will take a longer time to reach the destination
  if (destination < 0) {
    time += 2 * (-destination);
  }
  return time;
}

int main() {
  // Read the number of shopping centres and the length of the city
  int N;
  long long L;
  scanf("%d %lld", &N, &L);

  // Allocate memory for the coordinates and shopping time of each shopping centre
  long long *x = (long long *)malloc(sizeof(long long) * N);
  long long *t = (long long *)malloc(sizeof(long long) * N);

  // Read the coordinates and shopping time of each shopping centre
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lld", &t[i]);
  }

  // Initialize the current position and total time
  long long current_position = 0;
  long long total_time = 0;

  // Iterate through each shopping centre
  for (int i = 0; i < N; i++) {
    // Calculate the travel time to the current shopping centre
    long long travel_time_to_centre = travel_time(current_position, x[i], L);
    // Add the travel time to the total time
    total_time += travel_time_to_centre;
    // Add the shopping time to the total time
    total_time += t[i];
    // Update the current position to the current shopping centre
    current_position = x[i];
  }

  // Calculate the travel time back home
  long long travel_time_home = travel_time(current_position, 0, L);
  // Add the travel time back home to the total time
  total_time += travel_time_home;

  // Print the total time
  printf("%lld\n", total_time);

  // Free the allocated memory
  free(x);
  free(t);

  return 0;
}