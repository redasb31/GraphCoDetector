#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define POS(i, j) ((i) * (m + 1) + (j))

i32 find (i32 a, i32 b, i32 c, i32 d, i32 *dp, i32 m) {
  return dp[POS(c, d)] - dp[POS(c, b - 1)] - dp[POS(a - 1, d)] + dp[POS(a - 1, b - 1)];
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 q = read_int();
  i32 *v = (i32 *) calloc ((n + 1) * (m + 1), sizeof (i32));
  i32 *ex = (i32 *) calloc ((n + 1) * (m + 1), sizeof (i32));
  i32 *ey = (i32 *) calloc ((n + 1) * (m + 1), sizeof (i32));
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= m; ++j) {
      v[POS(i, j)] = getchar() - '0';
      ex[POS(i, j)] = v[POS(i, j)] & v[POS(i - 1, j)];
      ey[POS(i, j)] = v[POS(i, j)] & v[POS(i, j - 1)];
    }
    getchar();
  }
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= m; ++j) {
      v[POS(i, j)] += v[POS(i - 1, j)] + v[POS(i, j - 1)] - v[POS(i - 1, j - 1)];
      ex[POS(i, j)] += ex[POS(i - 1, j)] + ex[POS(i, j - 1)] - ex[POS(i - 1, j - 1)];
      ey[POS(i, j)] += ey[POS(i - 1, j)] + ey[POS(i, j - 1)] - ey[POS(i - 1, j - 1)];
    }
  }
  while (q--) {
    i32 a = read_int();
    i32 b = read_int();
    i32 c = read_int();
    i32 d = read_int();
    i32 ans = find (a, b, c, d, v, m) - find (a + 1, b, c, d, ex, m) - find (a, b + 1, c, d, ey, m);
    print_int (ans);
    putchar ('\n');
  }
}

int main (void) {
  run();
  return 0;
}
