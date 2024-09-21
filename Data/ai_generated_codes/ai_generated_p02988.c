#include <stdio.h>

int main() {
  // n is the size of the permutation
  int n;
  scanf("%d", &n);

  // p is the permutation array
  int p[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }

  // count is the number of elements that satisfy the condition
  int count = 0;

  // Iterate through the permutation from the second element to the second to last element
  for (int i = 1; i < n - 1; i++) {
    // Calculate the three numbers p_i - 1, p_i, and p_i + 1
    int prev = p[i - 1];
    int curr = p[i];
    int next = p[i + 1];

    // Check if p_i is the second smallest number among the three
    if ((curr < prev && curr < next && prev < next) || 
        (curr < prev && curr < next && next < prev) ||
        (prev < curr && prev < next && curr < next) ||
        (prev < curr && prev < next && next < curr) ||
        (next < curr && next < prev && curr < prev) ||
        (next < curr && next < prev && prev < curr)) {
      count++;
    }
  }

  // Print the count
  printf("%d\n", count);

  return 0;
}