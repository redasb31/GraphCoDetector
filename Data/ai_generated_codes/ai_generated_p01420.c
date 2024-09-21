#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of a runner winning
double calculate_probability(int N, int M, int L, int* P, int* T, int* V, int runner_index) {
  // Calculate the time taken by the runner to complete the marathon without any breaks
  double total_time = (double)L / V[runner_index];

  // Calculate the probability of the runner taking a break at each resting place
  double break_probability = (double)P[runner_index] / 100;

  // Calculate the probability of the runner not taking a break at each resting place
  double no_break_probability = 1 - break_probability;

  // Calculate the probability of the runner taking a break at each resting place
  double break_probability_cumulative = 1;

  // Calculate the probability of the runner not taking a break at each resting place
  double no_break_probability_cumulative = 1;

  // Calculate the time taken by the runner to complete the marathon with breaks
  double time_with_breaks = total_time;

  // Loop through each resting place
  for (int i = 0; i < M; i++) {
    // Calculate the probability of the runner taking a break at this resting place
    break_probability_cumulative *= break_probability;

    // Calculate the probability of the runner not taking a break at this resting place
    no_break_probability_cumulative *= no_break_probability;

    // Calculate the time taken by the runner to complete the marathon with breaks
    time_with_breaks += T[runner_index] * break_probability_cumulative;
  }

  // Calculate the probability of the runner winning the marathon
  double probability_of_winning = 0;

  // Loop through each runner
  for (int i = 0; i < N; i++) {
    // Calculate the time taken by the runner to complete the marathon with breaks
    double time_with_breaks_i = (double)L / V[i];
    for (int j = 0; j < M; j++) {
      time_with_breaks_i += T[i] * pow(P[i] / 100.0, j + 1);
    }

    // If the runner is faster than the current runner, increment the probability of winning
    if (time_with_breaks_i < time_with_breaks) {
      probability_of_winning += no_break_probability_cumulative;
    } else if (time_with_breaks_i == time_with_breaks && i != runner_index) {
      // If the runner is as fast as the current runner, but not the current runner, decrease the probability of winning
      probability_of_winning -= no_break_probability_cumulative;
    }
  }

  // Return the probability of winning
  return probability_of_winning;
}

int main() {
  // Read the input data
  int N, M, L;
  scanf("%d %d %d", &N, &M, &L);

  // Allocate memory for the runner data
  int* P = malloc(N * sizeof(int));
  int* T = malloc(N * sizeof(int));
  int* V = malloc(N * sizeof(int));

  // Read the runner data
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &P[i], &T[i], &V[i]);
  }

  // Calculate the probability of winning for each runner
  for (int i = 0; i < N; i++) {
    // Calculate the probability of the runner winning
    double probability = calculate_probability(N, M, L, P, T, V, i);

    // Print the probability of winning
    printf("%.8lf\n", probability);
  }

  // Free the memory
  free(P);
  free(T);
  free(V);

  return 0;
}