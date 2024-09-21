#include <stdio.h>
#include <string.h>

int main() {
  // Number of datasets
  int n;
  scanf("%d", &n);

  // Loop through each dataset
  for (int i = 0; i < n; i++) {
    // Initialize score and outs
    int score = 0;
    int outs = 0;

    // Initialize runners on base (0: empty, 1: occupied)
    int bases[3] = {0, 0, 0};

    // Read events in the inning
    char event[10];
    while (outs < 3 && scanf("%s", event) != EOF) {
      // Single hit
      if (strcmp(event, "HIT") == 0) {
        // Advance runners
        bases[2] = bases[1];
        bases[1] = bases[0];
        bases[0] = 1;
        // Score a run if there's a runner on third base
        if (bases[2]) {
          score++;
          bases[2] = 0;
        }
      }

      // Home run
      else if (strcmp(event, "HOMERUN") == 0) {
        // Score runs for all runners on base plus the batter
        score += bases[0] + bases[1] + bases[2] + 1;
        // Clear bases
        bases[0] = bases[1] = bases[2] = 0;
      }

      // Out
      else if (strcmp(event, "OUT") == 0) {
        outs++;
      }
    }

    // Print the score for the inning
    printf("%d\n", score);
  }

  return 0;
}