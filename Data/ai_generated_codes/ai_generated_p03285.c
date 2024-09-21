#include <stdio.h>

int main() {
  int N; // The total amount of money

  // Input the total amount of money
  scanf("%d", &N);

  // Check if there is a way to buy cakes and doughnuts for exactly N dollars
  for (int i = 0; i <= N / 4; i++) { // Iterate through possible number of cakes
    for (int j = 0; j <= N / 7; j++) { // Iterate through possible number of doughnuts
      if (4 * i + 7 * j == N) { // Check if the total cost equals N
        printf("Yes\n");
        return 0;
      }
    }
  }

  // If no combination is found
  printf("No\n");
  return 0;
}