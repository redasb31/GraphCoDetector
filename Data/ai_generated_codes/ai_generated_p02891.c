#include <stdio.h>
#include <string.h>

int main() {
  // Read the input string and the number of copies.
  char s[101];
  long long k;
  scanf("%s %lld", s, &k);

  // Calculate the length of the string.
  int len = strlen(s);

  // Initialize the count of operations to 0.
  long long operations = 0;

  // Iterate through the string.
  for (int i = 0; i < len; i++) {
    // If the current character is the same as the next character, increment the operation count.
    if (s[i] == s[(i + 1) % len]) {
      operations++;
    }
  }

  // Multiply the operation count by the number of copies.
  operations *= k;

  // Output the minimum number of operations required.
  printf("%lld\n", operations);

  return 0;
}