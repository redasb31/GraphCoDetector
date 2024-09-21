#include <stdio.h>
#include <string.h>

int main() {
  char S[4]; // Store the input string, with an extra space for the null terminator

  // Read the input string from standard input
  scanf("%s", S);

  // Initialize the price to the base price of ramen
  int price = 700;

  // Iterate through the characters of the input string
  for (int i = 0; i < 3; i++) {
    // If the character is 'o', add 100 yen for the topping
    if (S[i] == 'o') {
      price += 100;
    }
  }

  // Print the calculated price
  printf("%d\n", price);

  return 0;
}