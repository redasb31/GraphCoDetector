#include <stdio.h>

// Function to calculate the XOR of all possible sums of elements from two arrays
int calculateXOR(int a[], int b[], int n) {
  int xor = 0; // Initialize the XOR value to 0

  // Iterate through each element in the first array
  for (int i = 0; i < n; i++) {
    // Iterate through each element in the second array
    for (int j = 0; j < n; j++) {
      // Calculate the sum of the current elements from both arrays
      int sum = a[i] + b[j];
      // XOR the current sum with the existing XOR value
      xor ^= sum;
    }
  }
  // Return the final XOR value
  return xor;
}

int main() {
  int n; // Length of the arrays
  printf("Enter the length of the arrays: ");
  scanf("%d", &n);

  int a[n], b[n]; // Declare arrays to store the input sequences

  printf("Enter the elements of the first array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]); // Read elements of the first array
  }

  printf("Enter the elements of the second array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]); // Read elements of the second array
  }

  // Calculate the XOR of all possible sums
  int xorResult = calculateXOR(a, b, n);

  printf("The XOR of all possible sums is: %d\n", xorResult); // Print the result

  return 0;
}