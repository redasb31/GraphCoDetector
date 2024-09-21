#include <stdio.h>
#include <string.h>

int main() {
  int N; // Number of stones
  char S[200001]; // String representing the colors of the stones

  // Input the number of stones and the string representing their colors
  scanf("%d\n", &N);
  scanf("%s", S);

  int count = 0; // Counter for the number of stones to be recolored

  // Iterate through the string
  for (int i = 0; i < N - 1; i++) {
    // If a black stone is followed by a white stone, recolor the white stone to black
    if (S[i] == '#' && S[i + 1] == '.') {
      count++;
      S[i + 1] = '#'; // Recolor the white stone to black
    }
  }

  // Print the minimum number of stones to be recolored
  printf("%d\n", count);

  return 0;
}