#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a big integer
typedef struct {
  char *digits; // Array of digits of the big integer
  int size;     // Number of digits in the big integer
  int sign;     // Sign of the big integer (1 for positive, -1 for negative)
} BigInteger;

// Function to initialize a BigInteger
BigInteger* initializeBigInteger(char *str) {
  BigInteger *bi = (BigInteger*)malloc(sizeof(BigInteger));
  bi->size = strlen(str);
  bi->digits = (char*)malloc(sizeof(char) * (bi->size + 1));
  strcpy(bi->digits, str);

  // Determine the sign of the big integer
  bi->sign = (str[0] == '-') ? -1 : 1;

  // Remove the sign from the digits if it's present
  if (bi->sign == -1) {
    bi->digits++;
    bi->size--;
  }

  return bi;
}

// Function to add two BigIntegers
BigInteger* addBigIntegers(BigInteger *a, BigInteger *b) {
  // Handle cases where one of the numbers is zero
  if (a->size == 0) {
    return b;
  }
  if (b->size == 0) {
    return a;
  }

  // Determine the sign of the result
  int sign = (a->sign == b->sign) ? 1 : -1;

  // Ensure that a has the larger size
  if (a->size < b->size) {
    BigInteger *temp = a;
    a = b;
    b = temp;
  }

  // Create a new BigInteger for the result
  BigInteger *result = (BigInteger*)malloc(sizeof(BigInteger));
  result->size = a->size + 1; // Add 1 for potential carry
  result->digits = (char*)malloc(sizeof(char) * (result->size + 1));
  memset(result->digits, '0', result->size); // Initialize with zeros
  result->digits[result->size] = '\0'; // Null-terminate the string
  result->sign = sign;

  // Perform addition
  int carry = 0;
  int i;
  for (i = 0; i < b->size; i++) {
    int sum = (a->digits[i] - '0') + (b->digits[i] - '0') + carry;
    carry = sum / 10;
    result->digits[i] = (sum % 10) + '0';
  }
  // Handle remaining digits of a
  for (; i < a->size; i++) {
    int sum = (a->digits[i] - '0') + carry;
    carry = sum / 10;
    result->digits[i] = (sum % 10) + '0';
  }

  // Handle the final carry
  if (carry) {
    result->digits[result->size - 1] = carry + '0';
  } else {
    result->size--; // Adjust size if no carry
  }

  // Remove leading zeros
  while (result->size > 1 && result->digits[result->size - 1] == '0') {
    result->size--;
  }

  return result;
}

// Function to multiply two BigIntegers
BigInteger* multiplyBigIntegers(BigInteger *a, BigInteger *b) {
  // Handle cases where one of the numbers is zero
  if (a->size == 0 || b->size == 0) {
    BigInteger *result = (BigInteger*)malloc(sizeof(BigInteger));
    result->size = 0;
    result->digits = (char*)malloc(sizeof(char));
    result->digits[0] = '\0';
    result->sign = 1;
    return result;
  }

  // Determine the sign of the result
  int sign = (a->sign == b->sign) ? 1 : -1;

  // Create a new BigInteger for the result
  BigInteger *result = (BigInteger*)malloc(sizeof(BigInteger));
  result->size = a->size + b->size;
  result->digits = (char*)malloc(sizeof(char) * (result->size + 1));
  memset(result->digits, '0', result->size); // Initialize with zeros
  result->digits[result->size] = '\0'; // Null-terminate the string
  result->sign = sign;

  // Perform multiplication
  int i, j;
  for (i = 0; i < a->size; i++) {
    int carry = 0;
    for (j = 0; j < b->size; j++) {
      int product = (a->digits[i] - '0') * (b->digits[j] - '0') + carry + (result->digits[i + j] - '0');
      carry = product / 10;
      result->digits[i + j] = (product % 10) + '0';
    }
    result->digits[i + b->size] = carry + '0';
  }

  // Remove leading zeros
  while (result->size > 1 && result->digits[result->size - 1] == '0') {
    result->size--;
  }

  return result;
}

// Function to print a BigInteger
void printBigInteger(BigInteger *bi) {
  if (bi->sign == -1) {
    printf("-");
  }
  printf("%s\n", bi->digits);
}

int main() {
  char str1[200001], str2[200001];
  scanf("%s %s", str1, str2);

  // Initialize BigIntegers
  BigInteger *a = initializeBigInteger(str1);
  BigInteger *b = initializeBigInteger(str2);

  // Multiply the BigIntegers
  BigInteger *product = multiplyBigIntegers(a, b);

  // Print the product
  printBigInteger(product);

  // Free allocated memory
  free(a->digits);
  free(a);
  free(b->digits);
  free(b);
  free(product->digits);
  free(product);

  return 0;
}