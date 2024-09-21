#include <stdio.h>
#include <string.h>
#include <math.h>
#define NMAX 100
#define INF 1e8
#define EPS 1e-8
#define min(a, b) ((a) < (b) ? (a) : (b))
struct node {
  int id;
  int weight;
};
int dist[NMAX], len[NMAX], heap[NMAX], heap_index[NMAX], heapsize;
struct node list[NMAX][NMAX];
void downheap(int k);
void upheap(int j);
void dijkstra(int t, int size);
void gauss_jordan(double (*A)[NMAX], double *b, int size);
int main(void)
{
  int i, j, n, s, t, q[NMAX];
  double A[NMAX][NMAX], B[NMAX];
  while (scanf("%d %d %d", &n, &s, &t), (n != 0 && s != 0 && t != 0)) {
    s--;
    t--;
    for (i = 0; i < n; i++) scanf ("%d", &q[i]);
    for (i = 0; i < n; i++) {
      len[i] = 0;
      for (j = 0; j < n; j++) {
        int temp;
        A[i][j] = 0;
        scanf("%d", &temp);
        if (temp) {
          list[i][len[i]].id = j;
          list[i][len[i]++].weight = temp;
        }
      }
      A[i][i] = 1.0;
      B[i] = 0;
    }
    dijkstra(t, n);
    if (dist[s] == INF) {
      printf("impossible\n");
      continue;
    }
    for (i = 0; i < n; i++) {
      int move = 0, sum = 0;
      if (i == t) continue;
      else if (q[i] == 1) {
        int best = INF;
        for (j = 0; j < len[i]; j++) best = min(best, list[i][j].weight + dist[list[i][j].id]);
        if (best == INF) continue;
        for (j = 0; j < len[i]; j++) {
          if (best == list[i][j].weight + dist[list[i][j].id]) {
            move++;
            A[i][list[i][j].id] = -1;
            sum += list[i][j].weight;
          }
        }
        A[i][i] = move;
        B[i] = sum;
      } else {
        move = len[i];
        A[i][i] = move;
        if (move == 0) continue;
        for (j = 0; j < len[i]; j++) {
          A[i][list[i][j].id] = -1;
          sum += list[i][j].weight;
        }
        B[i] = sum;
      }
    }
    gauss_jordan(A, B, n);
    printf("%.15f\n", B[s]);
  }
}

void downheap(int k)
{
  int j, v = heap[k];
  while (k < heapsize / 2) {
    j = 2 * k + 1;
    if (j < heapsize - 1 && dist[heap[j]] > dist[heap[j + 1]]) j++;
    if (dist[v] <= dist[heap[j]]) break;
    heap[k] = heap[j];
    heap_index[heap[j]] = k;
    k = j;
  }
  heap[k] = v;
  heap_index[v] = k;
}

void upheap(int j)
{
  int k, v = heap[j];
  while (j > 0) {
    k = (j + 1) / 2 - 1;
    if (dist[v] >= dist[heap[k]]) break;
    heap[j] = heap[k];
    heap_index[heap[k]] = j;
    j = k;
  }
  heap[j] = v;
  heap_index[v] = j;
}

void dijkstra(int t, int size)
{
  int i, u;
  heapsize = size;
  for (i = 0; i < size; i++) {
    heap[i] = i;
    heap_index[i] = i;
    dist[i] = INF;
  }
  dist[t] = 0;
  for (i = size / 2 - 1; i >= 0; i--) downheap(i);
  while (heapsize > 0) {
    u = heap[0];
    heap[0] = heap[heapsize - 1];
    heap_index[heap[heapsize - 1]] = 0;
    heapsize--;
    downheap(0);
    for (i = 0; i < len[u]; i++) {
      int w = list[u][i].weight, newlen = dist[u] + w;
      if (newlen < dist[list[u][i].id]) {
        dist[list[u][i].id] = newlen;
        upheap(heap_index[list[u][i].id]);
      }
    }
  }
}

void gauss_jordan(double (*A)[NMAX], double *b, int size)
{
  int i, j, k;
  double B[size][size+1];
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      B[i][j] = A[i][j];
    }
  }
  for (i = 0; i < size; i++) B[i][size] = b[i];
  for (i = 0; i < size; i++) {
    int pivot = i;
    for (j = i; j < size; j++) {
      if (fabs(B[j][i]) > fabs(B[pivot][i])) pivot = j;
    }
    for (j = 0; j <= size; j++) {
      double temp = B[i][j];
      B[i][j] = B[pivot][j];
      B[pivot][j] = temp;
    }
    if (fabs(B[i][i]) < EPS) continue;
    for (j = i + 1; j <= size; j++) B[i][j] /= B[i][i];
    for (j = 0; j < size; j++) {
      if (i != j) {
        for (k = i + 1; k <= size; k++) B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }
  for (i = 0; i < size; i++) b[i] = B[i][size];
}
