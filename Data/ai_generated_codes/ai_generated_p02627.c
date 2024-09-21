#include <stdio.h>

int main() {
  // Declare a character variable to store the input
  char alpha;

  // Read the input character from the user
  scanf("%c", &alpha);

  // Check if the input is uppercase or lowercase
  if (alpha >= 'A' && alpha <= 'Z') {
    // If uppercase, print 'A'
    printf("A\n");
  } else {
    // If lowercase, print 'a'
    printf("a\n");
  }

  return 0;
}