#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M (MAX_N + 15)

typedef struct {
  int head;
  int tail;
} Queue;

typedef struct {
  int to;
  int next;
} Edge;

Edge edges[2 * MAX_M];
int head[MAX_N + 1];
int degree[MAX_N + 1];
int queue[MAX_N + 1];

int n, m;

void add_edge(int u, int v) {
  static int edge_count = 0;
  edges[edge_count].to = v;
  edges[edge_count].next = head[u];
  head[u] = edge_count++;
}

void init_queue(Queue *q) {
  q->head = 0;
  q->tail = 0;
}

void enqueue(Queue *q, int x) {
  queue[q->tail++] = x;
}

int dequeue(Queue *q) {
  return queue[q->head++];
}

int is_empty(Queue *q) {
  return q->head == q->tail;
}

void bfs(int start) {
  Queue q;
  init_queue(&q);
  enqueue(&q, start);
  degree[start] = -1; // Mark start as visited

  while (!is_empty(&q)) {
    int u = dequeue(&q);
    for (int i = head[u]; i != -1; i = edges[i].next) {
      int v = edges[i].to;
      if (degree[v] == 1) { // Cycle found!
        degree[v] = -1; // Mark v as visited
        degree[u] = -1; // Mark u as visited
        enqueue(&q, v); // Continue BFS from v
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);

  // Initialize adjacency list and degree array
  for (int i = 1; i <= n; i++) {
    head[i] = -1;
    degree[i] = 0;
  }

  // Read edges and update degree array
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
    degree[u]++;
    degree[v]++;
  }

  // Count the number of simple cycles
  int cycle_count = 0;
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 2) {
      bfs(i);
      cycle_count++;
    }
  }

  printf("%d\n", cycle_count);

  return 0;
}