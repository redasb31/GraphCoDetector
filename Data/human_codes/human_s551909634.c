#include <stdio.h>


void rotate(int *a, int b, int m, int e)
{
  int i;
  int tmp[e-b];
  for (i=0; i<e-b; i++)
    tmp[i] = a[b+i];
  for (i=0; i<e-b; i++)
    a[(i+e-m)%(e-b)+b] = tmp[i];
}

int main()
{
  int i, n, q, b, e, m;
  fscanf(stdin, "%d", &n);
  int a[n];
  for (i=0; i<n; i++)
    fscanf(stdin, "%d", &a[i]);

  fscanf(stdin, "%d", &q);
  for (i=0; i<q; i++) {
    fscanf(stdin, "%d %d %d", &b, &m, &e);
    rotate(a, b, m, e);
  }
  for (i=0; i<n-1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  
  return 0;
}

