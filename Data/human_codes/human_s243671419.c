#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MOD 1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;
#define MAX_N (1 << 17)

int
main(int argc, const char *argv[])
{
  int n; char s[100001];
  scanf("%d", &n);
  scanf("%s", s);

  for (int i = 0; i < (1 << 2); i++) {
    bool t[100010];
    t[0] = i & 1;
    t[1] = i & (i << 1);
    int k = 2;
    while (k <= n + 1) {
      if (!t[k - 1] && s[k - 1] == 'o') t[k] = t[k - 2];
      if (!t[k - 1] && s[k - 1] == 'x') t[k] = !t[k - 2];
      if (t[k - 1] && s[k - 1] == 'o') t[k] = !t[k - 2];
      if (t[k - 1] && s[k - 1] == 'x') t[k] = t[k - 2];
      k++;
    }

    if (t[n] == t[0] && t[n + 1] == t[1]) {
      for (int i = 0; i < n; i++) {
	if (!t[i]) printf("S");
	else printf("W");
      } endl;
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}
    
    
    
