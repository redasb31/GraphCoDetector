#include <stdio.h>
#include <stdint.h>

// Function to calculate the bitwise XOR of an array of integers
uint64_t xor_array(uint64_t arr[], int n) {
  uint64_t xor_sum = 0;
  for (int i = 0; i < n; i++) {
    xor_sum ^= arr[i];
  }
  return xor_sum;
}

int main() {
  int n;
  scanf("%d", &n);

  uint64_t arr[100000]; // Array to store the input integers

  // Read the input integers
  for (int i = 0; i < n; i++) {
    scanf("%llu", &arr[i]);
  }

  // Calculate the maximum beauty by considering all possible combinations of painting
  // red and blue
  uint64_t max_beauty = 0;
  for (int i = 1; i < n; i++) {
    // Calculate the XOR of the integers painted red (from index 0 to i-1)
    uint64_t red_xor = xor_array(arr, i);
    // Calculate the XOR of the integers painted blue (from index i to n-1)
    uint64_t blue_xor = xor_array(arr + i, n - i);
    // Update the maximum beauty if the current combination is better
    max_beauty = (red_xor + blue_xor) > max_beauty ? (red_xor + blue_xor) : max_beauty;
  }

  printf("%llu\n", max_beauty); // Print the maximum beauty

  return 0;
}