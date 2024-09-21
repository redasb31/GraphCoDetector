#include <stdio.h>
#include <stdlib.h>

// Function to calculate the intensity of bulbs after K operations
void calculate_intensity(int n, int k, int *a) {
  // Create an array to store the number of bulbs illuminating each coordinate
  int *illuminated = (int *)calloc(n + 1, sizeof(int));

  // Loop for K operations
  for (int op = 0; op < k; op++) {
    // Reset the illuminated array
    for (int i = 0; i <= n; i++) {
      illuminated[i] = 0;
    }

    // Calculate the number of bulbs illuminating each coordinate
    for (int i = 1; i <= n; i++) {
      int left = i - a[i] - 1;
      int right = i + a[i];
      // Check if the left coordinate is within the array bounds
      if (left >= 0) {
        illuminated[left]++;
      }
      // Check if the right coordinate is within the array bounds
      if (right <= n) {
        illuminated[right]++;
      }
    }

    // Update the intensity of each bulb
    for (int i = 1; i <= n; i++) {
      a[i] = illuminated[i];
    }
  }

  // Print the intensity of each bulb after K operations
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(illuminated);
}

int main() {
  int n, k;
  // Read the input values
  scanf("%d %d", &n, &k);

  // Allocate memory for the intensity array
  int *a = (int *)malloc(n * sizeof(int));

  // Read the intensity of each bulb
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate and print the intensity of each bulb after K operations
  calculate_intensity(n, k, a);

  // Free the allocated memory
  free(a);

  return 0;
}