#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

typedef struct directed_edge {
  int32_t vertex;
  int32_t next;
} graph_edge;

typedef struct directedGraph {
  graph_edge *edge;
  int32_t *start;
  int32_t pointer;
  int32_t vertex_num;
  int32_t edge_max_size;
} graph;

graph* new_graph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->edge_max_size = 1;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void add_edge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  g->start[from] = g->pointer++;
}

const i32 mod = 1000000007;

i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

void calc (i32 r, graph *g, i32 *dp, i32 *height, i32 *tmp) {
  dp[0] = (mod + 1) / 2;
  if (g->start[r] == -1) {
    return;
  }
  i32 v = g->edge[g->start[r]].vertex;
  for (i32 p = g->start[r]; p != -1; p = g->edge[p].next) {
    i32 u = g->edge[p].vertex;
    if (height[u] > height[v]) {
      v = u;
    }
  }
  calc (v, g, dp + 1, height, tmp);
  i32 *buf = dp + height[r];
  i32 len = 0;
  for (i32 p = g->start[r]; p != -1; p = g->edge[p].next) {
    i32 u = g->edge[p].vertex;
    if (u == v) continue;
    calc (u, g, buf, height, tmp + 2 * len);
    if (len < height[u]) {
      for (i32 j = len; j < height[u]; ++j) {
        tmp[2 * j + 0] = mod + 1 - dp[1 + j];
        tmp[2 * j + 1] = dp[1 + j];
      }
      len = height[u];
    }
    for (i32 j = 0; j < height[u]; ++j) {
      tmp[2 * j + 1] = ((i64) tmp[2 * j + 1] * (mod + 1 - buf[j]) + (i64) tmp[2 * j + 0] * buf[j]) % mod;
      tmp[2 * j + 0] = (i64) tmp[2 * j + 0] * (mod + 1 - buf[j]) % mod;
    }
  }
  for (i32 i = 0; i < len; ++i) {
    dp[i + 1] = tmp[2 * i + 1];
  }
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  graph *g = new_graph (n + 1);
  for (i32 i = 1; i <= n; ++i) {
    i32 p;
    scanf ("%" SCNi32, &p);
    add_edge (g, p, i);
  }
  i32 *height = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 i = n; i >= 0; --i) {
    height[i] = 1;
    for (i32 p = g->start[i]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      if (height[u] + 1 > height[i]) height[i] = height[u] + 1;
    }
  }
  i32 *dp = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *tmp = (i32 *) calloc (2 * (n + 1), sizeof (i32));
  calc (0, g, dp, height, tmp);
  i64 ans = 0;
  for (i32 i = 0; i < height[0]; ++i) {
    ans += (i64) mod_pow (2, n + 1) * dp[i];
  }
  printf ("%" PRIi64 "\n", ans % mod);
}

int main (void) {
  run();
  return 0;
}
