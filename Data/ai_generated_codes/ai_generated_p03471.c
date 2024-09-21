#include <stdio.h>

int main() {
  // Read the number of bills and the total amount.
  int N, Y;
  scanf("%d %d", &N, &Y);

  // Check if the total amount is possible.
  if (Y % 1000 != 0 || N * 1000 > Y || N * 10000 < Y) {
    printf("-1 -1 -1\n");
    return 0;
  }

  // Calculate the number of 10000-yen bills.
  int x = Y / 10000;

  // If the number of bills is more than N, then it's not possible.
  if (x > N) {
    printf("-1 -1 -1\n");
    return 0;
  }

  // Calculate the remaining amount after using 10000-yen bills.
  int remaining = Y - x * 10000;

  // Calculate the number of 5000-yen bills.
  int y = remaining / 5000;

  // If the number of bills is more than N, then it's not possible.
  if (x + y > N) {
    printf("-1 -1 -1\n");
    return 0;
  }

  // Calculate the number of 1000-yen bills.
  int z = (remaining - y * 5000) / 1000;

  // Print the result.
  printf("%d %d %d\n", x, y, z);

  return 0;
}