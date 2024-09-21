#include <stdio.h>
#include <stdlib.h>

// Function to find a matching pair in the card layout
int find_matching_pair(int *layout, int *pair) {
  int i, j, found = 0;
  for (i = 0; i < 19; i++) {
    // Check for adjacent cards with the same value
    for (j = i + 1; j <= i + 3 && j < 20; j++) {
      if (layout[i] == layout[j]) {
        // Found a matching pair
        pair[0] = i;
        pair[1] = j;
        found = 1;
        break;
      }
    }
    if (found) break;
  }
  return found;
}

// Function to remove a matching pair and shift remaining cards
void remove_pair(int *layout, int pair[2]) {
  int i, j;
  // Remove the matching pair
  layout[pair[0]] = -1;
  layout[pair[1]] = -1;
  // Shift remaining cards
  for (i = 0, j = 0; i < 20; i++) {
    if (layout[i] != -1) {
      layout[j] = layout[i];
      j++;
    }
  }
}

// Function to calculate the minimum penalty for a given layout
int calculate_penalty(int *layout) {
  int penalty = 0;
  int pair[2];
  // Keep removing matching pairs until none are left
  while (find_matching_pair(layout, pair)) {
    remove_pair(layout, pair);
  }
  // Count remaining cards
  for (int i = 0; i < 20; i++) {
    if (layout[i] != -1) {
      penalty++;
    }
  }
  return penalty;
}

int main() {
  int N, i;
  int layout[20];
  scanf("%d", &N);
  // Process each card layout
  for (i = 0; i < N; i++) {
    // Read the card layout
    for (int j = 0; j < 20; j++) {
      scanf("%d", &layout[j]);
    }
    // Calculate and print the minimum penalty
    printf("%d\n", calculate_penalty(layout));
  }
  return 0;
}