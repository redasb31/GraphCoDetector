#include <stdio.h>

int main() {
  // Input variables
  int N; // Number of shops
  int F[101][5][2]; // Shop opening hours (1 for open, 0 for closed)
  int P[101][11]; // Profit for each shop based on number of shared open periods
  int maxProfit = -1000000000; // Initialize maximum profit to a very low value

  // Read input values
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 5; j++) {
      for (int k = 1; k <= 2; k++) {
        scanf("%d", &F[i][j][k]);
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 10; j++) {
      scanf("%d", &P[i][j]);
    }
  }

  // Iterate through all possible combinations of Joisino's shop opening hours
  for (int openPeriods = 1; openPeriods <= 10; openPeriods++) {
    // Iterate through all possible sets of open periods (using bitmask)
    for (int bitmask = 1; bitmask < (1 << 10); bitmask++) {
      // Check if the bitmask represents exactly 'openPeriods' open periods
      int countOpenPeriods = 0;
      for (int i = 0; i < 10; i++) {
        if (bitmask & (1 << i)) {
          countOpenPeriods++;
        }
      }
      if (countOpenPeriods != openPeriods) {
        continue; // Skip to the next bitmask if the wrong number of periods are open
      }

      // Calculate the profit for this combination of open periods
      int currentProfit = 0;
      for (int i = 1; i <= N; i++) {
        int sharedOpenPeriods = 0;
        for (int j = 1; j <= 5; j++) {
          for (int k = 1; k <= 2; k++) {
            if (F[i][j][k] == 1 && (bitmask & (1 << ((j - 1) * 2 + (k - 1))))) {
              sharedOpenPeriods++;
            }
          }
        }
        currentProfit += P[i][sharedOpenPeriods];
      }

      // Update the maximum profit if necessary
      maxProfit = (currentProfit > maxProfit) ? currentProfit : maxProfit;
    }
  }

  // Output the maximum profit
  printf("%d\n", maxProfit);

  return 0;
}