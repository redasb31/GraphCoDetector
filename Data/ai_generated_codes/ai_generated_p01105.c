#include <stdio.h>
#include <string.h>

// Function to evaluate a Boolean expression
int evaluate(char *expression, int a, int b, int c, int d) {
  // Create a copy of the expression to modify
  char *exp_copy = strdup(expression);

  // Replace variables with their values
  for (int i = 0; exp_copy[i] != '\0'; i++) {
    if (exp_copy[i] == 'a') {
      exp_copy[i] = '0' + a;
    } else if (exp_copy[i] == 'b') {
      exp_copy[i] = '0' + b;
    } else if (exp_copy[i] == 'c') {
      exp_copy[i] = '0' + c;
    } else if (exp_copy[i] == 'd') {
      exp_copy[i] = '0' + d;
    }
  }

  // Evaluate the expression using a stack-based approach
  char stack[100];
  int top = -1;
  for (int i = 0; exp_copy[i] != '\0'; i++) {
    if (exp_copy[i] >= '0' && exp_copy[i] <= '1') {
      stack[++top] = exp_copy[i];
    } else if (exp_copy[i] == '-') {
      if (stack[top] == '0') {
        stack[top] = '1';
      } else {
        stack[top] = '0';
      }
    } else if (exp_copy[i] == '^') {
      int operand1 = stack[top--];
      int operand2 = stack[top--];
      stack[++top] = (operand1 == operand2) ? '0' : '1';
    } else if (exp_copy[i] == '*') {
      int operand1 = stack[top--];
      int operand2 = stack[top--];
      stack[++top] = (operand1 == '1' && operand2 == '1') ? '1' : '0';
    }
  }

  // The result is the top of the stack
  int result = stack[top];

  // Free the copy of the expression
  free(exp_copy);

  return result;
}

// Function to find the shortest equivalent expression
int shortest_expression(char *expression) {
  // Check all possible combinations of variable values
  int shortest_length = strlen(expression);
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      for (int c = 0; c <= 1; c++) {
        for (int d = 0; d <= 1; d++) {
          int result = evaluate(expression, a, b, c, d);

          // Check if the expression can be simplified
          if (result == 0) {
            shortest_length = 1;
            break;
          } else if (result == 1) {
            shortest_length = 1;
            break;
          }
        }
        if (shortest_length == 1) {
          break;
        }
      }
      if (shortest_length == 1) {
        break;
      }
    }
    if (shortest_length == 1) {
      break;
    }
  }

  return shortest_length;
}

int main() {
  char expression[17];
  while (1) {
    scanf("%s", expression);
    if (strcmp(expression, ".") == 0) {
      break;
    }
    printf("%d\n", shortest_expression(expression));
  }
  return 0;
}