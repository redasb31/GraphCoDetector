#include <stdio.h>
#include <math.h>

// Function to calculate the cubic number less than or equal to n
int find_cubic(int n) {
  int i = 0;
  while (i * i * i <= n) {
    i++;
  }
  return (i - 1) * (i - 1) * (i - 1);
}

// Function to calculate the tetrahedral number less than or equal to n
int find_tetrahedral(int n) {
  int i = 0;
  while (i * (i + 1) * (i + 2) / 6 <= n) {
    i++;
  }
  return (i - 1) * (i - 1 + 1) * (i - 1 + 2) / 6;
}

int main() {
  int n;
  // Read input until a zero is encountered
  while (scanf("%d", &n) && n != 0) {
    // Find the maximum sum of cubic and tetrahedral numbers
    int max_sum = 0;
    for (int i = 0; i <= n; i++) {
      // Calculate the cubic and tetrahedral numbers for the current value of i
      int cubic_num = find_cubic(i);
      int tetrahedral_num = find_tetrahedral(n - cubic_num);
      // Update max_sum if the current sum is greater
      max_sum = (cubic_num + tetrahedral_num > max_sum) ? cubic_num + tetrahedral_num : max_sum;
    }
    // Print the maximum sum
    printf("%d\n", max_sum);
  }
  return 0;
}