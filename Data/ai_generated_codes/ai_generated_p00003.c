#include <stdio.h>
#include <math.h>

int main() {
  int N, a, b, c;
  scanf("%d", &N); // Read the number of data sets

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &a, &b, &c); // Read the side lengths for each data set

    // Check if the Pythagorean theorem holds (a^2 + b^2 = c^2)
    if (pow(a, 2) + pow(b, 2) == pow(c, 2) || 
        pow(a, 2) + pow(c, 2) == pow(b, 2) || 
        pow(b, 2) + pow(c, 2) == pow(a, 2)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}