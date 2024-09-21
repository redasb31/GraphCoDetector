// This code solves the problem of calculating the sum of floor((A * i + B) / M) for i from 0 to N-1.

#include <stdio.h>
#include <math.h>

// Function to calculate the sum
long long calculateSum(long long N, long long M, long long A, long long B) {
  long long sum = 0;
  // Iterate from 0 to N-1
  for (long long i = 0; i < N; i++) {
    // Calculate the floor value and add it to the sum
    sum += floor((A * i + B) / (double)M);
  }
  return sum;
}

int main() {
  // Number of test cases
  int T;
  scanf("%d", &T);

  // Process each test case
  for (int i = 0; i < T; i++) {
    // Input values for N, M, A, and B
    long long N, M, A, B;
    scanf("%lld %lld %lld %lld", &N, &M, &A, &B);
    // Calculate and print the sum
    printf("%lld\n", calculateSum(N, M, A, B));
  }
  return 0;
}