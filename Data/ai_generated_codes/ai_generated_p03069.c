#include <stdio.h>
#include <string.h>

int main() {
  int N; // Number of stones
  char S[200001]; // String representing the colors of the stones

  // Read input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Initialize the count of stones that need to be recolored
  int recolor_count = 0;

  // Iterate through the stones
  for (int i = 0; i < N - 1; i++) {
    // If a black stone is followed by a white stone, recolor the white stone
    if (S[i] == '#' && S[i + 1] == '.') {
      recolor_count++;
    }
  }

  // Print the minimum number of stones that need to be recolored
  printf("%d\n", recolor_count);

  return 0;
}