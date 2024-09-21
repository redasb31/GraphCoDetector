#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint64_t u64;

typedef struct union_find_add {
  i32 *parent;
  i64 *add;
} union_find;

union_find* new_union_find (i32 n) {
  union_find *u = (union_find *) calloc (1, sizeof (union_find));
  u->parent = (i32 *) calloc (n, sizeof (i32));
  u->add = (i64 *) calloc (n, sizeof (i64));
  for (i32 i = 0; i < n; ++i) {
    u->parent[i] = -1;
  }
  return u;
}

i32 root (union_find *u, i32 x) {
  i32 stack[32];
  i32 top = 0;
  stack[top++] = x;
  while (u->parent[x] >= 0) {
    x = u->parent[x];
    stack[top++] = x;
  }
  i32 r = stack[top - 1];
  i64 buf = 0;
  for (i32 i = top - 2; i >= 0; --i) {
    i32 y = stack[i];
    i64 next = buf + u->add[y];
    u->add[y] += buf;
    buf = next;
    u->parent[y] = r;
  }
  return r;
}

void unite (union_find *u, i32 x, i32 y) {
  x = root (u, x);
  y = root (u, y);
  if (x == y) return;
  if (u->parent[x] > u->parent[y]) {
    i32 s = x;
    x = y;
    y = s;
  }
  u->add[y] -= u->add[x];
  u->parent[x] += u->parent[y];
  u->parent[y] = x;
}

void add (union_find *u, i32 x, i64 v) {
  u->add[root (u, x)] += v;
}

i64 find (union_find *u, i32 x) {
  i32 r = root (u, x);
  return r == x ? u->add[x] : u->add[x] + u->add[r];
}

typedef u64 radix_type;

#define RADIX_WIDTH 15
const uint32_t radix_type_max = 64;
const uint32_t radix_type_begin = 34;
const uint32_t radix_width = RADIX_WIDTH;
const uint32_t radix_mask = (1 << RADIX_WIDTH) - 1;
#undef RADIX_WIDTH

static inline uint32_t radix_get_bit (radix_type v, uint32_t shift) {
  return v >> shift & radix_mask;
}

void radix_sort (radix_type *a, uint32_t n) {
  radix_type * const array = (radix_type *) calloc (4 * n, sizeof (radix_type));
  radix_type **bucket = (radix_type **) calloc (1 << radix_width, sizeof (radix_type *));
  uint32_t *len = (uint32_t *) calloc (2 << radix_width, sizeof (uint32_t));
  uint32_t *max_len = len + (1 << radix_width);
  for (uint32_t shift = radix_type_begin; shift < radix_type_max; shift += radix_width) {
    radix_type *p = array;
    memset (len, 0, sizeof (uint32_t) << (radix_width + 1));
    for (uint32_t i = 0; i < n; ++i) {
      uint32_t bit = radix_get_bit (a[i], shift);
      if (len[bit] == max_len[bit]) {
        for (uint32_t j = 0; j < len[bit]; ++j) {
          p[j] = bucket[bit][j];
        }
        max_len[bit] = 2 * max_len[bit] + 1;
        bucket[bit] = p;
        p += max_len[bit];
      }
      bucket[bit][len[bit]++] = a[i];
    }
    for (uint32_t bit = 0, i = 0; bit < (1 << radix_width); ++bit) {
      for (uint32_t j = 0; j < len[bit]; ++j, ++i) {
        a[i] = bucket[bit][j];
      }
    }
  }
  free (array);
  free (bucket);
  free (len);
}

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  u64 *e = (u64 *) calloc (n - 1, sizeof (u64));
  const i32 f = 17;
  const i32 mask = (1 << f) - 1;
  for (i32 i = 0; i < n - 1; ++i) {
    i32 a = read_int() - 1;
    i32 b = read_int() - 1;
    i32 c = read_int();
    e[i] = ((u64) c << 2 * f) + ((u64) a << f) + b;
  }
  radix_sort (e, n - 1);
  union_find *u = new_union_find (n);
  for (i32 i = n - 2; i >= 0; --i) {
    i32 a = root (u, e[i] & mask);
    i32 b = root (u, e[i] >> f & mask);
    i64 c = e[i] >> 2 * f;
    add (u, b, -u->parent[a] * c);
    add (u, a, -u->parent[b] * c);
    unite (u, a, b);
  }
  for (i32 i = 0; i < n; ++i) {
    print_int (find (u, i));
    putchar ('\n');
  }
}

int main (void) {
  run();
  return 0;
}
