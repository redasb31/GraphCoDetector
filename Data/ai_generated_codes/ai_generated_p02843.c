#include <stdio.h>

int main() {
  // Declare the variable to store the desired total price.
  int X;

  // Read the desired total price from the standard input.
  scanf("%d", &X);

  // Declare a flag to indicate whether a valid combination of items is found.
  int possible = 0;

  // Iterate over all possible combinations of items.
  for (int riceballs = 0; riceballs <= 1000000; riceballs++) {
    for (int sandwiches = 0; sandwiches <= 1000000; sandwiches++) {
      for (int cookies = 0; cookies <= 1000000; cookies++) {
        for (int cakes = 0; cakes <= 1000000; cakes++) {
          for (int candies = 0; candies <= 1000000; candies++) {
            for (int computers = 0; computers <= 1000000; computers++) {
              // Calculate the total price of the current combination.
              int total = riceballs * 100 + sandwiches * 101 + cookies * 102 + cakes * 103 + candies * 104 + computers * 105;

              // If the total price matches the desired price, set the flag to true.
              if (total == X) {
                possible = 1;
                break;
              }
            }
            // If a valid combination is found, break out of the nested loops.
            if (possible) {
              break;
            }
          }
          if (possible) {
            break;
          }
        }
        if (possible) {
          break;
        }
      }
      if (possible) {
        break;
      }
    }
    if (possible) {
      break;
    }
  }

  // Print the result based on the flag value.
  printf("%d\n", possible);

  return 0;
}