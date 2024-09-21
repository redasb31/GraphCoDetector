#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long count_occurrences(char *A, char *B, char *C) {
  // Calculate the length of the interval
  long long interval_length = atoll(B) - atoll(A) + 1;

  // Calculate the number of occurrences of C in the interval
  long long count = 0;
  long long c_length = strlen(C);
  long long i;
  for (i = 0; i < interval_length; i++) {
    // Check if the current number in the interval contains C
    char current_number[5000];
    sprintf(current_number, "%lld", atoll(A) + i);
    if (strstr(current_number, C) != NULL) {
      count++;
    }
  }

  return count % MOD;
}

int main() {
  char A[5000], B[5000], C[5000];

  // Read the input
  scanf("%s %s %s", A, B, C);

  // Calculate the number of occurrences of C in the interval
  long long result = count_occurrences(A, B, C);

  // Print the result
  printf("%lld\n", result);

  return 0;
}