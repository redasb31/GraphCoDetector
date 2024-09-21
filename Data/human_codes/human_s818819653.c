#include <stdio.h>

#define MAX_N   (10000)

static int sqcheck[MAX_N];
static int sqs[MAX_N];
static int counts[MAX_N];

int main() {
  int d, i, j, hn, n, sqsize;
  long k;

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;

    hn = (n - 1) / 2;

    for (i = 0; i < n; i++) sqcheck[i] = counts[i] = 0;

    for (k = 1; k < n; k++) sqcheck[(k * k) % n] = 1;

    sqsize = 0;
    for (i = 1; i < n; i++)
      if (sqcheck[i]) sqs[sqsize++] = i;

    for (i = 0; i < sqsize; i++)
      for (j = 0; j < sqsize; j++)
        if (i != j) {
          d = sqs[i] - sqs[j];
          if (d < 0) d += n;
          if (d > hn) d = n - d;
          counts[d]++;
        }

    for (i = 1; i <= hn; i++)
      printf("%d\n", counts[i]);
  }

  return 0;
}