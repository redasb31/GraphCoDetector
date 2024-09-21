#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  char s[n+5];
  scanf("%s", s);
  long ans = 0;
  if (10%p == 0) {
    for (int i = 0; i < n; i++)
    {
      if ((s[i] - '0') % p == 0)
        ans += i + 1;
    }
  } else {
    long dig = 1, r[p], t = 0;
    for (int i = 0; i < p; i++)
      r[i] = 0;
    r[0]++;
    for (int i = n; i > 0; i--)
    {
      t += (s[i-1] - '0') * dig;
      t %= p;
      r[t]++;
      dig *= 10;
      dig %= p;
    }
    for (int i = 0; i < p; i++)
      ans += (r[i] * (r[i] - 1)) / 2;
  }
  printf("%ld\n", ans);
  return 0;
}
