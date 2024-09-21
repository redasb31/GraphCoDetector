#include <stdio.h>

int main(void) {

  long n;
  scanf("%ld", &n);
  long bit[100];
  for (long i = 0; i < 100; i++) {
    bit[i] = 0;
  }
  if (n >= 0) {
    bit[0] = n;
  } else {
    bit[0] = -n;
    bit[1] = -n;
  }
  for (long i = 1; i < 50; i++) {
    bit[i] += bit[i-1]/2;
    bit[i+1] += bit[i-1]/2;
    bit[i-1] %= 2;
  }
  int flag = 0;
  for (long i = 40; i > 0; i--) {
    if (bit[i] == 1) {
      flag = 1;
    }
    if (flag == 1) {
      printf("%ld", bit[i]);
    }
  }
  printf("%ld\n", bit[0]);

  return 0;
}