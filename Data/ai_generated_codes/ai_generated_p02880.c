#include <stdio.h>

int main() {
  // Declare a variable to store the input number
  int N;

  // Read the input number from the user
  scanf("%d", &N);

  // Iterate over all possible factors from 1 to 9
  for (int i = 1; i <= 9; i++) {
    // Check if the current factor divides the input number evenly
    if (N % i == 0) {
      // If it does, check if the other factor is also within the range 1 to 9
      if (N / i <= 9 && N / i >= 1) {
        // If both factors are within the range, print "Yes" and exit the loop
        printf("Yes\n");
        return 0;
      }
    }
  }

  // If no factors are found within the range, print "No"
  printf("No\n");
  return 0;
}