#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

#define ALLOC(size,type) ((type *) calloc ((size), sizeof (type)))

typedef struct union_find_depth {
  i32 *parent;
  i32 *depth;
  i32 size;
} union_find;

union_find* new_union_find (const i32 n) {
  union_find *u = ALLOC (1, union_find);
  u->parent = ALLOC (n, i32);
  u->depth = ALLOC (n, i32);
  u->size = n;
  for (i32 i = 0; i < n; ++i) {
    u->parent[i] = -1;
  }
  return u;
}

i32 root (union_find *u, i32 x) {
  while (u->parent[x] >= 0) {
    x = u->parent[x];
  }
  return x;
}

i32 depth (union_find *u, i32 x) {
  i32 sum = 0;
  while (u->parent[x] >= 0) {
    sum += u->depth[x];
    x = u->parent[x];
  }
  return sum;
}

int unite (union_find *u, i32 x, i32 y, i32 w) {
  i32 rx = root (u, x);
  i32 ry = root (u, y);
  if (rx == ry) {
    return depth (u, x) + w == depth (u, y);
  }
  if (u->parent[rx] > u->parent[ry]) {
    i32 swap = rx;
    rx = ry;
    ry = swap;
    w = -w;
  }
  u->depth[ry] = depth (u, x) + w - depth (u, y);
  u->parent[rx] += u->parent[ry];
  u->parent[ry] = rx;
  return 1;
}

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  union_find *u = new_union_find (n + 1);
  while (m--) {
    i32 l, r, d;
    scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &l, &r, &d);
    if (!unite (u, l, r, d)) {
      puts ("No");
      return;
    }
  }
  puts ("Yes");
}

int main (void) {
  run();
  return 0;
}
