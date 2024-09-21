// AOJ 1565 Squid Ink
// 2018.2.16 bal4u

#include <stdio.h>
#include <string.h>

#define QMAX 10000
typedef struct { char r, c; int t; } QUE;
QUE que[QMAX]; int qsize;

#define PARENT(i) ((i)>>1)
#define LEFT(i)   ((i)<<1)
#define RIGHT(i)  (((i)<<1)+1)

void min_heapify(int i)
{
	int l, r, min;
	QUE qt;

	l = LEFT(i), r = RIGHT(i);
	if (l < qsize && que[l].t < que[i].t) min = l; else min = i;
	if (r < qsize && que[r].t < que[min].t) min = r;
	if (min != i) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		min_heapify(min);
	}
}

void deq()
{
//	if (qsize == 0) return 0;
//	*n = que[0].node, *t = que[0].t, *c = que[0].c;
	que[0] = que[--qsize];
	min_heapify(0);
}

void enq(char r, char c, int t)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].r = r, que[i].c = c, que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

#define INF  0x10101010
char map[33][33];
int dist[33][33];
int mv[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main() 
{
	int R, C, i, j, r, c, nr, nc, d;
	int sr, sc, gr, gc;
	char buf[10];

	fgets(buf, 10, stdin), sscanf(buf, "%d%d", &R, &C);
	sr = gr = -1;
	for (r = 0; r < R; r++) {
		fgets(map[r], 33, stdin);
		if (sr >= 0 && gr >= 0) continue;
		for (c = 0; c < C; c++) {
			if      (map[r][c] == 'S') map[r][c] = '.', sr = r, sc = c;
			else if (map[r][c] == 'G') map[r][c] = '.', gr = r, gc = c;
		}
	}

	memset(dist, INF, sizeof(dist));
	qsize = 0;
	enq(sr, sc, 0), dist[sr][sc] = 0;
	while (qsize) {
		r = que[0].r, c = que[0].c, deq();
		d = dist[r][c];

		if (r == gr && c == gc) break;

		for (i = 0; i < 4; i++) {
			nr = r + mv[i][0], nc = c + mv[i][1];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (map[nr][nc] == 'o') {
				if (dist[nr][nc] > d + 1) dist[nr][nc] = d + 1, enq(nr, nc, d+1);
			} else if (map[nr][nc] == '.') {
				if (dist[nr][nc] > d + 2) dist[nr][nc] = d + 2, enq(nr, nc, d+2);
			}
		}

		for (i = 0; i < 4; i++) {
			nr = r, nc = c;
			for (j = 0; j < 3; j++) {
				nr += mv[i][0], nc += mv[i][1];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (map[nr][nc] == '#') break;
				if (dist[nr][nc] > d+3+j) {
					dist[nr][nc] = d+3+j, enq(nr, nc, d+3+j);
				}
			}
		}
	}
	printf("%d\n", d);
	return 0;
}

