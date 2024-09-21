#include <stdio.h>

int main() {
  // Declare a variable to store the price of the product.
  int price;

  // Read the price from the standard input.
  scanf("%d", &price);

  // Calculate the number of 1000-yen bills needed to pay the price.
  int num_bills = price / 1000;

  // Calculate the change received.
  int change = price - (num_bills * 1000);

  // Print the change.
  printf("%d\n", change);

  return 0;
}