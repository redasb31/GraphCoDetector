#include <stdio.h>

// Function to calculate the number of possible chocolate pole patterns
int count_patterns(int l, int k) {
  // Initialize the count of possible patterns
  int count = 0;

  // Iterate through all possible thicknesses of the pole
  for (int i = 1; i <= l; i++) {
    // If the pole thickness is less than the thickness of a thick disk
    if (i < k) {
      // There are only two possible patterns:
      // - Dark-White-Dark
      // - Dark-Dark
      count += 2;
    } else {
      // If the pole thickness is greater than or equal to the thickness of a thick disk
      // There are two possible ways to start:
      // - Start with a dark disk
      // - Start with a white disk
      for (int j = 0; j < 2; j++) {
        // Initialize the current thickness of the pole
        int current_thickness = 0;
        // Initialize the flag for the last disk color
        int last_disk_color = j;

        // Iterate through all possible disks
        for (int m = 1; m <= i; m++) {
          // If the current thickness is less than the thickness of a thick disk
          if (current_thickness < k) {
            // If the last disk is dark, the next disk must be white, and vice versa
            last_disk_color = 1 - last_disk_color;
            // Add the thickness of the thin disk
            current_thickness += 1;
          } else {
            // If the current thickness is greater than or equal to the thickness of a thick disk
            // The next disk must be a thick disk, and the color depends on the last disk color
            current_thickness += k;
            last_disk_color = 1 - last_disk_color;
          }

          // If the current thickness exceeds the maximum thickness, break the loop
          if (current_thickness > i) {
            break;
          }

          // If the current thickness is equal to the maximum thickness, increment the count
          if (current_thickness == i) {
            count++;
          }
        }
      }
    }
  }

  // Return the total count of possible patterns
  return count;
}

int main() {
  // Declare the variables to store the input values
  int l, k;

  // Read the input values from the user
  scanf("%d %d", &l, &k);

  // Calculate and print the number of possible patterns
  printf("%d\n", count_patterns(l, k));

  return 0;
}