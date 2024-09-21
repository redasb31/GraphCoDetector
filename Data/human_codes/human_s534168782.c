#include<stdio.h>
#include<stdlib.h>

struct edge {
  int a;
  int b;
  int weight;
};
int *ufp, *ufr;
struct edge *ed;

void downheap(int, int);
int UF_find(int);
void UF_union(int, int);
int Kruskal(int, int);

int main(void)
{
  int i, j, v, e, s, t, w, cost;
  scanf("%d %d", &v, &e);
  ufp = (int*)malloc(sizeof(int) * v);
  ufr = (int*)malloc(sizeof(int) * v);
  ed = (struct edge*)malloc(sizeof(struct edge) * e);
  for (i = 0; i < v; i++) {
    ufp[i] = i;
    ufr[i] = 0;
  }
  for (i = 0; i < e; i++) {
    scanf("%d %d %d", &s, &t, &w);
    ed[i].weight = w;
    ed[i].a = s;
    ed[i].b = t;
  }
  cost = Kruskal(v, e);
  printf("%d\n", cost);
  free(ufp);
  free(ufr);
  free(ed);
}

void downheap(int left, int right)
{
  int parent, child;
  struct edge root = ed[left];
  for (parent = left; parent < (right + 1) / 2 - 1; parent = child) {
    int l = 2 * parent + 1;
    if (ed[l].weight > ed[l + 1].weight && l + 1 <= right) child = l+1;
    else child = l;
    if (root.weight <= ed[child].weight) break;
    ed[parent] = ed[child];
  }
  ed[parent] = root;
}

int UF_find(int a)
{
  if (ufp[a] == a) return a;
  else {
    ufp[a] = UF_find(ufp[a]);
    return ufp[a];
  }
}

void UF_union(int a, int b)
{
  if (ufr[a] < ufr[b]) ufp[a] = b;
  else {
    ufp[b] = a;
    if (ufr[a] == ufr[b]) ufr[a]++;
  }
}

int Kruskal(int size, int esize)
{
  int i, selected = 0, cost = 0;
  for (i = esize / 2 - 1; i >= 0; i--) downheap(i, esize - 1);
  while (selected < size - 1) {
    int ea = UF_find(ed[0].a), eb = UF_find(ed[0].b);
    struct edge tmp = ed[0];
    if (ea != eb) {
      UF_union(ea, eb);
      cost += ed[0].weight;
      selected++;
    }
    ed[0] = ed[esize - 1];
    ed[esize - 1] = tmp;
    esize--;
    if (esize) downheap(0, esize - 1);
  }
  return cost;
}
