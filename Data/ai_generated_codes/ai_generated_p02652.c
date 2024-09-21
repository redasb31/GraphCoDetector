#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char s[1000001];
  scanf("%s", s);

  // Calculate the number of 0s, 1s, and ?s in the string.
  int count_0 = 0;
  int count_1 = 0;
  int count_q = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '0') {
      count_0++;
    } else if (s[i] == '1') {
      count_1++;
    } else {
      count_q++;
    }
  }

  // Calculate the maximum possible difference between the number of 0s and 1s.
  int max_diff = abs(count_0 - count_1) + count_q;

  // Calculate the minimum possible unbalancedness.
  int min_unbalancedness = max_diff / 2;

  // If the maximum possible difference is odd, then the minimum possible unbalancedness is one more than half the maximum possible difference.
  if (max_diff % 2 != 0) {
    min_unbalancedness++;
  }

  printf("%d\n", min_unbalancedness);

  return 0;
}