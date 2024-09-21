#include <stdio.h>

int main() {
  int N; // Length of the sequences
  scanf("%d", &N);

  int a[N], b[N]; // The two integer sequences

  // Input the sequences
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  int xor = 0; // Variable to store the XOR of all the sums

  // Calculate the XOR of all possible sums
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      xor ^= (a[i] + b[j]); // XOR operation
    }
  }

  printf("%d\n", xor); // Print the final XOR

  return 0;
}