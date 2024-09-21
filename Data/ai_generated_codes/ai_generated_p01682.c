#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to evaluate the Shipura expression
long long evaluate(char *expr) {
  // Handle the case of a single number
  if (strchr(expr, 'S') == NULL && strchr(expr, '>') == NULL) {
    return atol(expr);
  }

  // Find the last occurrence of ">>"
  char *last_op = strrchr(expr, '>');
  if (last_op == NULL) {
    return evaluate(expr + 2); // Handle S<expr>
  }

  // Split the expression into two parts
  *last_op = '\0';
  long long left = evaluate(expr);
  long long right = atol(last_op + 2);
  *last_op = '>';

  // Evaluate the expression according to operator precedence
  return (left >> right);
}

// Function to calculate the square modulo MOD
long long square_mod(long long x) {
  return (x * x) % MOD;
}

// Function to evaluate the S< > function
long long S(long long x) {
  return square_mod(x);
}

int main() {
  char expr[1000000];

  while (fgets(expr, sizeof(expr), stdin) != NULL) {
    if (expr[0] == '#') {
      break;
    }

    // Remove trailing newline character
    expr[strcspn(expr, "\n")] = 0;

    // Evaluate the Shipura expression
    long long result = evaluate(expr);

    // Print the evaluated result
    printf("%lld\n", result);
  }

  return 0;
}