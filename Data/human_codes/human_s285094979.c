#include<stdio.h>
#include<stdlib.h>

struct node {
  int id;
  struct node *next;
};
struct pair {
  int x;
  int y;
};
struct node **list;
struct pair *art;
int *seq, counter,sp;

void Insert(int, int);
int Biconnected(int, int);
void qsort1(int, int);
int main(void)
{
  int i, j, v, e, s, t;
  scanf("%d %d", &v, &e);
  list = (struct node**)malloc(sizeof(struct node*) * v);
  art = (struct pair*)malloc(sizeof(struct pair) * e);
  seq = (int*)calloc(v, sizeof(int));
  for (i = 0; i < v; i++) {
    list[i] = NULL;

  }
  for (i = 0; i < e; i++) {
    scanf("%d %d", &s, &t);
    Insert(s,t);
  }
  Biconnected(0, -1);
  qsort1(0, sp - 1);
  for (i = 0; i < sp; i++) printf("%d %d\n", art[i].x, art[i].y);
  for (i = 0; i < v; i++) {
    free(list[i]);
  }
  free(list);
  free(seq);
  free(art);
}
void Insert(int a, int b)
{
  struct node *p = (struct node*)malloc(sizeof(struct node));
  p->id = b;
  p->next = list[a];
  list[a] = p;
  p = (struct node*)malloc(sizeof(struct node));
  p->id = a;
  p->next = list[b];
  list[b] = p;
}
int Biconnected(int point, int pre)
{
  int min;
  struct node *n;
  counter++;
  seq[point] = counter;
  min = counter;
  for(n = list[point]; n != NULL; n = n->next) {
    if (!seq[n->id]) {
      int m;
      m = Biconnected(n->id, point);
      if (m < min) min = m;
      if (m > seq[point]) {
        if (point < n->id) {
          art[sp].x = point;
          art[sp].y = n->id;
        } else {
          art[sp].x = n->id;
          art[sp].y = point;
        }
        sp++;
      }
    } else if (n->id != pre) {
      if (seq[n->id] < min) {
        min = seq[n->id];
      }
    }
  }
  return min;
}
void qsort1(int left, int right) {
  struct pair pivot = art[(left + right) / 2];
  int i = left, j = right;
  if (left >= right) return;
  do{
    while (1) {
      if (art[i].x > pivot.x || (art[i].x == pivot.x && art[i].y >= pivot.y)) break;
      i++;
    }
    while (1) {
      if (art[j].x < pivot.x || (art[j].x == pivot.x && art[j].y <= pivot.y)) break;
      j--;
    }
    if (i <= j) {
      struct pair temp = art[i];
      art[i] = art[j];
      art[j] = temp;
      i++;
      j--;
    }
  }while(i <= j);
  qsort1(left, j);
  qsort1(i, right);
}
