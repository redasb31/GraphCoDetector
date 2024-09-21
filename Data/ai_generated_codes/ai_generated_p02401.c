#include <stdio.h>

int main() {
  int a, b;
  char op;

  // Loop to process multiple datasets
  while (1) {
    // Read the input values
    scanf("%d %c %d", &a, &op, &b);

    // Check if the operator is '?'
    if (op == '?') {
      break; // Exit the loop if the operator is '?'
    }

    // Perform the calculation based on the operator
    switch (op) {
      case '+':
        printf("%d\n", a + b);
        break;
      case '-':
        printf("%d\n", a - b);
        break;
      case '*':
        printf("%d\n", a * b);
        break;
      case '/':
        printf("%d\n", a / b); // Truncates the fractional part
        break;
    }
  }

  return 0;
}