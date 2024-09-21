#include <stdio.h>

int main() {
  int N, M; // N: total digits, M: number of constraints
  scanf("%d %d", &N, &M);

  int s[6], c[6]; // s: positions of digits, c: corresponding values
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &s[i], &c[i]);
  }

  // Initialize the candidate number with -1
  int candidate = -1;

  // Check if any digit is fixed at the first position
  int firstDigitFixed = 0;
  for (int i = 0; i < M; i++) {
    if (s[i] == 1) {
      firstDigitFixed = 1;
      candidate = c[i];
      break;
    }
  }

  // If no digit is fixed at the first position, check for other positions
  if (!firstDigitFixed) {
    // Build the candidate number based on constraints
    for (int i = 0; i < M; i++) {
      if (candidate == -1 || s[i] > 1) {
        candidate = 0; // Initialize with 0 if no previous digit set
      }

      if (s[i] == N) { // If digit is fixed at the last position
        candidate = candidate * 10 + c[i];
      } else {
        // Adjust the number for the fixed digit at the specified position
        int power = N - s[i];
        int digit = c[i] * (int) pow(10, power);
        candidate += digit;
      }
    }
  }

  // Validate the candidate number
  if (candidate != -1) {
    // Check if the candidate number has exactly N digits
    int digits = 0;
    int temp = candidate;
    while (temp > 0) {
      temp /= 10;
      digits++;
    }

    // Check if the candidate number satisfies all constraints
    if (digits != N) {
      candidate = -1;
    } else {
      for (int i = 0; i < M; i++) {
        int digit = (candidate / (int) pow(10, N - s[i])) % 10;
        if (digit != c[i]) {
          candidate = -1;
          break;
        }
      }
    }
  }

  // Print the result
  printf("%d\n", candidate);

  return 0;
}