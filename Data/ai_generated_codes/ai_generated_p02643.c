#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define MAX_K 200000

int main() {
  // Input
  int N, Q;
  scanf("%d %d", &N, &Q);

  // Array to store the ratings of infants
  int A[MAX_N];
  // Array to store the initial kindergarten of each infant
  int B[MAX_N];
  // Array to store the maximum rating in each kindergarten
  int max_rating[MAX_K + 1];
  // Array to store the number of infants in each kindergarten
  int count[MAX_K + 1];

  // Initialize the max_rating and count arrays
  for (int i = 1; i <= MAX_K; i++) {
    max_rating[i] = 0;
    count[i] = 0;
  }

  // Read the ratings and initial kindergartens of infants
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
    // Update the maximum rating and count for the initial kindergarten
    if (A[i] > max_rating[B[i]]) {
      max_rating[B[i]] = A[i];
    }
    count[B[i]]++;
  }

  // Read the transfer information
  int C[MAX_N], D[MAX_N];
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &C[i], &D[i]);
  }

  // Process each transfer
  for (int i = 0; i < Q; i++) {
    // Get the infant and kindergarten involved in the transfer
    int infant = C[i] - 1;
    int old_kindergarten = B[infant];
    int new_kindergarten = D[i];

    // Update the kindergarten of the infant
    B[infant] = new_kindergarten;

    // Update the count and maximum rating for the old and new kindergartens
    count[old_kindergarten]--;
    if (count[old_kindergarten] == 0) {
      max_rating[old_kindergarten] = 0;
    } else if (A[infant] == max_rating[old_kindergarten]) {
      // If the transferred infant had the highest rating in the old kindergarten, find the new highest rating
      max_rating[old_kindergarten] = 0;
      for (int j = 0; j < N; j++) {
        if (B[j] == old_kindergarten && A[j] > max_rating[old_kindergarten]) {
          max_rating[old_kindergarten] = A[j];
        }
      }
    }

    count[new_kindergarten]++;
    if (A[infant] > max_rating[new_kindergarten]) {
      max_rating[new_kindergarten] = A[infant];
    }

    // Find the evenness
    int evenness = max_rating[1];
    for (int j = 2; j <= MAX_K; j++) {
      if (count[j] > 0 && max_rating[j] < evenness) {
        evenness = max_rating[j];
      }
    }

    // Print the evenness
    printf("%d\n", evenness);
  }

  return 0;
}