#include <stdio.h>
#include <string.h>

// Function to convert a digit in a string to its decimal value
int charToDecimal(char digit, int base) {
  if (digit >= '0' && digit <= '9') {
    return digit - '0';
  } else if (digit >= 'A' && digit <= 'Z') {
    return digit - 'A' + 10;
  } else {
    return -1; // Invalid digit
  }
}

// Function to calculate the factorial of a number
int factorial(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

// Function to count trailing zeros in the base-N representation of a number
int countTrailingZeros(int n, int base) {
  int count = 0;
  while (n > 0) {
    n /= base;
    count += n;
  }
  return count;
}

int main() {
  int base, decimalM;
  char M[13];

  while (1) {
    scanf("%d %s", &base, M);

    // Check for termination condition
    if (base == 0 && strcmp(M, "0") == 0) {
      break;
    }

    // Convert M from base-N to decimal
    decimalM = 0;
    int len = strlen(M);
    for (int i = 0; i < len; i++) {
      decimalM = decimalM * base + charToDecimal(M[i], base);
    }

    // Calculate the factorial of M
    int factM = factorial(decimalM);

    // Count trailing zeros in the base-N representation of the factorial
    int trailingZeros = countTrailingZeros(factM, base);

    printf("%d\n", trailingZeros);
  }

  return 0;
}