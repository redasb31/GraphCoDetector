#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
  int n;
  scanf("%d", &n);

  // Read the input sequence.
  int *a = malloc(2 * n * sizeof(int));
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i]);
  }

  // Count the number of -1s.
  int count_minus_one = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (a[i] == -1) {
      count_minus_one++;
    }
  }

  // Calculate the number of possible sequences for B.
  long long result = 1;
  for (int i = 0; i < count_minus_one; i++) {
    result = (result * (2 * n - i)) % MOD;
  }

  // Print the result.
  printf("%lld\n", result);

  free(a);
  return 0;
}