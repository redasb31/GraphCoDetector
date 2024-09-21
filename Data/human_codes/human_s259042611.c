#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

void rand_qsort_memcpy (uint8_t * restrict dst, uint8_t * restrict src, size_t size) {
  while (size--) {
    *dst++ = *src++;
  }
}

uint32_t rand_qsort_rand (void) {
  static uint32_t y = 2463534242;
  y = y ^ (y << 13);
  y = y ^ (y >> 17);
  return y = y ^ (y << 5);
}

void rand_qsort (void * const array, const size_t num, const size_t size, int (* const cmp) (const void *, const void *)) {
  typedef struct operation {
    size_t l;
    size_t r;
  } op;
  uint8_t * const a = (uint8_t *) array;
  uint8_t * const tmp = (uint8_t *) malloc (2 * size);
  uint8_t * const pivot = tmp + size;
  op stack[64];
  int32_t top = 0;
  stack[top++] = (op) {0, num};
  while (top > 0) {
    const op t = stack[--top];
    if (t.l + 1 >= t.r) continue;
    const size_t p = rand_qsort_rand() % (t.r - t.l) + t.l;
    rand_qsort_memcpy (pivot, a + p * size, size);
    rand_qsort_memcpy (a + p * size, a + t.l * size, size);
    size_t l = t.l * size + size;
    size_t r = t.r * size;
    const size_t m = (t.l + t.r) / 2 * size;
    while (l < r) {
      int c = cmp (a + l, pivot);
      if (c < 0 || (c == 0 && l < m)) {
        rand_qsort_memcpy (a + l - size, a + l, size);
        l += size;
      } else {
        r -= size;
        rand_qsort_memcpy (tmp, a + l, size);
        rand_qsort_memcpy (a + l, a + r, size);
        rand_qsort_memcpy (a + r, tmp, size);
      }
    }
    rand_qsort_memcpy (a + l - size, pivot, size);
    if (l - size - t.l * size >= t.r * size - r) {
      stack[top++] = (op) {t.l, l / size - 1};
      stack[top++] = (op) {r / size, t.r};
    } else {
      stack[top++] = (op) {r / size, t.r};
      stack[top++] = (op) {t.l, l / size - 1};
    }
  }
  free (tmp);
}

typedef int32_t deque_val;

typedef struct Deque {
  deque_val *array;
  size_t front;
  size_t last;
  size_t mask;
} deque;

deque* new_deque (void) {
  const size_t len = 2;
  deque *d = (deque *) calloc (len, sizeof (deque));
  d->array = (deque_val *) calloc (len, sizeof (deque_val));
  d->front = d->last = 0;
  d->mask = len - 1;
  return d;
}

int is_empty (const deque *d) {
  return d->front == d->last;
}

void deque_realloc (deque * const d) {
  deque_val *array = (deque_val *) calloc (2 * (d->mask + 1), sizeof (deque_val));
  size_t k = 0;
  for (size_t i = d->front; i != d->last; i = (i + 1) & d->mask) {
    array[k++] = d->array[i];
  }
  free (d->array);
  d->array = array;
  d->front = 0;
  d->last = k;
  d->mask = 2 * d->mask + 1;
}

deque_val pop_front (deque * const d) {
  deque_val res = d->array[d->front];
  d->front = (d->front + 1) & d->mask;
  return res;
}

void push_front (deque * const d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  d->front = (d->front + d->mask) & d->mask;
  d->array[d->front] = v;
}

void push_back (deque * const d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  d->array[d->last] = v;
  d->last = (d->last + 1) & d->mask;
}

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

typedef int32_t i32;

static i32 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i32 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct color_vertex {
  i32 c, v;
} node;

int cmp_node (const void *a, const void *b) {
  const node *p = (const node *)a;
  const node *q = (const node *)b;
  i32 d = p->v - q->v;
  if (d != 0) return d < 0 ? -1 : 1;
  d = p->c - q->c;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 to_index (const node *z, const i32 n, const node v) {
  i32 l = 0; 
  i32 r = n;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (cmp_node (&v, z + m) >= 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  i32 *p = (i32 *) calloc (3 * m, sizeof (i32));
  i32 *q = p + m;
  i32 *c = q + m;
  node *z = (node *) calloc (2 * m + n, sizeof (node));
  for (i32 i = 0; i < m; ++i) {
    p[i] = read_int();
    q[i] = read_int();
    c[i] = read_int();
    z[2 * i] = (node) {c[i], p[i]};
    z[2 * i + 1] = (node) {c[i], q[i]};
  }
  for (i32 i = 0; i < n; ++i) {
    z[2 * m + i] = (node) {0, i + 1};
  }
  rand_qsort (z, 2 * m + n, sizeof (node), cmp_node);
  i32 len = 1;
  for (i32 i = 1; i < 2 * m + n; ++i) {
    if (cmp_node (z + len - 1, z + i) == 0) continue;
    z[len++] = z[i];
  }
  graph *g = new_graph (len);
  for (i32 i = 0; i < m; ++i) {
    i32 s = to_index (z, len, (node) {c[i], p[i]});
    i32 t = to_index (z, len, (node) {c[i], q[i]});
    add_edge (g, s, t);
    add_edge (g, t, s);
  }
  free (p);
  for (i32 i = 0; i < len; ++i) {
    if (z[i].c != 0) continue;
    for (i32 j = i + 1; j < len && z[j].v == z[i].v; ++j) {
      add_edge (g, i, j);
      add_edge (g, j, i);
    }
  }
  const i32 inf = n + 1;
  i32 *dp = (i32 *) calloc (len, sizeof (i32));
  uint8_t *used = (uint8_t *) calloc (len, sizeof (uint8_t));
  for (i32 i = 1; i < len; ++i) {
    dp[i] = inf;
  }
  deque *d = new_deque();
  push_back (d, 0);
  while (!is_empty (d)) {
    const i32 v = pop_front (d);
    if (used[v]) continue;
    used[v] = 1;
    i32 cost = dp[v] + (z[v].c == 0 ? 1 : 0);
    if (cost > dp[v]) {
      for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
        i32 u = g->edge[p].vertex;
        if (cost >= dp[u]) continue;
        dp[u] = cost;
        push_back (d, u);
      }
    } else {
      for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
        i32 u = g->edge[p].vertex;
        if (cost >= dp[u]) continue;
        dp[u] = cost;
        push_front (d, u);
      }
    }
  }
  for (i32 i = len - 1; i >= 0; --i) {
    if (cmp_node (z + i, &((node) {0, n})) != 0) continue;
    printf ("%" PRIi32 "\n", dp[i] == inf ? -1 : dp[i]);
  }
}

int main (void) {
  run();
  return 0;
}
