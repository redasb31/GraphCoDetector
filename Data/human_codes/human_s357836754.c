//RE
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define max(a,b) (a > b ? a : b)

typedef struct queue{
  int a;
  int b;
  struct queue *next;
} queue;

char s[22][22];
int t[22][22];

void grid_init(int h) {
  for (int i=0; i<h; i++) scanf("%s", s[i]);
  for (int i=0; i<22; i++) {
    for (int j=0; j<22; j++) {
      if (s[i][j] == '.') continue;
      else s[i][j] = '#';
    }
  }
  return ;
}

//first element
queue *queue_init() {
  queue *q = malloc(sizeof(queue));
  q->next = NULL;
  return q;
}

queue *queue_create(int a, int b) {
  queue *q = malloc(sizeof(queue));
  q->a = a;
  q->b = b;
  q->next = NULL;
  return q;
}

void queue_free(queue *q) {
  if (q != NULL) free(q);
  return ;
}

bool queue_empty(queue *q) {
  if (q->next == NULL) return true;
  return false;
}

queue *queue_back(queue *q) {
  if (queue_empty(q)) return q;
  return queue_back(q->next);
}

queue *queue_front(queue *q) {
  if (queue_empty(q)) return NULL;
  return q->next;
}

void queue_pop(queue *q) {
  if (queue_empty(q)) return ;
  queue *qnext = q->next;
  q->next = qnext->next;
  queue_free(qnext);
  return ;
}

void queue_push(queue *q, int a, int b) {
  queue_back(q)->next = queue_create(a, b);
  return ;
}

void bfs_init() {
  for (int i=0; i<22; i++)
    for (int j=0; j<22; j++) t[i][j] = -1;
  return ;
}

void enqueue(queue *q, int a, int b)
{
  if (a > 0 && s[a - 1][b] == '.' && t[a - 1][b] == -1)
  {
    queue_push(q, a - 1, b);
    t[a - 1][b] = t[a][b] + 1;
  }
  if (s[a + 1][b] == '.' && t[a + 1][b] == -1)
  {
    queue_push(q, a + 1, b);
    t[a + 1][b] = t[a][b] + 1;
  }
  if (b > 0 && s[a][b - 1] == '.' && t[a][b - 1] == -1)
  {
    queue_push(q, a, b - 1);
    t[a][b - 1] = t[a][b] + 1;
  }
  if (s[a][b + 1] == '.' && t[a][b + 1] == -1)
  {
    queue_push(q, a, b + 1);
    t[a][b + 1] = t[a][b] + 1;
  }
  return ;
}

void bfs(queue *q ,int a,  int b) {
  enqueue(q, a, b);
  while (!queue_empty(q)) {
    queue *front = queue_front(q);
    int fa = front->a;
    int fb = front->b;
    queue_pop(q);
    enqueue(q, fa, fb);
  }
  return ;
}

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  grid_init(h);
  /*
  for (int i=0; i<25; i++) {
    for (int j=0; j<25; j++) printf("%c", s[i][j]);
    printf("\n");
  }
  */
  int ans = 0;
  queue *q = queue_init();
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (s[i][j] != '.') continue;
      bfs_init();
      t[i][j] = 0;
      bfs(q, i, j);
      for (int k=0; k<h; k++) {
        for (int l=0; l<w; l++) {
          if (s[k][l] == '.') ans = max(ans, t[k][l]);
          //printf("%d ", t[k][l]);
        }
        //printf("\n");
      }
      //printf("\n");
    }
  }
  queue_free(q);
  printf("%d\n", ans);
  return 0;
}
