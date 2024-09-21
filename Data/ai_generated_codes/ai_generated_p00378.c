#include <stdio.h>
#include <limits.h>

int main() {
  // Input variables
  int A, B, X;

  // Read input values
  scanf("%d %d %d", &A, &B, &X);

  // Initialize minimum price to a large value
  int min_price = INT_MAX; 

  // Iterate through all possible combinations of 1-liter and 0.5-liter bottles
  for (int i = 0; i <= X; i++) {
    for (int j = 0; j <= X; j++) {
      // Calculate total quantity and price for current combination
      int total_quantity = i * 1000 + j * 500;
      int price = i * A + j * B;

      // If total quantity is greater than or equal to the required quantity and the price is lower than the current minimum price
      if (total_quantity >= X && price < min_price) {
        min_price = price; 
      }
    }
  }

  // Print the minimum price
  printf("%d\n", min_price); 

  return 0;
}