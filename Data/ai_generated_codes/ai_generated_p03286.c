#include <stdio.h>
#include <string.h>

// Function to convert an integer to its base -2 representation
char *baseNeg2(int n) {
  // Handle the base case for 0
  if (n == 0) {
    return "0";
  }

  // Create a string to store the result
  char result[32] = {0};
  int index = 0;

  // Convert the integer to base -2
  while (n != 0) {
    // Get the remainder after dividing by -2
    int remainder = n % (-2);

    // Adjust the remainder to 0 or 1
    if (remainder < 0) {
      remainder += 2;
      n += 2;
    }

    // Add the remainder to the result string
    result[index++] = '0' + remainder;

    // Divide by -2
    n /= -2;
  }

  // Reverse the result string
  int start = 0;
  int end = index - 1;
  while (start < end) {
    char temp = result[start];
    result[start] = result[end];
    result[end] = temp;
    start++;
    end--;
  }

  // Return the result string
  return result;
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%s\n", baseNeg2(N));
  return 0;
}