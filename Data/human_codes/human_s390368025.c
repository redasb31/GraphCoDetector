#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

static char s[N][N + 64];
static int n;

static
nextint()
{
  char s[32];
  fgets(s, sizeof(s), stdin);
  return atoi(s);
}

static void
preproc(s)
char *s;
{
  if (s[0] != '.') return ;
  for (; s[1] == '.'; ++s) {
    s[0] = ' ';
  }
  s[0] = '+';
}

main()
{
  int i, j;
  
  for (;;) {
    n = nextint();
    if (n == 0) break ;

    memset(s, 0, sizeof(s));
    for (i = 0; i < n; ++i) {
      fgets(s[i], sizeof(s[i]), stdin);
      preproc(s[i]);
    }
    
    for (i = 0; i < n; ++i) {
      char *p = strchr(s[i], '+');
      if (p == NULL) continue ;
      for (j = i + 1; j < n; ++j) {
        if (s[j][p - s[i]] == ' ') continue ;
        if (s[j][p - s[i]] == '+') {
          for (--j; j != i; --j) {
            s[j][p - s[i]] = '|';
          }
        }
        break ;
      }
    }
    
    for (i = 0; i < n; ++i) {
      fputs(s[i], stdout);
    }
  }

  return 0;
}