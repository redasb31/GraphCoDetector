#include <stdio.h>

int main() {
  // Declare a variable to store the input character
  char b;

  // Read the input character
  scanf("%c", &b);

  // Print the corresponding bonding base
  switch (b) {
    case 'A':
      printf("T\n");
      break;
    case 'C':
      printf("G\n");
      break;
    case 'G':
      printf("C\n");
      break;
    case 'T':
      printf("A\n");
      break;
  }

  return 0;
}