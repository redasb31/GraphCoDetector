#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return (n * fact(n - 1)) % MOD;
}

long long int inv_fact(int n) {
  if (n == 0) {
    return 1;
  }
  return (inv_fact(n - 1) * (MOD + 1 - n)) % MOD;
}

long long int choose(int n, int k) {
  if (k > n || k < 0) {
    return 0;
  }
  return (fact(n) * inv_fact(k) * inv_fact(n - k)) % MOD;
}

int main() {
  int n;
  scanf("%d", &n);

  int *a = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the number of inversions for each possible value of A[i]
  long long int total_inversions = 0;
  for (int i = 1; i <= n; i++) {
    // Find the number of elements in A that are greater than or equal to i
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] >= i) {
        count++;
      }
    }
    // Calculate the number of inversions involving i
    total_inversions = (total_inversions + choose(count, 2)) % MOD;
  }

  // Multiply by the number of permutations that satisfy the condition
  long long int num_permutations = 1;
  for (int i = 1; i <= n; i++) {
    // Find the number of elements in A that are greater than or equal to i
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] >= i) {
        count++;
      }
    }
    num_permutations = (num_permutations * count) % MOD;
  }

  printf("%lld\n", (total_inversions * num_permutations) % MOD);

  free(a);
  return 0;
}