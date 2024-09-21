#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000000
#define MAX_M 3000

int main() {
  // Input variables
  long long N, M, K; // Number of stations, express train stops, semiexpress train stops
  long long A, B, C; // Travel time for local, express, and semiexpress trains
  long long T; // Maximum travel time
  long long S[MAX_M]; // Stations where express train stops

  // Read input
  scanf("%lld %lld %lld", &N, &M, &K);
  scanf("%lld %lld %lld", &A, &B, &C);
  scanf("%lld", &T);
  for (long long i = 0; i < M; i++) {
    scanf("%lld", &S[i]);
  }

  // Calculate the maximum number of stations reachable within T minutes
  long long max_stations = 0; // Initialize maximum stations to 0
  long long current_station = 1; // Initialize current station to 1
  long long current_time = 0; // Initialize current time to 0
  long long express_stop = 0; // Initialize express stop index to 0

  // Iterate through all stations
  while (current_station < N) {
    // If the current station is an express stop, use express train
    if (express_stop < M && S[express_stop] == current_station) {
      // Update time for express train travel
      current_time += B;
      // Update express stop index
      express_stop++;
    } else {
      // Check if we can reach the next station within the time limit
      if (current_time + C <= T) {
        // Update time for semiexpress train travel
        current_time += C;
        // Update current station
        current_station++;
        // Update max stations count
        max_stations++;
      } else {
        // Check if we can reach the next station using local train
        if (current_time + A <= T) {
          // Update time for local train travel
          current_time += A;
          // Update current station
          current_station++;
          // Update max stations count
          max_stations++;
        } else {
          // We cannot reach any more stations within the time limit
          break;
        }
      }
    }
  }

  // Output the maximum number of stations
  printf("%lld\n", max_stations);

  return 0;
}