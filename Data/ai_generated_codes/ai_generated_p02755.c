#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int A, B;

  // Read the input values
  scanf("%d %d", &A, &B);

  // Iterate through possible prices
  for (int price = 1; price <= 10000; price++) {
    // Calculate the tax for each tax rate
    int tax8 = (int)(price * 0.08); // Round down using integer cast
    int tax10 = (int)(price * 0.1);

    // Check if the calculated taxes match the input values
    if (tax8 == A && tax10 == B) {
      // If a matching price is found, print it and exit the loop
      printf("%d\n", price);
      return 0;
    }
  }

  // If no matching price is found within the range, print -1
  printf("-1\n");

  return 0;
}