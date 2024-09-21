#include <stdio.h>
#include <string.h>

// Function to evaluate a three-valued logic formula
int evaluate(char *formula, int p, int q, int r) {
  // Base cases: constants and variables
  if (strcmp(formula, "0") == 0) {
    return 0;
  } else if (strcmp(formula, "1") == 0) {
    return 1;
  } else if (strcmp(formula, "2") == 0) {
    return 2;
  } else if (strcmp(formula, "P") == 0) {
    return p;
  } else if (strcmp(formula, "Q") == 0) {
    return q;
  } else if (strcmp(formula, "R") == 0) {
    return r;
  }

  // Negation
  if (formula[0] == '-') {
    return 2 - evaluate(formula + 1, p, q, r);
  }

  // Conjunction and Disjunction
  if (formula[0] == '(') {
    int len = strlen(formula);
    char *op = strchr(formula, '*');
    if (op == NULL) {
      op = strchr(formula, '+');
    }

    // Evaluate the left and right operands
    int left = evaluate(formula + 1, p, q, r);
    int right = evaluate(op + 2, p, q, r);

    // Conjunction
    if (*op == '*') {
      if (left == 2 && right == 2) {
        return 2;
      } else {
        return 0;
      }
    }

    // Disjunction
    if (*op == '+') {
      if (left == 2 || right == 2) {
        return 2;
      } else if (left == 1 || right == 1) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  return 0; // Should never reach here
}

int main() {
  char formula[81];

  while (1) {
    scanf("%s", formula);
    if (strcmp(formula, ".") == 0) {
      break;
    }

    int count = 0;
    for (int p = 0; p <= 2; p++) {
      for (int q = 0; q <= 2; q++) {
        for (int r = 0; r <= 2; r++) {
          if (evaluate(formula, p, q, r) == 2) {
            count++;
          }
        }
      }
    }

    printf("%d\n", count);
  }

  return 0;
}