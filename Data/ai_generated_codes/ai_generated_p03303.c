#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the input string and the line width.
  char S[1001];
  int w;

  // Read the input string and the line width from the standard input.
  scanf("%s %d", S, &w);

  // Calculate the number of lines.
  int lines = strlen(S) / w;
  if (strlen(S) % w != 0) {
    lines++; // Add an extra line if there are remaining characters.
  }

  // Loop through the lines and print the first character of each line.
  for (int i = 0; i < lines; i++) {
    printf("%c", S[i * w]);
  }

  printf("\n"); // Print a newline at the end.

  return 0;
}