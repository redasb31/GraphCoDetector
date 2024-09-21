#include <stdio.h>
#include <string.h>

// Function to add two big integers represented as strings
char *addBigInt(char *a, char *b) {
  // Determine the lengths of the input strings
  int lenA = strlen(a);
  int lenB = strlen(b);

  // Determine the length of the result string (maximum length + 1 for carry)
  int maxLength = (lenA > lenB) ? lenA : lenB;
  char *result = (char *)malloc(maxLength + 2); // +1 for carry, +1 for null terminator

  // Initialize carry to 0
  int carry = 0;

  // Iterate through the strings from the rightmost digit to the leftmost
  for (int i = lenA - 1, j = lenB - 1, k = maxLength; i >= 0 || j >= 0 || carry; i--, j--, k--) {
    // Get the digit values from the input strings
    int digitA = (i >= 0) ? a[i] - '0' : 0;
    int digitB = (j >= 0) ? b[j] - '0' : 0;

    // Calculate the sum and carry
    int sum = digitA + digitB + carry;
    carry = sum / 10;
    sum %= 10;

    // Store the calculated digit in the result string
    result[k] = sum + '0';
  }

  // If there's a leading zero, skip it
  if (result[0] == '0') {
    result++;
  }

  // Add null terminator
  result[maxLength + 1 - (result[0] == '0')] = '\0';

  return result;
}

int main() {
  // Input the two big integers as strings
  char a[100001], b[100001];
  scanf("%s %s", a, b);

  // Add the big integers using the addBigInt function
  char *sum = addBigInt(a, b);

  // Print the sum
  printf("%s\n", sum);

  // Free the allocated memory for the sum string
  free(sum);

  return 0;
}