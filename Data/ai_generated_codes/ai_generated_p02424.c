#include <stdio.h>

// Function to print binary representation of a 32-bit integer
void printBinary(unsigned int num) {
  // Iterate over 32 bits from MSB to LSB
  for (int i = 31; i >= 0; i--) {
    // Print the bit value (1 or 0)
    printf("%d", (num >> i) & 1);
  }
}

int main() {
  unsigned int a, b;

  // Read input values
  scanf("%u %u", &a, &b);

  // Calculate AND, OR, and XOR operations
  unsigned int andResult = a & b;
  unsigned int orResult = a | b;
  unsigned int xorResult = a ^ b;

  // Print results in binary format
  printf("0000000000000000000000000000"); // Print leading 0s for consistency
  printBinary(andResult);
  printf("\n");
  printf("0000000000000000000000000000"); 
  printBinary(orResult);
  printf("\n");
  printf("0000000000000000000000000000");
  printBinary(xorResult);
  printf("\n");

  return 0;
}