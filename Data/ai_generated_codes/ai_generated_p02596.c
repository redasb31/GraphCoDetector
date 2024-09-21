#include <stdio.h>

int main() {
  // Declare the variable to store the input value K.
  int K;

  // Read the input value K from the user.
  scanf("%d", &K);

  // Initialize the counter variable 'i' to 1.
  int i = 1;

  // Initialize the variable 'num' to 7, representing the first element of the sequence.
  long long num = 7;

  // Loop until a multiple of K is found or the number becomes too large.
  while (num <= 1e18) { 
    // Check if the current number 'num' is a multiple of K.
    if (num % K == 0) {
      // If a multiple is found, print the position 'i' and break the loop.
      printf("%d\n", i);
      break;
    } 
    // If not a multiple, increment the position 'i' and update the number 'num'.
    i++;
    num = num * 10 + 7; 
  }

  // If the loop completes without finding a multiple of K, print -1.
  if (num > 1e18) {
    printf("-1\n");
  }

  return 0;
}