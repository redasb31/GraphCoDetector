// AOJ 1169 The Most Powerful Spell
// 2018.4.17 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QMAX 15000
typedef struct { char s; int t; char lab[405]; } QUE;
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

void enq(int s, int t, char *lab)
{
	int i, min;
	QUE qt;

	i = qsize++;
	que[i].s = s, que[i].t = t, strcpy(que[i].lab, lab);
	while (i > 0 && que[min = PARENT(i)].t > que[i].t) {
		qt = que[i], que[i] = que[min], que[min] = qt;
		i = min;
	}
}

// バッファ入力から数値を得る
char buf[20], *p;
int in()
{
	int n = 0;
	while (*p >= '0') n = 10*n + (*p++ & 0xf);
	p++;
	return n;
}

char hi[42], to[42][42];
char w[42][42]; char lab[42][42][8];
char dist[42][510][510];
char str[510], nstr[510], *ans;

char *dijkstra(int n, int start, int goal)
{
	int i, s, e, t, nt;

	for (s = 0; s < n; s++) for (i = 0; i < 400; i++) {
		dist[s][i][0] = 0x7e, dist[s][i][1] = 0;
	}
	qsize = 0;
	dist[start][0][0] = 0, enq(start, 0, "");
	while (qsize) {
		s = que[0].s, t = que[0].t, strcpy(str, que[0].lab), deq();
		if (strcmp(dist[s][t], str) < 0) continue;
		for (i = 0; i < hi[s]; i++) {
			e = to[s][i], nt = t + w[s][i];
			if (nt > 400) continue;
			memcpy(nstr, str, t), strcpy(nstr+t, lab[s][i]);
			if (strcmp(dist[e][nt], nstr) > 0) {
				strcpy(dist[e][nt], nstr);
				enq(e, nt, nstr);
			}
		}
	}
	str[0] = 0x7e, str[1] = 0, ans = str;
	for (i = 0; i < 400; i++) {
		if (strcmp(ans, dist[goal][i]) > 0) {
			if (i > 300) return NULL;
			ans = dist[goal][i];
		}
	}
	if (*ans == 0x7e) return NULL;
	return ans;
}

int main()
{
	int n, a, s, g, k, x, y;
	char *q;

	while (fgets(p=buf, 20, stdin) && *p != '0') {
		n = in(), a = in(), s = in(), g = in();
		memset(hi, 0, sizeof(hi));
		while (a--) {
			fgets(p=buf, 20, stdin);
			x = in(), y = in();
			k = hi[x]++;
			to[x][k] = y;
			q = lab[x][k]; while (*p > ' ') *q++ = *p++; *q = 0;
			w[x][k] = q - lab[x][k];
		}

		if ((q = dijkstra(n, s, g)) == NULL) puts("NO");
		else puts(q);
	}
	return 0;
}
