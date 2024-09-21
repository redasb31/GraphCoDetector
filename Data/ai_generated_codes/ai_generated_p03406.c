#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the factorial of n
long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return (n * factorial(n - 1)) % MOD;
}

// Function to calculate the number of permutations
// that result in Player 1 being the champion
long long countPermutations(int N, int M, int* A) {
  // Calculate the total number of permutations
  long long totalPermutations = factorial(1 << N);

  // Calculate the number of permutations where Player 1 loses
  long long losingPermutations = 0;

  // Iterate over all possible starting positions for Player 1
  for (int i = 1; i <= (1 << N); i++) {
    // Calculate the position of Player 1 after the first round
    int position = (i + 1) / 2;

    // Check if Player 1 loses in the first round
    if (i % 2 == 0 && i > 1) {
      // Check if Player 1 loses to Player i
      int j;
      for (j = 0; j < M; j++) {
        if (A[j] == i) {
          break;
        }
      }
      // If Player 1 loses to Player i
      if (j < M) {
        losingPermutations += factorial(1 << N - 1);
        losingPermutations %= MOD;
      }
    } else {
      // If Player 1 loses in the first round due to the rule
      losingPermutations += factorial(1 << N - 1);
      losingPermutations %= MOD;
    }
  }

  // Calculate the number of permutations where Player 1 wins
  long long winningPermutations = totalPermutations - losingPermutations;
  winningPermutations %= MOD;

  return winningPermutations;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Allocate memory for the array A
  int* A = (int*)malloc(M * sizeof(int));

  // Read the array A
  for (int i = 0; i < M; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate and print the answer
  long long answer = countPermutations(N, M, A);
  printf("%lld\n", answer);

  // Free the memory allocated for the array A
  free(A);

  return 0;
}