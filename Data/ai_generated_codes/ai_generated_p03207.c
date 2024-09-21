#include <stdio.h>

int main() {
  // N: the number of items
  int N;
  // p: the array to store the price of each item
  int p[10]; 
  // max_price: the highest price of the item
  int max_price = 0;
  // total_price: the total price of all items
  int total_price = 0;

  // Read the number of items from the input
  scanf("%d", &N);

  // Read the price of each item from the input
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
    // Find the highest price
    if (p[i] > max_price) {
      max_price = p[i];
    }
  }

  // Calculate the total price
  for (int i = 0; i < N; i++) {
    // Apply the discount to the highest price item
    if (p[i] == max_price) {
      total_price += p[i] / 2; 
    } else {
      // Calculate the regular price for the remaining items
      total_price += p[i]; 
    }
  }

  // Print the total price
  printf("%d\n", total_price);

  return 0;
}