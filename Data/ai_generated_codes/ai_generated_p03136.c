#include <stdio.h>

int main() {
  // Get the number of sides of the polygon
  int N;
  scanf("%d", &N);

  // Get the lengths of the sides
  int L[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &L[i]);
  }

  // Find the longest side
  int longest_side = L[0];
  for (int i = 1; i < N; i++) {
    if (L[i] > longest_side) {
      longest_side = L[i];
    }
  }

  // Calculate the sum of the lengths of the other sides
  int sum_other_sides = 0;
  for (int i = 0; i < N; i++) {
    if (L[i] != longest_side) {
      sum_other_sides += L[i];
    }
  }

  // Check if the longest side is strictly shorter than the sum of the other sides
  if (longest_side < sum_other_sides) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}