#include <stdio.h>

int main() {
  // N: The number of takoyaki
  int N;
  // d_i: Deliciousness of the i-th takoyaki
  int d[50];
  // sum: The sum of health points restored from eating two takoyaki
  long long sum = 0;

  // Input the number of takoyaki
  scanf("%d", &N);

  // Input the deliciousness of each takoyaki
  for (int i = 0; i < N; i++) {
    scanf("%d", &d[i]);
  }

  // Calculate the sum of health points restored
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      // Calculate the health points restored from eating the i-th and j-th takoyaki
      sum += (long long)d[i] * d[j];
    }
  }

  // Output the sum of health points restored
  printf("%lld\n", sum);

  return 0;
}