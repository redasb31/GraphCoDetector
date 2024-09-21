#include <stdio.h>
#include <stdlib.h>
#define MOD 998244353

typedef struct edge {
  int to;
  struct edge *next;
} Edge;

typedef struct node {
  Edge *adj;
  int visited;
} Node;

void addEdge(Node *nodes, int from, int to) {
  Edge *newEdge = malloc(sizeof(Edge));
  newEdge->to = to;
  newEdge->next = nodes[from].adj;
  nodes[from].adj = newEdge;
}

int dfs(Node *nodes, int u) {
  nodes[u].visited = 1;
  int count = 1;
  for (Edge *e = nodes[u].adj; e; e = e->next) {
    if (!nodes[e->to].visited) {
      count += dfs(nodes, e->to);
    }
  }
  return count;
}

int main() {
  int N;
  scanf("%d", &N);

  Node *T = malloc(sizeof(Node) * (N + 1));
  Node *U = malloc(sizeof(Node) * (N + 1));

  for (int i = 0; i <= N; i++) {
    T[i].adj = NULL;
    U[i].adj = NULL;
  }

  // Read tree T
  for (int i = 1; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    addEdge(T, a, b);
    addEdge(T, b, a);
  }

  // Read tree U
  for (int i = 1; i < N; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    addEdge(U, c, d);
    addEdge(U, d, c);
  }

  int num_components_T = 0;
  int num_components_U = 0;
  int expected_product = 0;

  // Enumerate all possible combinations of removed vertices
  for (int mask = 0; mask < (1 << N); mask++) {
    // Reset visited flags
    for (int i = 1; i <= N; i++) {
      T[i].visited = 0;
      U[i].visited = 0;
    }

    // Calculate number of connected components in T
    num_components_T = 0;
    for (int i = 1; i <= N; i++) {
      if (!(mask & (1 << (i - 1))) && !T[i].visited) {
        num_components_T++;
        dfs(T, i);
      }
    }

    // Calculate number of connected components in U
    num_components_U = 0;
    for (int i = 1; i <= N; i++) {
      if ((mask & (1 << (i - 1))) && !U[i].visited) {
        num_components_U++;
        dfs(U, i);
      }
    }

    // Update expected product
    expected_product = (expected_product + num_components_T * num_components_U) % MOD;
  }

  // Calculate the probability of each combination
  int probability = 1;
  for (int i = 0; i < N; i++) {
    probability = (probability * 2) % MOD;
  }

  // Compute R
  int R = (expected_product * (probability - 1)) % MOD;
  printf("%d\n", R);

  free(T);
  free(U);
  return 0;
}