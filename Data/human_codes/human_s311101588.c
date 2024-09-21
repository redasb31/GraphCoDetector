#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;
typedef int64_t i64;

#define F 2

const i32 prime[2] = {1000000033, 1000000087};
const i32 rad = 27;

typedef struct hashNode {
  i32 val[F];
} node;

int cmp (const void *a, const void *b) {
  node *p = (node *) a;
  node *q = (node *) b;
  for (i32 i = 0; i < F; ++i) {
    i32 d = p->val[i] - q->val[i];
    if (d != 0) {
      return d < 0 ? -1 : 1;
    }
  }
  return 0;
}

i32 modPow (i32 r, i32 n, i32 mod) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

void run (void) {
  char *s = (char *) calloc (100000 + 1, sizeof (char));
  scanf("%s", s);
  const i32 n = strlen (s);
  node *p = (node *) calloc (n, sizeof (node));
  i32 l = 0;
  i32 r = n;
  while (r - l > 1) {
    const i32 m = (l + r) / 2;
    const i32 len = m;
    i32 inv[F];
    node t;
    for (i32 i = 0; i < F; ++i) {
      t.val[i] = 0;
      inv[i] = modPow (rad, len - 1, prime[i]);
    }
    for (i32 i = 0; i < len - 1; ++i) {
      i32 d = s[i] - 'a' + 1;
      for (i32 k = 0; k < F; ++k) {
	t.val[k] = ((i64) t.val[k] * rad + d) % prime[k];
      }
    }
    i32 plen = 0;
    for (i32 i = len - 1; i < n; ++i) {
      i32 d = s[i] - 'a' + 1;
      for (i32 k = 0; k < F; ++k) {
	t.val[k] = ((i64) t.val[k] * rad + d) % prime[k];
      }
      p[plen++] = t;
      d = s[i - len + 1] - 'a' + 1;
      for (i32 k = 0; k < F; ++k) {
	t.val[k] = (t.val[k] - (i64) d * inv[k] % prime[k] + prime[k]) % prime[k];
      }
    }
    qsort (p, plen, sizeof (node), cmp);
    i32 i;
    for (i = 0; i < plen - 1; ++i) {
      if (cmp (p + i, p + i + 1) == 0) {
	break;
      }
    }
    if (i < plen - 1) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%" PRIi32 "\n", n - r + 1);
}

int main (void) {
  run ();
  return 0;
}
