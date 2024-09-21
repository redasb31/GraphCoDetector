#include <stdio.h>
#include <string.h>

int main() {
  char filter[129];
  while (1) {
    scanf("%s", filter);
    if (filter[0] == '#') {
      break;
    }

    int is_idempotent = 1; // Assume idempotent until proven otherwise
    for (int i = 0; i < 128; i++) {
      // Apply the filter twice
      int first_result = filter[i];
      int second_result = filter[first_result];

      // Check if the results are the same after applying twice
      if (first_result != second_result) {
        is_idempotent = 0;
        break;
      }
    }

    if (is_idempotent) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}