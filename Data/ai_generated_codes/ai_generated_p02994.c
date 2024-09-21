#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the number of apples (N) and the starting flavor (L)
  int N, L;
  scanf("%d %d", &N, &L);

  // Calculate the total flavor of all apples
  long long total_flavor = 0;
  for (int i = 1; i <= N; i++) {
    total_flavor += L + i - 1;
  }

  // Find the apple with the flavor closest to the average flavor
  long long min_diff = LLONG_MAX;
  int chosen_apple = -1;
  for (int i = 1; i <= N; i++) {
    long long current_diff = abs(total_flavor - (L + i - 1));
    if (current_diff < min_diff) {
      min_diff = current_diff;
      chosen_apple = i;
    }
  }

  // Calculate the flavor of the pie without the chosen apple
  long long pie_flavor = total_flavor - (L + chosen_apple - 1);

  // Print the flavor of the pie
  printf("%lld\n", pie_flavor);

  return 0;
}