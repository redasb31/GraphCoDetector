#include <stdio.h>

// Function to calculate the grundy number of a heap
int grundy(int stones, int max_take) {
  // Base case: No stones left
  if (stones == 0) {
    return 0;
  }

  // Calculate the set of grundy numbers for possible moves
  int grundy_set[max_take + 1];
  for (int i = 1; i <= max_take && i <= stones; ++i) {
    grundy_set[i] = grundy(stones - i, max_take);
  }

  // Find the smallest non-negative integer not in the set
  int grundy_value = 0;
  while (grundy_set[grundy_value] == grundy_value) {
    grundy_value++;
  }

  return grundy_value;
}

int main() {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);

  // Calculate the grundy number for each heap
  int total_grundy = 0;
  for (int i = 0; i < N; ++i) {
    int S;
    scanf("%d", &S);
    total_grundy ^= grundy(S, A);
  }

  // Determine the winner based on the total grundy number
  if (total_grundy == 0) {
    printf("Jiro\n");
  } else {
    printf("Hanako\n");
  }

  return 0;
}