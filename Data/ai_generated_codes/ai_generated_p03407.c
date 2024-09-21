#include <stdio.h>

int main() {
  // Declare variables to store the coin values and the toy price.
  int A, B, C;

  // Read the coin values and the toy price from the user.
  scanf("%d %d %d", &A, &B, &C);

  // Calculate the total amount of money Takahashi has.
  int total_money = A + B;

  // Check if Takahashi has enough money to buy the toy.
  if (total_money >= C) {
    // If Takahashi has enough money, print "Yes".
    printf("Yes\n");
  } else {
    // If Takahashi does not have enough money, print "No".
    printf("No\n");
  }

  return 0;
}