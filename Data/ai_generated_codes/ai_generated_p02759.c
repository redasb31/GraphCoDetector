#include <stdio.h>

int main() {
  // Declare the variable to store the number of pages
  int N;

  // Read the number of pages from the input
  scanf("%d", &N);

  // Calculate the number of sheets needed
  // If the number of pages is odd, we need an extra sheet for the last page
  int sheets = N / 2 + (N % 2);

  // Print the result
  printf("%d\n", sheets);

  return 0;
}