// AOJ 1080: Everything Starts With Your Vote
// 2018.2.4 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZ		200017
typedef struct { char *s; int id; } HASH;
HASH hash[HASHSIZ+2], *hashend = hash + HASHSIZ;			// Hash table

void insert(char *s, int w, int id)
{
	int i = (101 * *s + 103 * *(s+w-1) + 107 * w) % HASHSIZ;
	HASH *tp = hash + i;
	int inc = *s + (*(s + 1) << 1);

	while (tp->s != NULL) {
		if (!strcmp(tp->s, s)) return;
		tp += inc; if (tp >= hashend) tp -= HASHSIZ;
	}
	tp->s = s, tp->id = id;
}

int lookup(char *s, int w)
{
	int i = (101 * *s + 103 * *(s+w-1) + 107 * w) % HASHSIZ;
	HASH *tp = hash + i;
	int inc = *s + (*(s + 1) << 1);

	while (tp->s != NULL) {
		if (!strcmp(tp->s, s)) return tp->id;
		tp += inc; if (tp >= hashend) tp -= HASHSIZ;
	}
	return -1;
}

typedef struct { char *nm; int x; char fav; } T;
T tbl[100002], *fav;
char name[100002][22];
int N, M, K, L;

#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int cmp(T *a, T *b)
{
	if (a->fav - b->fav) return a->fav - b->fav;
	if (b->x - a->x) return b->x - a->x;
	return strcmp(a->nm, b->nm);
}

int check(int m)
{
	int i, f, x, base, sum;
	char *nm;

	base = K-m;
	if (base < 0) return 0;
	if (base >= N) return 1;
	sum = 0, nm = tbl[base].nm, base = tbl[base].x;
	for (i = 0; i < m; i++) {
		x = base - fav[i].x;
		if (x < 0) continue;
		f = (strcmp(fav[i].nm, nm) <= 0);
		if (!x && f) continue;
		sum += x; if (!f) sum++;
		if (sum > L) return 0;
	}
	return sum <= L;
}

int main()
{
	int i, lo, hi, mi;
	char buf[12], *p;

	while (N = in()) {
		M = in(), K = in(), L = in();
		memset(hash, 0, sizeof(hash));

		for (i = 0; i < N; i++) {
			fgets(name[i], 22, stdin);
			tbl[i].nm = p = name[i];
			while (*p > ' ') p++; *p = 0;
			insert(name[i], p-name[i], i);
			tbl[i].x = atoi(p+1), tbl[i].fav = 0;
		}
		for (i = 0; i < M; i++) {
			fgets(p=buf, 12, stdin);
			while (*p > ' ') p++; *p = 0;
			tbl[lookup(buf, p-buf)].fav = 1;
		}
		qsort(tbl, N, sizeof(T), cmp);
		fav = tbl + N - M, N -= M;

		lo = 0;
		hi = M; if (hi > K) hi = K; hi++;
		while (hi-lo > 1) {
			mi = (lo + hi) >> 1;
			if (check(mi)) lo = mi; else hi = mi;
		}
		printf("%d\n", lo);
	}
	return 0;
}
