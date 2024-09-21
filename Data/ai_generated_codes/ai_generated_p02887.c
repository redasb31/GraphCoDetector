#include <stdio.h>
#include <string.h>

int main() {
  // N: Number of slimes
  int N;
  // S: String representing the colors of slimes
  char S[100005]; 

  // Read the input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Initialize the count of slimes to 1 
  // (we start with one slime and count the fusions)
  int slimes = 1; 

  // Iterate through the slimes, starting from the second one
  for (int i = 1; i < N; i++) {
    // If the current slime's color is the same as the previous slime, 
    // they will fuse, so we don't increment the slime count
    if (S[i] == S[i - 1]) {
      continue;
    } 
    // Otherwise, we have a new slime, so we increment the count
    else {
      slimes++;
    }
  }

  // Print the final number of slimes
  printf("%d\n", slimes);

  return 0;
}