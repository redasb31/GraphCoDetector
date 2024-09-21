#include <stdio.h>

// Function to find the polynomial coefficients
void find_polynomial(int p, int a[]) {
  int b[p]; // Array to store the coefficients

  // Initialize all coefficients to 0
  for (int i = 0; i < p; i++) {
    b[i] = 0;
  }

  // Iterate over each point (i, a[i])
  for (int i = 0; i < p; i++) {
    // Calculate the value of the polynomial at point i
    int f_i = 0;
    for (int j = 0; j < p; j++) {
      f_i = (f_i + b[j] * (i % p)) % p; // Modulo p for calculations
    }

    // Adjust the coefficient b[i] to match a[i]
    b[i] = (a[i] - f_i + p) % p;
  }

  // Print the coefficients
  for (int i = 0; i < p; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");
}

int main() {
  int p;
  scanf("%d", &p); // Read the prime number p

  int a[p]; // Array to store the sequence of zeros and ones
  for (int i = 0; i < p; i++) {
    scanf("%d", &a[i]); // Read the sequence
  }

  // Find the polynomial coefficients and print them
  find_polynomial(p, a);

  return 0;
}