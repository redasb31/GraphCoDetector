#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the input integers.
  int a, b;

  // Read the input integers from the user.
  scanf("%d %d", &a, &b);

  // Declare two strings to store the concatenated strings.
  char str1[10], str2[10];

  // Initialize the strings to empty strings.
  strcpy(str1, "");
  strcpy(str2, "");

  // Concatenate 'b' copies of 'a' to str1.
  for (int i = 0; i < b; i++) {
    char temp[2];
    sprintf(temp, "%d", a);
    strcat(str1, temp);
  }

  // Concatenate 'a' copies of 'b' to str2.
  for (int i = 0; i < a; i++) {
    char temp[2];
    sprintf(temp, "%d", b);
    strcat(str2, temp);
  }

  // Compare the two strings lexicographically.
  if (strcmp(str1, str2) < 0) {
    // If str1 is lexicographically smaller, print it.
    printf("%s\n", str1);
  } else {
    // If str2 is lexicographically smaller or equal, print it.
    printf("%s\n", str2);
  }

  return 0;
}