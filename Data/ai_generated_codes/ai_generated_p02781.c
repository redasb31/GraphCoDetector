#include <stdio.h>
#include <string.h>

// Function to count the number of non-zero digits in a number
int countNonZeroDigits(long long num) {
  int count = 0;
  char str[100];
  sprintf(str, "%lld", num);
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != '0') {
      count++;
    }
  }
  return count;
}

int main() {
  long long N;
  int K;

  // Input N and K
  scanf("%lld %d", &N, &K);

  // Initialize count
  int count = 0;

  // Iterate through all numbers from 1 to N
  for (long long i = 1; i <= N; i++) {
    // Check if the number has exactly K non-zero digits
    if (countNonZeroDigits(i) == K) {
      count++;
    }
  }

  // Print the count
  printf("%d\n", count);

  return 0;
}