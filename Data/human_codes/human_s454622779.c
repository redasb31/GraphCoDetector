#include <stdio.h>

int main(void){
  int N;
  scanf("%d", &N);

  int a, ans = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a);
    if(a%2 != 0) ans = 1;
  }

  if(ans) printf("first\n");
  else printf("second\n");

  return 0;
}