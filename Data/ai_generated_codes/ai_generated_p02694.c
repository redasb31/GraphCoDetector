#include <stdio.h>

int main() {
  // Declare the variable to store the target amount
  long long X;

  // Read the target amount from the standard input
  scanf("%lld", &X);

  // Initialize the balance and year counter
  long long balance = 100;
  int years = 0;

  // Loop until the balance reaches or exceeds the target amount
  while (balance < X) {
    // Calculate the interest for the current year
    balance += balance / 100;
    // Increment the year counter
    years++;
  }

  // Print the number of years
  printf("%d\n", years);

  return 0;
}