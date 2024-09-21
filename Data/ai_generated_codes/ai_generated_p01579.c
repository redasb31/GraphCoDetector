#include <stdio.h>
#include <string.h>

int main() {
  char str[100001];
  scanf("%s", str);

  int len = strlen(str);
  int count = 0;

  // Iterate over all possible substrings
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j <= len; j++) {
      // Check if removing the substring from i to j-1 results in a valid tree
      if (isValidTree(str, i, j)) {
        count++;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}

// Function to check if a string represents a valid tree
int isValidTree(char *str, int start, int end) {
  int open = 0;
  int close = 0;
  for (int i = 0; i < start; i++) {
    if (str[i] == '(') {
      open++;
    } else if (str[i] == ')') {
      close++;
    }
  }
  for (int i = end; i < strlen(str); i++) {
    if (str[i] == '(') {
      open++;
    } else if (str[i] == ')') {
      close++;
    }
  }

  // Check if the number of opening and closing parentheses are balanced
  if (open != close) {
    return 0;
  }

  // Check if the substring is a valid subtree
  int balance = 0;
  for (int i = start; i < end; i++) {
    if (str[i] == '(') {
      balance++;
    } else if (str[i] == ')') {
      balance--;
    }
    // If the balance becomes negative, it means the substring is not a valid subtree
    if (balance < 0) {
      return 0;
    }
  }

  return 1;
}