#include <stdio.h>
#include <limits.h>

int main() {
  long long A, B, C, K;
  scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

  // Perform the operation K times
  for (long long i = 0; i < K; i++) {
    // Calculate the sum of the integers that the other two people have
    long long sum_A = B + C;
    long long sum_B = A + C;
    long long sum_C = A + B;

    // Replace the current integer with the sum
    A = sum_A;
    B = sum_B;
    C = sum_C;
  }

  // Calculate the difference between Takahashi's and Nakahashi's integers
  long long difference = A - B;

  // Check if the absolute value of the difference exceeds 10^18
  if (difference > LLONG_MAX || difference < LLONG_MIN) {
    printf("Unfair\n");
  } else {
    printf("%lld\n", difference);
  }

  return 0;
}