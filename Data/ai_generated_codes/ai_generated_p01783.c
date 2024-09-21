#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Function to check if a string represents a valid non-negative integer
int is_valid_integer(char *str) {
  if (str[0] == '0' && strlen(str) > 1) {
    return 0; // Invalid: Extra leading zeros
  }
  for (int i = 0; str[i]; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0; // Invalid: Contains non-digit characters
    }
  }
  return 1; // Valid
}

// Function to evaluate the expression, assuming it's valid
long long evaluate_expression(char *expression) {
  char *token = strtok(expression, ",");
  if (token == NULL || strcmp(token, "L") == 0) {
    return 0; // Invalid: Missing function name or "L" without arguments
  }

  long long left = atoll(token);

  token = strtok(NULL, ",");
  if (token == NULL || strcmp(token, "R") == 0) {
    return 0; // Invalid: Missing function name or "R" without arguments
  }

  long long right = atoll(token);

  if (strcmp(expression, "L(0,0)") == 0) { // Special case: "L(0,0)"
    return 0;
  }

  if (strcmp(expression, "L") != 0 && strcmp(expression, "R") != 0) {
    if (strcmp(expression, "R(0,0)") == 0) { // Special case: "R(0,0)"
      return 0;
    }

    if (strcmp(expression, "L") == 0) {
      return left;
    }
    if (strcmp(expression, "R") == 0) {
      return right;
    }
  }

  return right;
}

// Function to find the highest possible score recursively
long long find_highest_score(char *expression, int index, int depth, char *stack, int stack_top) {
  if (index == strlen(expression)) {
    if (depth == 0 && stack_top == 0) {
      // Complete expression, evaluate it
      return evaluate_expression(expression);
    } else {
      return LLONG_MIN; // Incomplete expression
    }
  }

  if (expression[index] == '?') {
    // Replace '?' with all possible characters
    long long max_score = LLONG_MIN;
    char possible_chars[] = "LR(,0123456789";
    for (int i = 0; possible_chars[i]; i++) {
      expression[index] = possible_chars[i];
      long long score = find_highest_score(expression, index + 1, depth, stack, stack_top);
      if (score > max_score) {
        max_score = score;
      }
      expression[index] = '?'; // Reset the character
    }
    return max_score;
  } else if (expression[index] == '(') {
    // Push '(' onto the stack
    stack[stack_top++] = '(';
    return find_highest_score(expression, index + 1, depth + 1, stack, stack_top);
  } else if (expression[index] == ')') {
    // Pop '(' from the stack
    if (stack_top == 0) {
      return LLONG_MIN; // Invalid: Unmatched ')'
    }
    stack_top--;
    return find_highest_score(expression, index + 1, depth - 1, stack, stack_top);
  } else if (expression[index] == ',' && depth > 0) {
    // Ignore ',' if inside a function
    return find_highest_score(expression, index + 1, depth, stack, stack_top);
  } else if (expression[index] == ',' && depth == 0) {
    // Invalid: ',' outside a function
    return LLONG_MIN;
  } else if (expression[index] >= '0' && expression[index] <= '9') {
    // Check for valid integer
    int j = index;
    while (expression[j] >= '0' && expression[j] <= '9') {
      j++;
    }
    char *substring = (char *)malloc((j - index + 1) * sizeof(char));
    strncpy(substring, &expression[index], j - index);
    substring[j - index] = '\0';
    if (!is_valid_integer(substring)) {
      free(substring);
      return LLONG_MIN; // Invalid: Contains extra leading zeros
    }
    free(substring);
    return find_highest_score(expression, j, depth, stack, stack_top);
  } else {
    // Other characters: L, R
    return find_highest_score(expression, index + 1, depth, stack, stack_top);
  }
}

int main() {
  char expression[51];
  fgets(expression, 51, stdin);
  expression[strcspn(expression, "\n")] = 0; // Remove trailing newline

  char stack[51];
  int stack_top = 0;

  long long highest_score = find_highest_score(expression, 0, 0, stack, stack_top);
  if (highest_score == LLONG_MIN) {
    printf("invalid\n");
  } else {
    printf("%lld\n", highest_score);
  }

  return 0;
}