#include <stdio.h>

// Function to calculate the sum of digits in base l
int sum_of_digits(int a, int l) {
  int sum = 0;
  while (a > 0) {
    sum += a % l;
    a /= l;
  }
  return sum;
}

// Function to calculate L(a)
int L(int a, int l) {
  int k = 0;
  while (a >= l) {
    a = sum_of_digits(a, l);
    k++;
  }
  return k;
}

int main() {
  int N, m, l, case_num = 1;
  while (scanf("%d %d %d", &N, &m, &l) != EOF) {
    if (N == 0 && m == 0 && l == 0) {
      break;
    }
    // Start from 1 and iterate until we find a number with L(a) == N
    int a = 1;
    while (L(a, l) != N) {
      a++;
    }
    // Print the result
    printf("Case %d: %d\n", case_num++, a % m);
  }
  return 0;
}