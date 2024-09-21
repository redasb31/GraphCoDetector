#include <stdio.h>
#include <string.h>

int main() {
  // N: Number of lottery draws
  int N;
  scanf("%d", &N);

  // Array to store the kinds of items you got
  char items[200001][11]; // Maximum length of each item is 10

  // Set to store the unique kinds of items (using a set is efficient for this purpose)
  int unique_items = 0; // Initialize to 0

  // Read the items from each draw
  for (int i = 0; i < N; i++) {
    scanf("%s", items[i]);

    // Check if the item is already in the set
    int found = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(items[i], items[j]) == 0) {
        found = 1;
        break;
      }
    }

    // If the item is not in the set, add it to the set and increment unique_items
    if (!found) {
      unique_items++;
    }
  }

  // Print the number of unique kinds of items
  printf("%d\n", unique_items);

  return 0;
}