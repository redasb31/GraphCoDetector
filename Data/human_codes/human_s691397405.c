#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void print (i32 a, i32 b) {
  printf ("%" PRIi32 " %" PRIi32 "\n", a, b);
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  if (n == (n & -n)) {
    puts ("No");
    return;
  }
  puts ("Yes");
  print (1, 2);
  print (2, 3);
  print (3, n + 1);
  print (n + 1, n + 2);
  print (n + 2, n + 3);
  if (n % 2 != 0) {
    for (i32 i = 4; i < n; i += 2) {
      print (i, i + 1);
      print (i + 1, 1);
      print (1, n + i);
      print (n + i, n + i + 1);
    }
  } else {
    for (i32 i = 4; i < n - 1; i += 2) {
      print (i + 1, i);
      print (i, 1);
      print (1, n + i + 1);
      print (n + i + 1, n + i);
    }
    i32 b = n & -n;
    print (n, b);
    print (2 * n, n + (n ^ 1 ^ b));
  }
}

int main (void) {
  run();
  return 0;
}
