#include <stdio.h>

int main(void){

  char s[16];
  scanf("%s", s);
  char correct[16] = "CODEFESTIVAL2016";
  int count = 0;
  for (int i = 0; i < 16; i++) {
    if (s[i] != correct[i]) {
      count++;
    }
  }
  printf("%d\n", count);

  return 0;
}