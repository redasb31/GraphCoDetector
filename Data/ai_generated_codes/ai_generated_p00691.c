#include <stdio.h>
#include <math.h>

int main() {
  int z, x, y, max_sum = 0;

  // Loop through input integers until 0 is read
  while (1) {
    scanf("%d", &z);
    if (z == 0) {
      break;
    }

    // Iterate through all possible x and y values
    for (x = 1; x <= z; x++) {
      for (y = 1; y <= z; y++) {
        // Calculate x^3 + y^3
        int sum = pow(x, 3) + pow(y, 3);
        // Update max_sum if the current sum is larger and less than z^3
        if (sum > max_sum && sum <= pow(z, 3)) {
          max_sum = sum;
        }
      }
    }

    // Output z^3 - max_sum
    printf("%d\n", pow(z, 3) - max_sum);

    // Reset max_sum for the next iteration
    max_sum = 0;
  }

  return 0;
}