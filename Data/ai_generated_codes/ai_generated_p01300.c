#include <stdio.h>
#include <string.h>

// Function to check if a string represents a multiple of 11
int isMultipleOfEleven(char *str, int len) {
  int sumOdd = 0, sumEven = 0;
  for (int i = 0; i < len; i++) {
    if (i % 2 == 0) {
      sumEven += str[i] - '0'; // Add digits at even positions
    } else {
      sumOdd += str[i] - '0'; // Add digits at odd positions
    }
  }
  return (abs(sumEven - sumOdd) % 11 == 0); // Check if the difference is a multiple of 11
}

int main() {
  char num[80001];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0') { // End of input
      break;
    }
    int len = strlen(num);
    int count = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j <= len; j++) {
        if (isMultipleOfEleven(num + i, j - i)) { // Check if substring is a multiple of 11
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
  return 0;
}