#include <stdio.h>

int main() {
  int m, f, r; // midterm, final, makeup scores

  // Loop through each student's data
  while (1) {
    scanf("%d %d %d", &m, &f, &r);

    // Check for terminal symbols
    if (m == -1 && f == -1 && r == -1) {
      break; // Exit loop if terminal symbols are encountered
    }

    // Determine the grade based on the criteria
    if (m == -1 || f == -1) {
      printf("F\n"); // Failed if either midterm or final is missing
    } else if (m + f >= 80) {
      printf("A\n");
    } else if (m + f >= 65) {
      printf("B\n");
    } else if (m + f >= 50) {
      printf("C\n");
    } else if (m + f >= 30) {
      if (r >= 50) {
        printf("C\n"); // Makeup score overrides D if >= 50
      } else {
        printf("D\n");
      }
    } else {
      printf("F\n");
    }
  }

  return 0;
}