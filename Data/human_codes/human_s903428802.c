// Aizu 0215: Pachimon Creature
// 2017.9.9 bal4u@uu

#include <stdio.h>
#include <string.h>

#define abs(a)  ((a)>=0?(a):-(a))
#define INF 0x7fffffff
#define MAX 50000
typedef struct { int t, r, c, k; } QUE;
QUE que[MAX]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
  int l, r;
  int smallest;

  l = LEFT(i), r = RIGHT(i);
  if (l < qsize && que[l].t < que[i].t) smallest = l; else smallest = i;
  if (r < qsize && que[r].t < que[smallest].t) smallest = r;
  if (smallest != i) {
    QUE t = que[i]; que[i] = que[smallest]; que[smallest] = t;
    min_heapify(smallest);
  }
}

int deq(int *r, int *c, int *k)
{
  if (qsize == 0) return 0;
  *r = que[0].r, *c = que[0].c, *k = que[0].k;
  que[0] = que[--qsize];
  min_heapify(0);
  return 1;
}

void enq(int r, int c, int t, int k)
{
  int i, ii;

  i = qsize++;
  que[i].r = r, que[i].c = c, que[i].t = t, que[i].k = k;
  while (i > 0 && que[ii = PARENT(i)].t > que[i].t) {
    QUE tt = que[i]; que[i] = que[ii]; que[ii] = tt;
    i = ii;
  }
}

typedef struct { int r, c; } TBL;
TBL start, goal, tbl[5][1002]; int len[5];
int node[1002][1002][5];
char map[1002][1002]; int w, h;

int search(int item)
{
	int r, c, r2, c2, i, k, fin, f, f2;
	TBL *tp;

	qsize = 0;
	memset(node, -1, sizeof(node));
	fin = (item + 4) % 5;
	node[start.r][start.c][item] = 0;
	enq(start.r, start.c, 0, item);
	while(deq(&r, &c, &f)) {
		if (r == goal.r && c == goal.c) continue;
		f2 = f + 1; if (f2 >= 5) f2 = 0;
		if (f == fin) {
			r2 = goal.r, c2 = goal.c;
			k = node[r][c][f] + abs(r2 - r) + abs(c2 - c);
			if (node[r2][c2][f] < 0 || k < node[r2][c2][f]) node[r2][c2][f] = k, enq(r2, c2, k, f);
		} else for (tp = tbl[f2], i = 0; i < len[f2]; i++, tp++) {
			r2 = tp->r, c2 = tp->c;
			k = node[r][c][f] + abs(r2 - r) + abs(c2 - c);
			if (node[r2][c2][f2] < 0 || k < node[r2][c2][f2]) node[r2][c2][f2] = k, enq(r2, c2, k, f2); 
		}
	}
	return node[goal.r][goal.c][fin];
}

int main()
{
	int r, c, i, ii, ans, f[5], s, g, k;

	while (scanf("%d%d", &w, &h) && w) {
		for (r = 0; r < h; r++) scanf("%s", map[r]);
		memset(len, 0, sizeof(len)), memset(f, 0, sizeof(f));
		for (s = g = r = 0; r < h; r++) for (c = 0; c < w; c++) {
			char cc = map[r][c];
			if      (cc == 'S') start.r = r, start.c = c, s = 1;
			else if (cc == 'G') goal.r = r, goal.c = c, g = 1;
			else if (cc >= '1' && cc <= '5') {
				cc -= '1', f[cc] = 1;
				tbl[cc][len[cc]].r = r, tbl[cc][len[cc]].c = c, len[cc]++;
			}
		}
		for (k = 0, i = 0; i < 5; i++) { k += f[i]; if (!f[i]) ii = i; }
		if (!s || !g || k < 4) puts("NA");
		else {
			int k1, k2;
			if (k == 4) k1 = k2 = ii; else k1 = 1, k2 = 4;
			for (ans = INF, i = k1; i <= k2; i++) if ((k = search(i)) < ans) ans = k, ii = i;
			printf("%d %d\n", ii+1, ans);
		}
	}
	return 0;
}