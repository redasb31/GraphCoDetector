#include <stdio.h>
#include <stdint.h>

int main(void){
  int n, i, count = 0;
  int64_t d, x, y;
  scanf("%d%lld", &n, &d);
  d = d*d;
  for(i = 0; i < n; i++){
    scanf("%lld%lld", &x, &y);
    if(x*x + y*y <= d) count++;
  }
  printf("%d\n", count);
  return 0;
}