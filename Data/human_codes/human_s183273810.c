#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int f[9];
void factorial() {
  f[0] = 1;
  for (int i = 1; i < 9; i++)
    f[i] = f[i - 1] * i;
}

int dictionary(int *a, int size) {
  if (size <= 1) return 0;
  int i=0;
  while (a[i] == i+1) i++;
  if (i == 0) {
    int b[size-1];
    for (int i=0; i<size-1; i++) {
      if (a[i+1] > a[0]) b[i] = a[i+1] - 1;
      else b[i] = a[i+1];
    }
    return (a[0]-1) * f[size-1] + dictionary(b, size-1);
  }
  int b[size - i];
  for (int j=0; j<size-i; j++) {
    if (a[i+j] > a[i-1]) b[j] = a[i+j] - a[i-1];
    else b[j] = a[i+j];
  }
  return dictionary(b, size-i);
}

int main() {
  int n;
  scanf("%d", &n);
  int p[n], q[n];
  for (int i = 0; i < n; i++)
    scanf("%d", p + i);
  for (int i = 0; i < n; i++)
    scanf("%d", q + i);
  factorial();
  int po = dictionary(p, n);
  int qo = dictionary(q, n);
  printf("%d\n", abs(po - qo));
  return 0;
}
