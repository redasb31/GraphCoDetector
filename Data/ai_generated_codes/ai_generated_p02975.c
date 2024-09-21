#include <stdio.h>

int main() {
  // N: Number of hats/camels
  int N;
  scanf("%d", &N);

  // a: Array to store the numbers written on the hats
  int a[N];

  // Input the numbers on the hats
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Check if the condition is satisfied for any arrangement of hats
  int flag = 1;
  for (int i = 0; i < N; i++) {
    if ((a[i] ^ a[(i + 1) % N]) != a[(i + 2) % N]) {
      flag = 0;
      break;
    }
  }

  // Output the result
  if (flag) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}