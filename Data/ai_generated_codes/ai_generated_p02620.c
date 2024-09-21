#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the satisfaction on a particular day
int satisfaction(int s[][26], int t, int c) {
  int sum = 0;
  for (int j = 0; j < 26; j++) {
    sum += s[t][j] * (j == c);
  }
  return sum;
}

// Function to calculate the total satisfaction on all days
int calculate_total_satisfaction(int s[][26], int t[], int D) {
  int total_satisfaction = 0;
  for (int i = 0; i < D; i++) {
    total_satisfaction += satisfaction(s, i, t[i]);
  }
  return total_satisfaction;
}

// Function to compute the difference in satisfaction after changing the contest type on a particular day
int compute_satisfaction_diff(int s[][26], int t[], int d, int q, int D) {
  int old_satisfaction = satisfaction(s, d, t[d]);
  int new_satisfaction = satisfaction(s, d, q);
  return new_satisfaction - old_satisfaction;
}

int main() {
  int D, M;
  scanf("%d", &D);

  // Read the contest scores for each day and contest type
  int s[D][26];
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < 26; j++) {
      scanf("%d", &s[i][j]);
    }
  }

  // Read the initial contest schedule
  int t[D];
  for (int i = 0; i < D; i++) {
    scanf("%d", &t[i]);
  }

  // Read the number of queries
  scanf("%d", &M);

  // Read the queries
  int d[M], q[M];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &d[i], &q[i]);
  }

  // Calculate the initial satisfaction
  int initial_satisfaction = calculate_total_satisfaction(s, t, D);

  // Process each query
  for (int i = 0; i < M; i++) {
    // Change the contest type on the specified day
    int old_contest_type = t[d[i] - 1];
    t[d[i] - 1] = q[i];

    // Calculate the difference in satisfaction
    int satisfaction_diff = compute_satisfaction_diff(s, t, d[i] - 1, q[i], D);

    // Update the total satisfaction
    initial_satisfaction += satisfaction_diff;

    // Print the final satisfaction
    printf("%d\n", initial_satisfaction);

    // Restore the original contest type
    t[d[i] - 1] = old_contest_type;
  }
  return 0;
}