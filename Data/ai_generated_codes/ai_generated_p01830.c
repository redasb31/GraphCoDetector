#include <stdio.h>

int main() {
  int N; // Number of files
  scanf("%d", &N);

  // Arrays to store file information
  char delete[1001]; // 'y' for delete, 'n' for keep
  int length[1001]; // Length of each filename

  // Input file information
  for (int i = 0; i < N; i++) {
    scanf(" %c %d", &delete[i], &length[i]);
  }

  int operations = 0; // Counter for deletion operations
  int current_length = 0; // Length of the current selection region
  int i = 0;

  // Iterate through the files
  while (i < N) {
    // If the file should be deleted
    if (delete[i] == 'y') {
      // Expand the selection region
      current_length += length[i];
      i++;

      // If the selection region is big enough to delete all files within it
      while (i < N && delete[i] == 'y' && current_length >= length[i]) {
        current_length -= length[i]; // Shrink the region
        i++; // Move to the next file
      }
      // Perform a deletion operation
      operations++;
      current_length = 0; // Reset the selection region
    } else { // File should not be deleted
      i++; // Move to the next file
    }
  }

  // Output the minimum number of deletion operations
  printf("%d\n", operations);

  return 0;
}