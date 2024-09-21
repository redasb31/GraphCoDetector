#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300
#define MAX_T 100000000

int adj_matrix[MAX_N][MAX_N];
int current_state[MAX_N];
int previous_state[MAX_N];

int main() {
  int N, T;
  int i, j, k;
  int odd_count;

  // Read the number of vertices and the adjacency matrix
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &adj_matrix[i][j]);
    }
  }

  // Read the current state of the vertices
  for (i = 0; i < N; i++) {
    scanf("%d", &current_state[i]);
  }

  // Read the time T
  scanf("%d", &T);

  // Iterate through time steps backwards
  for (k = 1; k <= T; k++) {
    // Initialize previous state to all 0s
    for (i = 0; i < N; i++) {
      previous_state[i] = 0;
    }

    // Calculate previous state based on the current state
    for (i = 0; i < N; i++) {
      odd_count = 0;
      for (j = 0; j < N; j++) {
        if (adj_matrix[i][j] == 1 && current_state[j] == 1) {
          odd_count++;
        }
      }
      if (odd_count % 2 == 1) {
        previous_state[i] = 1;
      }
    }

    // Update current state with the calculated previous state
    for (i = 0; i < N; i++) {
      current_state[i] = previous_state[i];
    }
  }

  // Check for ambiguity or inconsistency
  int ambiguous = 0;
  for (i = 0; i < N; i++) {
    odd_count = 0;
    for (j = 0; j < N; j++) {
      if (adj_matrix[i][j] == 1 && previous_state[j] == 1) {
        odd_count++;
      }
    }
    if (odd_count % 2 == 1 && current_state[i] == 0) {
      ambiguous = 1;
      break;
    }
    if (odd_count % 2 == 0 && current_state[i] == 1) {
      ambiguous = 1;
      break;
    }
  }

  // Print the result
  if (ambiguous) {
    printf("ambiguous\n");
  } else {
    // Check if there is a valid state
    int valid = 1;
    for (i = 0; i < N; i++) {
      odd_count = 0;
      for (j = 0; j < N; j++) {
        if (adj_matrix[i][j] == 1 && previous_state[j] == 1) {
          odd_count++;
        }
      }
      if (odd_count % 2 == 1 && current_state[i] == 0) {
        valid = 0;
        break;
      }
      if (odd_count % 2 == 0 && current_state[i] == 1) {
        valid = 0;
        break;
      }
    }

    if (valid) {
      for (i = 0; i < N; i++) {
        printf("%d ", previous_state[i]);
      }
      printf("\n");
    } else {
      printf("none\n");
    }
  }

  return 0;
}