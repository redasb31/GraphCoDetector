#include <stdio.h>
#include <string.h>

// Function to get the name of the dog with the given number
char* getDogName(long long int N) {
  // Create a buffer to store the dog's name
  char *name = malloc(100 * sizeof(char)); // Allocate enough memory for the name
  name[0] = '\0'; // Initialize the name to an empty string

  // Iterate through the alphabet
  int i = 0;
  while (N > 0) {
    // Calculate the remainder when dividing N by 26
    int remainder = N % 26;
    // If the remainder is 0, we need to subtract 1 from N to get the correct letter
    if (remainder == 0) {
      N = (N - 1) / 26;
      // Add 'z' to the name
      name[i++] = 'z';
    } else {
      // Add the corresponding letter to the name
      name[i++] = (char)(remainder + 'a' - 1);
      N /= 26;
    }
  }

  // Reverse the name to get the correct order
  int j = 0;
  int k = i - 1;
  while (j < k) {
    char temp = name[j];
    name[j] = name[k];
    name[k] = temp;
    j++;
    k--;
  }

  // Return the name
  return name;
}

int main() {
  long long int N;

  // Read the dog's number from the input
  scanf("%lld", &N);

  // Get the name of the dog
  char *dogName = getDogName(N);

  // Print the name
  printf("%s\n", dogName);

  // Free the memory allocated for the name
  free(dogName);

  return 0;
}