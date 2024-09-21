#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* typedef */

typedef unsigned long long ull_t;

/* main */

int main(int argc, char **argv) {
  ull_t n, hn, count, x;
  double hnf;

  for (;;) {
    scanf("%llu", &n);
    if (n == 0) break;

    hn = n / 2;
    hnf = (double)hn;

    count = hn;

    for (x = 1; x < hn; x++)
      count += (ull_t)ceil(hnf / x);

    printf("%llu\n", (count + n) * 8);
  }

  return 0;
}