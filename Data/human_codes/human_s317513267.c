#include <stdio.h>
int main(void) {
  int n, i, x, y;
  unsigned long long int k, j;
  if(scanf("%d %llu", &n, &k)==1);
  int a[n];
  for(i=0;i<n;i++) {
    if(scanf("%d", &a[i])==1);
  }
  x=1;
  for(j=0;j<k;j++) {
    y=a[x];
    x=y;
  }
  printf("%d", y);
  return 0;
}
