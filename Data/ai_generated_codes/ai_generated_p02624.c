#include <stdio.h>
#include <math.h>

// Function to calculate the sum of divisors of a number
long long sumOfDivisors(long long num) {
  long long sum = 0;
  for (long long i = 1; i <= sqrt(num); i++) {
    if (num % i == 0) {
      sum += i;
      if (i != num / i) {
        sum += num / i;
      }
    }
  }
  return sum;
}

int main() {
  long long N, result = 0;

  // Input N
  scanf("%lld", &N);

  // Calculate the sum for each number from 1 to N
  for (long long K = 1; K <= N; K++) {
    result += K * sumOfDivisors(K);
  }

  // Output the result
  printf("%lld\n", result);

  return 0;
}