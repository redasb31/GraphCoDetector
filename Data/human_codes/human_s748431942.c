#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve() {
  int n, x, y, dx, dy, tx, ty;
  int buf, dis;
  //FILE *fp = fopen("input", "r");
  fscanf(stdin, "%d", &n);
  while (0 < n--) {
    x = y = tx = ty = dis = 0;
    while (1) {
      fscanf(stdin, "%d %d", &dx, &dy);
      if (dx == 0 && dy == 0) break;
      x += dx;
      y += dy;
      buf = pow(x, 2) + pow(y, 2);
      if (buf > dis) {
        dis = buf;
        tx = x; ty = y;
      } else if (buf == dis && x > tx){
        tx = x; ty = y;
      }
    }
    printf("%d %d\n", tx, ty);
  }
  //fclose(fp);
}

int main(void) {
  solve();
  return 0;
}