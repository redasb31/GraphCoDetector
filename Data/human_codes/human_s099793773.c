// AOJ 1281 The Morning after Halloween
// 2018.3.3 bal4u
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int  w, h;
char map[18][18];
int  n;
char sr[3], sc[3], gr[3], gc[3];
char r[3], c[3], nr[3], nc[3];
int  mv[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
short mk[16][16][16][16][16][16];

#define QMAX 300000
typedef struct { char r[3], c[3]; short t; } QUE;
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
	que[0] = que[--qsize];
	min_heapify(0);
}

void enq(short t)
{
	int i, j, min;
	QUE qt;

	if (t >= mk[nr[0]][nc[0]][nr[1]][nc[1]][nr[2]][nc[2]]) return;
	mk[nr[0]][nc[0]][nr[1]][nc[1]][nr[2]][nc[2]] = t;

	i = qsize++;
	for (j = 0; j < n; j++) que[i].r[j] = nr[j], que[i].c[j] = nc[j]; 
	que[i].t = t;
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

int check(int i, int j)
{
	if (nr[i] == nr[j] && nc[i] == nc[j]) return 1;
	if (r[i] == nr[j] && c[i] == nc[j] && r[j] == nr[i] && c[j] == nc[i]) return 1;
	return 0;
}

int dijkstra()
{
	int i, j, k, t, nt;

	memset(mk, 0x55, sizeof(mk));
	for (i = n; i < 3; i++) r[i] = c[i] = nr[i] = nc[i] = 0;
	for (i = 0; i < n; i++) nr[i] = sr[i], nc[i] = sc[i];
	qsize = 0;
	enq(0);

	while (qsize) {
		for (i = 0; i < n; i++) r[i] = que[0].r[i], c[i] = que[0].c[i];
		t = que[0].t, nt = t+1, deq();

		for (i = 0; ; i++) {
			if (i == n) return t;
			if (gr[i] != r[i] || gc[i] != c[i]) break;
		}

		if (mk[r[0]][c[0]][r[1]][c[1]][r[2]][c[2]] < t) continue;

		for (i = 0; i < 5; i++) {
			if (!i) nr[0] = r[0], nc[0] = c[0];
			else {
				nr[0] = r[0] + mv[i][0], nc[0] = c[0] + mv[i][1];
				if (map[nr[0]][nc[0]] == '#') continue;
			}

		if (n >= 2) for (j = 0; j < 5; j++) {
			if (!j) nr[1] = r[1], nc[1] = c[1];
			else {
				nr[1] = r[1] + mv[j][0], nc[1] = c[1] + mv[j][1];
				if (map[nr[1]][nc[1]] == '#') continue;
			}
			if (check(0, 1)) continue;

		if (n == 3) for (k = 0; k < 5; k++) {
			if (!k) nr[2] = r[2], nc[2] = c[2];
			else {
				nr[2] = r[2] + mv[k][0], nc[2] = c[2] + mv[k][1];
				if (map[nr[2]][nc[2]] == '#') continue;
			}
			if (check(1,2) || check(0,2)) continue;
			enq(nt);
		} else enq(nt);
		} else enq(nt);
		}
	}
	return -1;
}

int main()
{
	int i, r, c;
	char buf[20], *p;

	while (fgets(buf, 20, stdin) && *buf != '0') {
		sscanf(buf, "%d%d%d", &w, &h, &n);
		for (i = n; i < 3; i++) sr[i] = sc[i] = gr[i] = gc[i] = 0;
		for (r = 0; r < h; r++) {
			fgets(p=map[r], 18, stdin);
			for (c = 0; c < w; c++) {
				if (isalpha(*p)) {
					if (islower(*p)) gr[*p-'a'] = r, gc[*p-'a'] = c;
					else             sr[*p-'A'] = r, sc[*p-'A'] = c;
					*p = ' ';
				}
				p++;
			}
		}
		printf("%d\n", dijkstra());
	}
	return 0;
}
