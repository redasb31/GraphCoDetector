#include <stdio.h>

int main() {
  int d, i, area = 0;

  // Loop through each dataset
  while (scanf("%d", &d) != EOF) {
    // Calculate the area using the formula
    area = 0;
    for (i = d; i < 600; i += d) {
      area += d * (i * i); // Area of each rectangle
    }
    printf("%d\n", area);
  }

  return 0;
}