#include <stdio.h>
#include <limits.h>

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
    // Read card scores
    int taro_scores[n], hanako_scores[m];
    int taro_total = 0, hanako_total = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &taro_scores[i]);
      taro_total += taro_scores[i];
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &hanako_scores[i]);
      hanako_total += hanako_scores[i];
    }

    // Find the best card exchange
    int best_taro_score = -1, best_hanako_score = -1;
    int min_diff = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // Calculate the difference in total scores after exchange
        int diff = abs((taro_total - taro_scores[i] + hanako_scores[j]) - (hanako_total - hanako_scores[j] + taro_scores[i]));
        // Update best exchange if the difference is smaller
        if (diff < min_diff) {
          min_diff = diff;
          best_taro_score = taro_scores[i];
          best_hanako_score = hanako_scores[j];
        }
      }
    }

    // Output the best exchange or -1 if no exchange can make the scores equal
    if (min_diff == INT_MAX) {
      printf("-1\n");
    } else {
      printf("%d %d\n", best_taro_score, best_hanako_score);
    }
  }
  return 0;
}