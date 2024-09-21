#include <stdio.h>

int main(void) {

  int n;
  scanf("%d", &n);
  int prime_list[55555+1];
  prime_list[0] = 0;
  prime_list[1] = 0;
  for (int i = 2; i <= 55555; i++) {
    prime_list[i] = 1;
  }
  for (int i = 2; i <= 55555; i++) {
    if (prime_list[i] == 1) {
      for (int j = 2; i*j <= 55555; j++) {
        prime_list[i*j] = 0;
      }
    }
  }
  for (int i = 2; i <= 55555; i++) {
    if (i%5 != 1) {
      prime_list[i] = 0;
    }
  }
  int count = 0;
  for (int i = 2; i <= 55555; i++) {
    if (prime_list[i] == 1) {
      printf("%d", i);
      count++;
      if (count == n) {
        printf("\n");
        break;
      } else {
        printf(" ");
      }
    }
  }

  return 0;
}