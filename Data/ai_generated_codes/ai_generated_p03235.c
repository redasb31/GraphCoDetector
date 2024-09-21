#include <stdio.h>
#include <stdlib.h>

// Function to determine if a string is a good string
int is_good_string(int *P, int N, char *S) {
  int X_high = 0; // Number of high elements in X
  int Y_high = 0; // Number of high elements in Y
  int max_X = 0;  // Maximum element in X
  int max_Y = 0;  // Maximum element in Y

  for (int i = 0; i < N; i++) {
    if (S[i] == '0') {
      // Append P[i] to X
      if (P[i] > max_X) {
        max_X = P[i];
        X_high++;
      }
    } else {
      // Append P[i] to Y
      if (P[i] > max_Y) {
        max_Y = P[i];
        Y_high++;
      }
    }
  }

  // Check if the number of high elements in X and Y are the same
  return (X_high == Y_high);
}

// Function to find the lexicographically smallest good string
char *find_smallest_good_string(int *P, int N) {
  // Allocate memory for the string S
  char *S = (char *)malloc((N + 1) * sizeof(char));
  if (S == NULL) {
    return NULL;
  }

  // Initialize S with '0's
  for (int i = 0; i < N; i++) {
    S[i] = '0';
  }
  S[N] = '\0';

  // Try all possible combinations of '0's and '1's in S
  for (int i = 0; i < (1 << N); i++) {
    // Convert the integer i to a binary string
    for (int j = 0; j < N; j++) {
      S[j] = (i & (1 << j)) ? '1' : '0';
    }

    // Check if the current string S is a good string
    if (is_good_string(P, N, S)) {
      // Return the lexicographically smallest good string
      return S;
    }
  }

  // If no good string is found, return NULL
  free(S);
  return NULL;
}

int main() {
  int N;
  scanf("%d", &N);

  // Allocate memory for the permutation P
  int *P = (int *)malloc(N * sizeof(int));
  if (P == NULL) {
    return 1;
  }

  // Read the permutation P
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }

  // Find the lexicographically smallest good string
  char *S = find_smallest_good_string(P, N);

  // Print the result
  if (S == NULL) {
    printf("-1\n");
  } else {
    printf("%s\n", S);
    free(S);
  }

  free(P);

  return 0;
}