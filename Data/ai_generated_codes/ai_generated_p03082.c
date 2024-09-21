#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int solve(int *S, int N, int X) {
  // Base case: If there are no elements left in S, we return the current number on the blackboard.
  if (N == 0) {
    return X;
  }

  long long int sum = 0;

  // Iterate through each element in S.
  for (int i = 0; i < N; i++) {
    // Create a new array S' that excludes the current element S[i].
    int *S_prime = malloc((N - 1) * sizeof(int));
    int j = 0;
    for (int k = 0; k < N; k++) {
      if (k != i) {
        S_prime[j++] = S[k];
      }
    }

    // Recursively calculate the sum for the remaining elements in S' and add it to the total sum.
    sum = (sum + solve(S_prime, N - 1, X * S[i]) % MOD) % MOD;

    // Free the memory allocated for S'.
    free(S_prime);
  }

  // Return the final sum.
  return sum;
}

int main() {
  int N, X;
  scanf("%d %d", &N, &X);

  int *S = malloc(N * sizeof(int));

  // Read the elements of S.
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }

  // Calculate and print the answer.
  printf("%lld\n", solve(S, N, X));

  // Free the memory allocated for S.
  free(S);

  return 0;
}