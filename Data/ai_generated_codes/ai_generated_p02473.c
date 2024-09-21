#include <stdio.h>
#include <string.h>

// Function to subtract two strings representing big integers
void subtractBigInt(char *a, char *b, char *result) {
  // Calculate the lengths of the input strings
  int lenA = strlen(a);
  int lenB = strlen(b);

  // Ensure a is always the larger number
  if (lenA < lenB) {
    char *temp = a;
    a = b;
    b = temp;
    int tempLen = lenA;
    lenA = lenB;
    lenB = tempLen;
  }

  // Initialize the result string with zeros
  memset(result, '0', lenA + 1);
  result[lenA] = '\0';

  // Iterate from right to left, subtracting digits
  int carry = 0;
  for (int i = lenA - 1, j = lenB - 1; j >= 0; i--, j--) {
    // Calculate the difference
    int diff = (a[i] - '0') - (b[j] - '0') - carry;

    // Handle negative differences
    if (diff < 0) {
      diff += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    // Store the difference in the result string
    result[i] = diff + '0';
  }

  // Subtract remaining digits from a
  for (int i = lenB - 1; i >= 0; i--) {
    int diff = (a[i] - '0') - carry;

    if (diff < 0) {
      diff += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result[i] = diff + '0';
  }

  // Remove leading zeros
  int i = 0;
  while (result[i] == '0' && result[i + 1] != '\0') {
    i++;
  }

  // Shift the result string
  if (i > 0) {
    strcpy(result, result + i);
  }

  // Handle negative results
  if (carry == 1) {
    result[0] = '-';
    for (i = 1; result[i] != '\0'; i++) {
      result[i] = (10 - (result[i] - '0')) + '0';
    }
  }
}

int main() {
  char a[100001];
  char b[100001];
  char result[100001];

  // Read input numbers as strings
  scanf("%s %s", a, b);

  // Subtract the numbers
  subtractBigInt(a, b, result);

  // Print the result
  printf("%s\n", result);

  return 0;
}