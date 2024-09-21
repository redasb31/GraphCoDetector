#include <stdio.h>

int main() {
  int P, N1, N5, N10, N50, N100, N500;

  // Loop through each data set
  while (1) {
    // Read input values
    scanf("%d %d %d %d %d %d %d", &P, &N1, &N5, &N10, &N50, &N100, &N500);

    // Check for end of input
    if (P == 0) {
      break;
    }

    // Initialize variables for counting coins
    int paidCoins = 0;
    int changeCoins = 0;

    // Pay with largest coins first
    while (P >= 500 && N500 > 0) {
      P -= 500;
      N500--;
      paidCoins++;
    }
    while (P >= 100 && N100 > 0) {
      P -= 100;
      N100--;
      paidCoins++;
    }
    while (P >= 50 && N50 > 0) {
      P -= 50;
      N50--;
      paidCoins++;
    }
    while (P >= 10 && N10 > 0) {
      P -= 10;
      N10--;
      paidCoins++;
    }
    while (P >= 5 && N5 > 0) {
      P -= 5;
      N5--;
      paidCoins++;
    }
    while (P >= 1 && N1 > 0) {
      P -= 1;
      N1--;
      paidCoins++;
    }

    // Calculate change coins
    changeCoins = (P >= 500) ? 1 : 0;
    P %= 500;
    changeCoins += (P >= 100) ? 1 : 0;
    P %= 100;
    changeCoins += (P >= 50) ? 1 : 0;
    P %= 50;
    changeCoins += (P >= 10) ? 1 : 0;
    P %= 10;
    changeCoins += (P >= 5) ? 1 : 0;
    P %= 5;
    changeCoins += P;

    // Print the total number of coins
    printf("%d\n", paidCoins + changeCoins);
  }

  return 0;
}