#include <stdio.h>

int main() {
  // N: The number of slimes
  int N;
  // a: An array storing the color of each slime
  int a[100];
  // spells: The number of spells required
  int spells = 0;

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Iterate through the slimes
  for (int i = 1; i < N; i++) {
    // If the current slime has the same color as the previous slime
    if (a[i] == a[i - 1]) {
      // Increase the number of spells by 1
      spells++;
      // Change the color of the current slime to a different color
      // (We can choose any color different from the previous slime's color)
      a[i] = a[i - 1] + 1; // This ensures we don't get a color larger than 10000
    }
  }

  // Print the minimum number of spells required
  printf("%d\n", spells);

  return 0;
}