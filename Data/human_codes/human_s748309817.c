#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

typedef int32_t flow_type;

const flow_type flow_inf = 25 * 25;

typedef struct flow_edge {
  int32_t vertex;
  int32_t next;
  flow_type capacity;
} flow_edge;

typedef struct maxFlowGraph {
  flow_edge *edge;
  int32_t *start;
  int32_t vertex_num;
  int32_t pointer;
  int32_t edge_length;
} graph;

graph* new_graph (const int32_t vertex_num) {
  graph * const g = (graph *) calloc (1, sizeof (graph));
  g->vertex_num = vertex_num;
  const int32_t initial_length = 4;
  g->edge = (flow_edge *) calloc (initial_length, sizeof (flow_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->edge_length = initial_length;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g;
}

void add_edge (graph * const g, const int32_t from, const int32_t to, const flow_type capa) {
  if (g->pointer == g->edge_length) {
    g->edge_length *= 2;
    g->edge = (flow_edge *) realloc (g->edge, sizeof (flow_edge) * g->edge_length);
  }
  const int32_t p = g->pointer;
  g->edge[p] = (flow_edge) {to, g->start[from], capa};
  g->start[from] = p;
  g->edge[p + 1] = (flow_edge) {from, g->start[to], 0};
  g->start[to] = p + 1;
  g->pointer += 2;
}

flow_type dinic_dfs (const int32_t v, const graph * const g, const int32_t dst, const int32_t * const level, int32_t * const iter, flow_type e) {
  if (v == dst) return e;
  flow_type sum = 0;
  for (int32_t p = iter[v]; p != -1; p = g->edge[p].next, iter[v] = p) {
    const int32_t u = g->edge[p].vertex;
    const flow_type capa = g->edge[p].capacity;
    if (level[u] <= level[v] || capa <= 0) continue;
    const flow_type f = dinic_dfs (u, g, dst, level, iter, capa < e ? capa : e);
    if (f > 0) {
      g->edge[p].capacity -= f;
      g->edge[p ^ 1].capacity += f;
      sum += f;
      e -= f;
      if (e <= 0) return sum;
    }
  }
  return sum;
}

flow_type dinic (const graph * const g, const int32_t src, const int32_t dst) {
  const int32_t vertex_num = g->vertex_num;
  int32_t * const level = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const queue = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  int32_t * const iter  = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  flow_type flow = 0;
  while (1) {
    memset (level, 0, sizeof (int32_t) * vertex_num);
    int32_t front = 0;
    int32_t last = 0;
    level[dst] = vertex_num;
    queue[last++] = dst;
    while (front < last && level[src] == 0) {
      const int32_t v = queue[front++];
      for (int32_t p = g->start[v]; p!=-1; p = g->edge[p].next) {
        const int32_t u = g->edge[p].vertex;
        if (g->edge[p ^ 1].capacity > 0 && level[u] == 0) {
          level[u] = level[v] - 1;
          queue[last++] = u;
        }
      }
    }
    if (level[src] == 0) break;
    memcpy (iter, g->start, sizeof (int32_t) * vertex_num);
    while (1) {
      const flow_type f = dinic_dfs (src, g, dst, level, iter, flow_inf);
      if (f <= 0) break;
      flow += f;
    }
  }
  free (level);
  free (queue);
  free (iter);
  return flow;
}

#define POS(i, j) ((i) * w + (j))

void run (void) {
  i32 h, w;
  scanf ("%" SCNi32 "%" SCNi32, &h, &w);
  char *s = ALLOC (h * w + 1, char);
  for (i32 i = 0; i < h; ++i) {
    scanf ("%s", s + i * w);
  }
  const i32 n = h * w;
  graph *g = new_graph (2 * n + 2);
  const i32 src = 2 * n;
  const i32 dst = src + 1;
  i32 cnt = 0;
  i32 d = 0;
  for (i32 i = 0; i < h; ++i) {
    for (i32 j = 0; j < w; ++j) {
      if (s[POS(i, j)] != '#') continue;
      cnt++;
      if (i + 1 < h && s[POS(i + 1, j)] == '#') {
        ++d;
        add_edge (g, src, POS(i, j), 1);
      }
      if (j + 1 < w && s[POS(i, j + 1)] == '#') {
        ++d;
        add_edge (g, n + POS(i, j), dst, 1);
      }
    }
  }
  for (i32 i = 0; i < h; ++i) {
    for (i32 j = 0; j < w; ++j) {
      add_edge (g, POS(i, j), n + POS(i, j), flow_inf);
      if (j > 0) {
        add_edge (g, POS(i, j), n + POS(i, j - 1), flow_inf);
      }
      if (i + 1 < h) {
        add_edge (g, POS(i, j), n + POS(i + 1, j), flow_inf);
      }
      if (i + 1 < h && j - 1 >= 0) {
        add_edge (g, POS(i, j), n + POS(i + 1, j - 1), flow_inf);
      }
    }
  }
  i32 ans = cnt - (d - dinic (g, src, dst));
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run();
  return 0;
}

