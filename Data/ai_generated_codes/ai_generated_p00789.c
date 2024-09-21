#include <stdio.h>

int main() {
  int amount, i, j, count;
  // Loop through each input amount until a zero is encountered
  while (1) {
    scanf("%d", &amount);
    if (amount == 0) {
      break;
    }
    count = 0; // Initialize the count of combinations
    // Iterate through all possible square coin values (1 to 17^2 = 289)
    for (i = 1; i * i <= amount; i++) {
      // Iterate through the remaining amount after using a coin with value i^2
      for (j = amount - i * i; j >= 0; j--) {
        // If the remaining amount can be paid with coins of smaller values (including 0)
        if (j % 1 == 0) {
          count++; // Increment the count of combinations
        }
      }
    }
    printf("%d\n", count);
  }
  return 0;
}