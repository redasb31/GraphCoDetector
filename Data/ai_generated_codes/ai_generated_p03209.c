#include <stdio.h>

// Function to calculate the number of patties in a level-L burger
int patties_in_level(int L) {
  // Base case: level-0 burger has 1 patty
  if (L == 0) {
    return 1;
  } else {
    // Recursive case: level-L burger has 2 patties and 2 level-(L-1) burgers
    return 2 + 2 * patties_in_level(L - 1);
  }
}

int main() {
  int N, X;

  // Read the input values
  scanf("%d %d", &N, &X);

  // Calculate the total number of patties in the level-N burger
  int total_patties = patties_in_level(N);

  // Calculate the number of patties in the bottom-most X layers
  // If X is greater than the total number of layers, print the total number of patties
  if (X > total_patties) {
    printf("%d\n", total_patties);
  } else {
    // Otherwise, print the number of patties in the bottom-most X layers
    printf("%d\n", patties_in_level(N - (total_patties - X)));
  }

  return 0;
}