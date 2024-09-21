#include <stdio.h>

int main() {
  int N, i;
  long long int a[100000], xor_sum = 0;

  // Read the number of heaps
  scanf("%d", &N);

  // Read the number of stones in each heap
  for (i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
    // Calculate the XOR sum of all heaps
    xor_sum ^= a[i];
  }

  // Determine the winner
  if (xor_sum == 0) {
    printf("Bob\n"); // If the initial XOR sum is 0, Bob wins
  } else {
    printf("Alice\n"); // Otherwise, Alice wins
  }

  return 0;
}