#include <stdio.h>

int n, a, b, c, d;
int tof = 0;
char str[200010];

void solve(int ta, int tb) {
  if (ta > c || tb > d) return;
  else if (ta == tb) return;
  else if (str[ta-1] == '#' || str[tb-1] == '#') return;
  
  if (ta == c && tb == d) {
    tof = 1;
    return;
  }
  
  solve(ta+1, tb);
  solve(ta+2, tb);
  solve(ta, tb+1);
  solve(ta, tb+2);
  return;
}

int main(void) {
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
  scanf("%s", str);
  
  solve(a, b);
  
  if (tof == 1) printf("Yes\n");
  else printf("No\n");
  
  return 0;
}