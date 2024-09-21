#include <stdio.h>
#include <stdlib.h>

// Function to check if the given schedule is valid
int isValidSchedule(int N, int **schedule, int days) {
  // Create a 2D array to store the matches played by each player on each day
  int **played = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    played[i] = (int *)calloc(days, sizeof(int));
  }

  // Iterate through each match and check if the conditions are satisfied
  for (int day = 0; day < days; day++) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (schedule[i][day] == j && schedule[j][day] == i) {
          // Check if both players are playing at most one match on this day
          if (played[i][day] || played[j][day]) {
            free(played);
            for (int k = 0; k < N; k++) {
              free(schedule[k]);
            }
            free(schedule);
            return 0;
          }
          // Mark the match as played
          played[i][day] = 1;
          played[j][day] = 1;
        }
      }
    }
  }

  // Check if all matches have been scheduled
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (played[i][j / (N - 1)] == 0) {
        free(played);
        for (int k = 0; k < N; k++) {
          free(schedule[k]);
        }
        free(schedule);
        return 0;
      }
    }
  }

  // Free the allocated memory
  free(played);
  for (int i = 0; i < N; i++) {
    free(schedule[i]);
  }
  free(schedule);
  return 1;
}

// Function to find the minimum number of days required to schedule the matches
int findMinDays(int N, int **A) {
  // Calculate the total number of matches
  int totalMatches = N * (N - 1) / 2;

  // Iterate through the possible number of days
  for (int days = 1; days <= totalMatches; days++) {
    // Create a 2D array to store the schedule
    int **schedule = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
      schedule[i] = (int *)calloc(days, sizeof(int));
    }

    // Initialize the schedule
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N - 1; j++) {
        schedule[i][j / (N - 1)] = A[i][j];
      }
    }

    // Check if the current schedule is valid
    if (isValidSchedule(N, schedule, days)) {
      // Free the allocated memory
      for (int i = 0; i < N; i++) {
        free(schedule[i]);
      }
      free(schedule);
      return days;
    }

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
      free(schedule[i]);
    }
    free(schedule);
  }

  // If no valid schedule is found, return -1
  return -1;
}

int main() {
  int N;
  scanf("%d", &N);

  // Create a 2D array to store the opponents
  int **A = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    A[i] = (int *)malloc((N - 1) * sizeof(int));
  }

  // Read the opponents from the input
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Find the minimum number of days required
  int minDays = findMinDays(N, A);

  // Print the result
  printf("%d\n", minDays);

  // Free the allocated memory
  for (int i = 0; i < N; i++) {
    free(A[i]);
  }
  free(A);

  return 0;
}