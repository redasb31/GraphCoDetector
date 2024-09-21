#include <stdio.h>
#include <string.h>

int main() {
  int n, i, openCount = 0, closeCount = 0;
  char str[101];

  // Read the number of strings
  scanf("%d", &n);

  // Iterate through each string
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    // Count the number of opening and closing parentheses in each string
    for (int j = 0; str[j] != '\0'; j++) {
      if (str[j] == '(') {
        openCount++;
      } else {
        closeCount++;
      }
    }
  }

  // If the number of opening parentheses equals the number of closing parentheses, it is possible to make a valid string
  if (openCount == closeCount) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}