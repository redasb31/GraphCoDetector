#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 40000
#define INF 1000000000
struct line {
  int a;
  int b;
  int c;
  int i;
  double g;
};
int compare(const void *a, const void *b);
void add(int *bit, int index, int value, int size);
int sum(int *bit, int index);
int main(void)
{
  int d, i, n, m, t, h, bit[NMAX+1];
  double mid, lo = -INF, hi = INF;
  struct line l[NMAX];
  scanf("%d", &n);
  m = (n - 1) * n / 2;
  t = (m + 1) / 2;
  for (d = 0; d < 2; d++) {
    for (i = 0; i < n; i++) {
      scanf("%d %d %d", &l[i].a, &l[i].b, &l[i].c);
      l[i].g = (double)l[i].a / l[i].b;
    }
    qsort(l, n, sizeof(struct line), compare);
    for (i = 0; i < n; i++) l[i].i = i;
    while (hi - lo >= 0.000000001) {
      mid = (lo + hi) / 2;
      for (i = 0; i < n; i++) l[i].g = (l[i].c - l[i].a * mid) / l[i].b;
      qsort(l, n, sizeof(struct line), compare);
      memset(bit, 0, sizeof(bit));
      h = m;
      for (i = 0; i < n; i++) {
        h -= sum(bit, l[i].i + 1);
        add(bit, l[i].i + 1, 1, n);
      }
      if (h >= t) hi = mid;
      else lo = mid;
    }
    printf("%f\n", mid);
    for (i = 0; i < n; i++) {
      int temp = l[i].a;
      l[i].a = l[i].b;
      l[i].b = temp;
    }
  }
}

int compare(const void *a, const void *b)
{
  double ta = ((struct line*)a)->g, tb = ((struct line*)b)->g;
  if (ta > tb) return 1;
  else if (ta < tb) return -1;
  else return 0;
}

void add(int *bit, int index, int value, int size)
{
  while (index <= size) {
    bit[index] += value;
    index += index & (-index);
  }
}

int sum(int *bit, int index)
{
  int sum = 0;
  while (index > 0) {
    sum += bit[index];
    index -= index & (-index);
  }
  return sum;
}