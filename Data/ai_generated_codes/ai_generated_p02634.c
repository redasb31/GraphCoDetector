#include <stdio.h>

#define MOD 998244353

// Function to calculate the factorial of a number modulo MOD
long long factorial(int n) {
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

// Function to calculate the binomial coefficient (n choose k) modulo MOD
long long binomialCoeff(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return (factorial(n) * ((factorial(k) * factorial(n - k)) % MOD)) % MOD;
}

int main() {
  int A, B, C, D;
  scanf("%d %d %d %d", &A, &B, &C, &D);

  // Calculate the number of rows and columns added
  int rowsAdded = C - A;
  int colsAdded = D - B;

  // Calculate the total number of squares added
  int totalAdded = rowsAdded + colsAdded;

  // Calculate the number of ways to choose the squares to paint black
  long long ways = binomialCoeff(totalAdded, rowsAdded);
  printf("%lld\n", ways);

  return 0;
}