#include <stdio.h>

int main() {
  // Declare variables for the number of coins (K) and the target amount (X)
  int K, X;

  // Read the number of coins (K) and the target amount (X) from the user
  scanf("%d %d", &K, &X);

  // Calculate the total value of the coins
  int totalValue = K * 500;

  // Check if the total value is greater than or equal to the target amount
  if (totalValue >= X) {
    printf("Yes\n"); // If yes, print "Yes"
  } else {
    printf("No\n"); // If no, print "No"
  }

  return 0;
}