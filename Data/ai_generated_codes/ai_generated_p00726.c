#include <stdio.h>
#include <string.h>

// Function to uncompress a compressed genome sequence
char uncompress(char *compressed, int index) {
  int i = 0, j = 0, k = 0, num = 0;
  char uncompressed[1000000]; // Assuming maximum uncompressed length is 1 million

  // Iterate through the compressed string
  while (compressed[i] != '\0') {
    if (compressed[i] >= 'A' && compressed[i] <= 'Z') {
      // Add the letter to the uncompressed string
      uncompressed[j++] = compressed[i];
    } else if (compressed[i] >= '0' && compressed[i] <= '9') {
      // Read the number of repetitions
      num = num * 10 + (compressed[i] - '0');
    } else if (compressed[i] == '(') {
      // Recursively uncompress the nested sequence
      k = i + 1;
      while (compressed[k] != ')') {
        k++;
      }
      char sub_compressed[1000]; // Assuming maximum compressed length is 1000
      strncpy(sub_compressed, compressed + i + 1, k - i - 1);
      sub_compressed[k - i - 1] = '\0';
      for (int l = 0; l < num; l++) {
        // Uncompress the sub-sequence num times
        uncompress(sub_compressed, index);
        index++; // Update the index to account for uncompressed characters
        j = strlen(uncompressed); // Get the current length of the uncompressed string
      }
      // Update the index for the next iteration
      i = k + 1;
      num = 0;
    } else {
      // Skip the closing parenthesis
      i++;
    }
    // Increment the index for the next iteration
    i++;
  }
  // Return the character at the given index if it exists
  if (index < j) {
    return uncompressed[index];
  } else {
    return '0';
  }
}

int main() {
  char compressed[100];
  int index;

  // Read input until two zeros are encountered
  while (1) {
    scanf("%s %d", compressed, &index);
    if (compressed[0] == '0' && index == 0) {
      break;
    }
    // Uncompress the sequence and print the result
    printf("%c\n", uncompress(compressed, index));
  }
  return 0;
}