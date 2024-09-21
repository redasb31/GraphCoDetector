#include <stdio.h>
#include <string.h>

// Function to calculate the remainder of two big integers
int big_int_remainder(char *a, char *b) {
  // Check if the divisor is zero
  if (b[0] == '0' && strlen(b) == 1) {
    return -1; // Indicate an error
  }

  // Initialize the remainder to the dividend
  char *remainder = a;
  int remainder_len = strlen(a);

  // Loop until the remainder is smaller than the divisor
  while (remainder_len >= strlen(b)) {
    // Find the largest multiple of the divisor that is smaller than the remainder
    int multiple = 0;
    while (compare_big_int(multiply_big_int(b, multiple), remainder) <= 0) {
      multiple++;
    }
    multiple--;

    // Subtract the multiple of the divisor from the remainder
    char *temp = subtract_big_int(remainder, multiply_big_int(b, multiple));
    free(remainder);
    remainder = temp;
    remainder_len = strlen(remainder);
  }

  // Return the remainder
  return atoi(remainder);
}

// Function to multiply two big integers
char *multiply_big_int(char *a, int multiplier) {
  // Allocate memory for the result
  int a_len = strlen(a);
  char *result = malloc(sizeof(char) * (a_len + 1));
  result[a_len] = '\0';

  // Multiply each digit of the first number by the multiplier
  int carry = 0;
  for (int i = a_len - 1; i >= 0; i--) {
    int product = (a[i] - '0') * multiplier + carry;
    result[i] = (product % 10) + '0';
    carry = product / 10;
  }

  // Add any remaining carry
  if (carry > 0) {
    result = insert_digit(result, carry, 0);
  }

  return result;
}

// Function to subtract two big integers
char *subtract_big_int(char *a, char *b) {
  // Ensure that the first number is larger than the second number
  if (compare_big_int(a, b) < 0) {
    char *temp = a;
    a = b;
    b = temp;
  }

  // Allocate memory for the result
  int a_len = strlen(a);
  int b_len = strlen(b);
  char *result = malloc(sizeof(char) * (a_len + 1));
  result[a_len] = '\0';

  // Subtract each digit of the second number from the corresponding digit of the first number
  int borrow = 0;
  for (int i = a_len - 1, j = b_len - 1; i >= 0 && j >= 0; i--, j--) {
    int difference = (a[i] - '0') - (b[j] - '0') - borrow;
    if (difference < 0) {
      difference += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result[i] = difference + '0';
  }

  // Subtract remaining digits of the first number
  for (int i = b_len - 1; i >= 0; i--) {
    int difference = (a[i] - '0') - borrow;
    if (difference < 0) {
      difference += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result[i] = difference + '0';
  }

  // Remove leading zeros
  while (result[0] == '0' && strlen(result) > 1) {
    result = remove_leading_zero(result);
  }

  return result;
}

// Function to compare two big integers
int compare_big_int(char *a, char *b) {
  // Compare the lengths of the two numbers
  int a_len = strlen(a);
  int b_len = strlen(b);
  if (a_len > b_len) {
    return 1;
  } else if (a_len < b_len) {
    return -1;
  }

  // Compare the digits of the two numbers
  for (int i = 0; i < a_len; i++) {
    if (a[i] > b[i]) {
      return 1;
    } else if (a[i] < b[i]) {
      return -1;
    }
  }

  // The two numbers are equal
  return 0;
}

// Function to insert a digit at a specific index in a string
char *insert_digit(char *str, int digit, int index) {
  // Allocate memory for the new string
  int len = strlen(str);
  char *new_str = malloc(sizeof(char) * (len + 2));
  new_str[len + 1] = '\0';

  // Copy the existing string up to the index
  for (int i = 0; i < index; i++) {
    new_str[i] = str[i];
  }

  // Insert the new digit
  new_str[index] = digit + '0';

  // Copy the remaining part of the string
  for (int i = index; i < len; i++) {
    new_str[i + 1] = str[i];
  }

  free(str);

  return new_str;
}

// Function to remove leading zeros from a string
char *remove_leading_zero(char *str) {
  // Allocate memory for the new string
  int len = strlen(str);
  char *new_str = malloc(sizeof(char) * (len + 1));
  new_str[len] = '\0';

  // Copy the string without leading zeros
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != '0' || i == len - 1) {
      new_str[j++] = str[i];
    }
  }

  free(str);

  return new_str;
}

int main() {
  // Read the two integers as strings
  char a[1001], b[1001];
  scanf("%s %s", a, b);

  // Calculate the remainder
  int remainder = big_int_remainder(a, b);

  // Print the remainder
  if (remainder == -1) {
    printf("Error: Divisor is zero.\n");
  } else {
    printf("%d\n", remainder);
  }

  return 0;
}