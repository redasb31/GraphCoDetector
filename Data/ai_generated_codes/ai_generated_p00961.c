#include <stdio.h>
#include <string.h>

int main() {
  int n, k; // n: number of bricks, k: max bricks per stroke
  char s[500001], t[500001]; // s: initial colors, t: desired colors

  scanf("%d %d\n", &n, &k);
  scanf("%s\n%s", s, t);

  int strokes = 0; // Counter for brush strokes
  int i = 0;

  // Iterate through the bricks, comparing initial and desired colors
  while (i < n) {
    // If current brick needs to be repainted
    if (s[i] != t[i]) {
      // Count a stroke
      strokes++;

      // Repaint as many bricks as possible within the stroke limit
      int j = i;
      while (j < n && j < i + k && s[j] != t[j]) {
        j++;
      }

      // Update the position for the next iteration
      i = j;
    } else {
      // Skip to the next brick if no repainting is needed
      i++;
    }
  }

  // Print the minimum number of strokes
  printf("%d\n", strokes);

  return 0;
}