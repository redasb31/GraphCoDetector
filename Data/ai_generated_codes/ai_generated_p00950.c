#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
int evaluateExpression(char *expression, char *mapping);
int countValidEquations(char *encryptedEquation);
int isOperator(char c);
int isParenthesis(char c);
int isDigit(char c);
int isLetter(char c);
int isBinaryNumber(char *number, char *mapping);

int main() {
  char encryptedEquation[32];

  // Read the encrypted equation from the input
  scanf("%s", encryptedEquation);

  // Count the number of valid equations
  int count = countValidEquations(encryptedEquation);

  // Print the count
  printf("%d\n", count);

  return 0;
}

// Function to evaluate an expression
int evaluateExpression(char *expression, char *mapping) {
  // Initialize a stack to store operands
  char *operandStack = (char *)malloc(sizeof(char) * 100);
  int operandTop = -1;

  // Iterate through the expression
  for (int i = 0; expression[i] != '\0'; i++) {
    char c = expression[i];

    // If the character is a digit
    if (isDigit(c)) {
      // Push the digit onto the operand stack
      operandStack[++operandTop] = c;
    }

    // If the character is a letter
    else if (isLetter(c)) {
      // Push the mapped digit onto the operand stack
      operandStack[++operandTop] = mapping[c];
    }

    // If the character is an operator
    else if (isOperator(c)) {
      // If the operator is a '-' (negation)
      if (c == '-') {
        // Pop the top operand from the stack
        int operand = operandStack[operandTop--];

        // Negate the operand
        operand *= -1;

        // Push the negated operand back onto the stack
        operandStack[++operandTop] = operand;
      }

      // If the operator is a '+' or '*'
      else {
        // Pop the top two operands from the stack
        int operand1 = operandStack[operandTop--];
        int operand2 = operandStack[operandTop--];

        // Perform the operation
        if (c == '+') {
          operand1 += operand2;
        } else if (c == '*') {
          operand1 *= operand2;
        }

        // Push the result back onto the stack
        operandStack[++operandTop] = operand1;
      }
    }

    // If the character is a '('
    else if (c == '(') {
      // Push the '(' onto the operand stack
      operandStack[++operandTop] = '(';
    }

    // If the character is a ')'
    else if (c == ')') {
      // Pop operands and operators from the stack until a '(' is encountered
      while (operandStack[operandTop] != '(') {
        int operand1 = operandStack[operandTop--];
        char operator = operandStack[operandTop--];
        int operand2 = operandStack[operandTop--];

        // Perform the operation
        if (operator == '+') {
          operand1 += operand2;
        } else if (operator == '*') {
          operand1 *= operand2;
        } else if (operator == '-') {
          operand1 *= -1;
        }

        // Push the result back onto the stack
        operandStack[++operandTop] = operand1;
      }

      // Pop the '(' from the stack
      operandTop--;
    }
  }

  // The top operand on the stack is the final result
  int result = operandStack[operandTop];

  // Free the operand stack
  free(operandStack);

  // Return the result
  return result;
}

// Function to count the number of valid equations
int countValidEquations(char *encryptedEquation) {
  // Create a mapping for letters to binary digits
  char mapping[256] = {0};

  // Initialize the count of valid equations
  int count = 0;

  // Iterate through all possible mappings
  for (int i = 0; i < 256; i++) {
    // If the current character is a letter
    if (isLetter(i)) {
      // Generate all possible mappings
      for (int j = 0; j < 256; j++) {
        // If the current character is a letter
        if (isLetter(j)) {
          // If the two letters are different
          if (i != j) {
            // Initialize the mapping for the two letters
            mapping[i] = '0';
            mapping[j] = '1';

            // Create a copy of the encrypted equation
            char *equation = strdup(encryptedEquation);

            // Replace letters with their corresponding digits
            for (int k = 0; equation[k] != '\0'; k++) {
              if (isLetter(equation[k])) {
                equation[k] = mapping[equation[k]];
              }
            }

            // Evaluate the left and right sides of the equation
            char *leftSide = strtok(equation, "=");
            char *rightSide = strtok(NULL, "=");

            // Check if the left and right sides are valid binary numbers
            if (isBinaryNumber(leftSide, mapping) && isBinaryNumber(rightSide, mapping)) {
              // Evaluate the expressions
              int leftResult = evaluateExpression(leftSide, mapping);
              int rightResult = evaluateExpression(rightSide, mapping);

              // If the results are equal
              if (leftResult == rightResult) {
                // Increment the count of valid equations
                count++;
              }
            }

            // Free the copy of the encrypted equation
            free(equation);
          }
        }
      }
    }
  }

  // Return the count of valid equations
  return count;
}

// Function to check if a character is an operator
int isOperator(char c) {
  return c == '+' || c == '-' || c == '*';
}

// Function to check if a character is a parenthesis
int isParenthesis(char c) {
  return c == '(' || c == ')';
}

// Function to check if a character is a digit
int isDigit(char c) {
  return c == '0' || c == '1';
}

// Function to check if a character is a letter
int isLetter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to check if a string is a valid binary number
int isBinaryNumber(char *number, char *mapping) {
  // If the number is empty
  if (number == NULL || *number == '\0') {
    return 0;
  }

  // If the number starts with '0'
  if (*number == '0') {
    return 0;
  }

  // Iterate through the number
  for (int i = 0; number[i] != '\0'; i++) {
    // If the character is not a digit or a letter
    if (!isDigit(number[i]) && !isLetter(number[i])) {
      return 0;
    }

    // If the character is a letter, check if it maps to a digit
    if (isLetter(number[i]) && mapping[number[i]] == '\0') {
      return 0;
    }
  }

  // The number is valid
  return 1;
}