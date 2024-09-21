#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the result of an expression
int calculate(char *expression) {
  // Initialize a stack to store operands
  int *operandStack = (int *)malloc(sizeof(int) * 100);
  int topOperand = -1;

  // Initialize a stack to store operators
  char *operatorStack = (char *)malloc(sizeof(char) * 100);
  int topOperator = -1;

  // Iterate over the expression
  for (int i = 0; i < strlen(expression) - 1; i++) {
    char currentChar = expression[i];

    // If the current character is a digit
    if (currentChar >= '0' && currentChar <= '9') {
      // Convert the digit to an integer
      int operand = currentChar - '0';

      // Push the operand onto the operand stack
      operandStack[++topOperand] = operand;
    }

    // If the current character is an operator
    else if (currentChar == '+' || currentChar == '-' || currentChar == '*' ||
             currentChar == '/') {
      // If the operator stack is empty or the precedence of the current operator
      // is higher than the precedence of the top operator on the stack
      if (topOperator == -1 ||
          (currentChar == '*' || currentChar == '/') &&
              (operatorStack[topOperator] == '+' ||
               operatorStack[topOperator] == '-')) {
        // Push the current operator onto the operator stack
        operatorStack[++topOperator] = currentChar;
      }

      // If the precedence of the current operator is lower than or equal to the
      // precedence of the top operator on the stack
      else {
        // Pop the top operator from the stack
        char operator = operatorStack[topOperator--];

        // Calculate the result of the operation
        int result = 0;
        if (operator == '+') {
          result = operandStack[topOperand - 1] + operandStack[topOperand];
        } else if (operator == '-') {
          result = operandStack[topOperand - 1] - operandStack[topOperand];
        } else if (operator == '*') {
          result = operandStack[topOperand - 1] * operandStack[topOperand];
        } else if (operator == '/') {
          result = operandStack[topOperand - 1] / operandStack[topOperand];
        }

        // Pop the two operands from the stack
        topOperand -= 2;

        // Push the result onto the operand stack
        operandStack[++topOperand] = result;

        // Push the current operator onto the stack
        operatorStack[++topOperator] = currentChar;
      }
    }
  }

  // After processing the entire expression
  // Calculate the remaining operations on the stack
  while (topOperator != -1) {
    // Pop the top operator from the stack
    char operator = operatorStack[topOperator--];

    // Calculate the result of the operation
    int result = 0;
    if (operator == '+') {
      result = operandStack[topOperand - 1] + operandStack[topOperand];
    } else if (operator == '-') {
      result = operandStack[topOperand - 1] - operandStack[topOperand];
    } else if (operator == '*') {
      result = operandStack[topOperand - 1] * operandStack[topOperand];
    } else if (operator == '/') {
      result = operandStack[topOperand - 1] / operandStack[topOperand];
    }

    // Pop the two operands from the stack
    topOperand -= 2;

    // Push the result onto the operand stack
    operandStack[++topOperand] = result;
  }

  // The final value on the operand stack is the result of the expression
  int finalResult = operandStack[topOperand];

  // Free the memory allocated for the stacks
  free(operandStack);
  free(operatorStack);

  // Return the result
  return finalResult;
}

int main() {
  // Get the number of datasets
  int n;
  scanf("%d", &n);

  // Process each dataset
  for (int i = 0; i < n; i++) {
    // Read the expression
    char expression[101];
    scanf("%s", expression);

    // Calculate the result of the expression
    int result = calculate(expression);

    // Print the result
    printf("%d\n", result);
  }

  return 0;
}