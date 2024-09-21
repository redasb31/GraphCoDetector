#include <stdio.h>
int main(int argc, char const *argv[]) {
  int a,b;
  scanf("%d%d", &a,&b);
  if (a>=10 || b>=10) {
    printf("-1");
  } else {
    printf("%d\n", a*b);
  }

  return 0;
}

