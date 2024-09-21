#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum and maximum votes for a party
void calculate_votes(int N, int M, int* S, int* min_votes, int* max_votes) {
  // Allocate memory for the number of votes each party receives
  int* votes = (int*)malloc(M * sizeof(int));
  if (votes == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // Initialize all votes to 0
  for (int i = 0; i < M; i++) {
    votes[i] = 0;
  }

  // Allocate memory for the D'Hondt values
  int* dhondt_values = (int*)malloc(N * sizeof(int));
  if (dhondt_values == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // Initialize all D'Hondt values to 0
  for (int i = 0; i < N; i++) {
    dhondt_values[i] = 0;
  }

  // Calculate the D'Hondt values
  int total_seats = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 1; j <= S[i]; j++) {
      dhondt_values[total_seats] = (votes[i] + 1) * j;
      total_seats++;
    }
    votes[i] += S[i];
  }

  // Sort the D'Hondt values in descending order
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (dhondt_values[i] < dhondt_values[j]) {
        int temp = dhondt_values[i];
        dhondt_values[i] = dhondt_values[j];
        dhondt_values[j] = temp;
      }
    }
  }

  // Calculate the minimum and maximum votes for each party
  int current_seat = 0;
  for (int i = 0; i < M; i++) {
    // Calculate the maximum votes
    max_votes[i] = votes[i];
    // Calculate the minimum votes
    while (current_seat < N && dhondt_values[current_seat] == (votes[i] + 1) * (S[i] + 1)) {
      min_votes[i]++;
      current_seat++;
    }
  }

  // Free allocated memory
  free(votes);
  free(dhondt_values);
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Allocate memory for the number of seats each party won
  int* S = (int*)malloc(M * sizeof(int));
  if (S == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // Read the number of seats each party won
  for (int i = 0; i < M; i++) {
    scanf("%d", &S[i]);
  }

  // Allocate memory for the minimum and maximum votes
  int* min_votes = (int*)malloc(M * sizeof(int));
  if (min_votes == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  int* max_votes = (int*)malloc(M * sizeof(int));
  if (max_votes == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  // Calculate the minimum and maximum votes for each party
  calculate_votes(N, M, S, min_votes, max_votes);

  // Check if there is a valid solution
  int total_seats = 0;
  for (int i = 0; i < M; i++) {
    total_seats += S[i];
  }
  if (total_seats != N) {
    printf("impossible\n");
  } else {
    // Print the minimum and maximum votes for each party
    for (int i = 0; i < M; i++) {
      printf("%d %d\n", min_votes[i], max_votes[i]);
    }
  }

  // Free allocated memory
  free(S);
  free(min_votes);
  free(max_votes);

  return 0;
}