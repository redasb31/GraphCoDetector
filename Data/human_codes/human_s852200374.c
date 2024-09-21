#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, m ,x;
  scanf("%d%d%d", &n, &m, &x);
  int a[m], left = 0;
  for (int i=0; i<m; i++) {
    scanf("%d", a+i);
    if (x>a[i]) left++;
  }
  if (left < m-left) printf("%d\n", left);
  else printf("%d\n", m-left);
  return 0;
}
