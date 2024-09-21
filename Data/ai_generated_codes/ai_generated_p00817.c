#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_P 300

int main() {
  int n, p1, p2;
  int x[MAX_N], y[MAX_N];
  char a[MAX_N][4];
  int divine[MAX_P + 1], devilish[MAX_P + 1];
  int i, j, k;
  int found;

  while (1) {
    // Read the input
    scanf("%d %d %d", &n, &p1, &p2);
    if (n == 0 && p1 == 0 && p2 == 0) {
      break;
    }
    for (i = 0; i < n; i++) {
      scanf("%d %d %s", &x[i], &y[i], a[i]);
    }

    // Initialize the divine and devilish arrays
    for (i = 1; i <= p1 + p2; i++) {
      divine[i] = -1; // -1 means unknown
      devilish[i] = -1;
    }

    // Process the answers
    for (i = 0; i < n; i++) {
      if (strcmp(a[i], "yes") == 0) {
        // If the answer is "yes", then:
        // - If x is divine, then y is also divine
        // - If x is devilish, then y is devilish
        if (divine[x[i]] == 1) {
          divine[y[i]] = 1;
        } else if (devilish[x[i]] == 1) {
          devilish[y[i]] = 1;
        }
      } else if (strcmp(a[i], "no") == 0) {
        // If the answer is "no", then:
        // - If x is divine, then y is devilish
        // - If x is devilish, then y is divine
        if (divine[x[i]] == 1) {
          devilish[y[i]] = 1;
        } else if (devilish[x[i]] == 1) {
          divine[y[i]] = 1;
        }
      }
    }

    // Check for contradictions
    found = 1;
    for (i = 1; i <= p1 + p2; i++) {
      if (divine[i] == 1 && devilish[i] == 1) {
        // Contradiction: A person cannot be both divine and devilish
        found = 0;
        break;
      }
    }

    // Check if all divine members are identified
    if (found) {
      for (i = 1; i <= p1 + p2; i++) {
        if (divine[i] == -1) {
          // Unidentified divine member
          found = 0;
          break;
        }
      }
    }

    // Print the results
    if (found) {
      for (i = 1; i <= p1 + p2; i++) {
        if (divine[i] == 1) {
          printf("%d\n", i);
        }
      }
      printf("end\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}