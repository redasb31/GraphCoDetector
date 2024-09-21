#include <stdio.h>

// Function to calculate f(a) = a^N mod N
int f(int a, int N) {
  return (a * a) % N; // Optimization: instead of calculating a^N directly, we can use repeated squaring 
}

// Function to calculate F_k(a) for a given k and a
int F(int a, int k, int N) {
  int result = a;
  for (int i = 0; i < k; ++i) {
    result = f(result, N);
  }
  return result;
}

int main() {
  int N;
  scanf("%d", &N);

  // Check if N is a prime number (as a special case, prime numbers have F_1(a) = a)
  int isPrime = 1;
  for (int i = 2; i * i <= N; ++i) {
    if (N % i == 0) {
      isPrime = 0;
      break;
    }
  }

  int k = -1;
  if (isPrime) { // If N is prime, then k = 1
    k = 1;
  } else {
    // Check for the minimum k that satisfies F_k(a) = a for all a < N
    for (int i = 1; i <= N; ++i) {
      int found = 1;
      for (int a = 1; a < N; ++a) {
        if (F(a, i, N) != a) {
          found = 0;
          break;
        }
      }
      if (found) {
        k = i;
        break;
      }
    }
  }

  printf("%d\n", k);

  return 0;
}