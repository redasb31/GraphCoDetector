#include <stdio.h>

int main() {
  // N: Number of people
  // M: Number of foods
  int N, M;
  scanf("%d %d", &N, &M);

  // foods[i]: Array to store whether the (i+1)-th food is liked by all people.
  // Initially, all foods are assumed to be liked by all people.
  int foods[M];
  for (int i = 0; i < M; i++) {
    foods[i] = 1;
  }

  // Loop for each person
  for (int i = 0; i < N; i++) {
    // K_i: Number of foods the i-th person likes
    int K_i;
    scanf("%d", &K_i);

    // A_ij: j-th food liked by the i-th person
    int A_ij;
    for (int j = 0; j < K_i; j++) {
      scanf("%d", &A_ij);

      // If the i-th person doesn't like the (A_ij-1)-th food,
      // set foods[A_ij-1] to 0.
      foods[A_ij - 1] = 0;
    }
  }

  // Count the number of foods liked by all people
  int count = 0;
  for (int i = 0; i < M; i++) {
    if (foods[i] == 1) {
      count++;
    }
  }

  // Print the result
  printf("%d\n", count);

  return 0;
}