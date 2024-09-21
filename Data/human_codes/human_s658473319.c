#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int Max(int a, int b) {return a > b ? a : b;}

#define maxn 200005

char mon[maxn];
int val[maxn], mx[maxn], fst[maxn];
int fix[maxn];
int lson[maxn], rson[maxn], tot;

int new_node(int v) {
	int x = ++ tot;
	mon[x] = 1;
	val[x] = v; mx[x] = v; fst[x] = v;
	fix[x] = rand();
	lson[x] = rson[x] = 0;
	return x;
}

void pushup(int x, char mo) {
	fst[x] = lson[x] ? fst[lson[x]] : val[x];
	if (mo) {
		mon[x] = 1;
		mx[x] = rson[x] ? mx[rson[x]] : val[x];
	} else {
		mo = 1;
		mx[x] = val[x];
		if (lson[x]) {
			mx[x] = Max(mx[x], mx[lson[x]]);
			mo &= mon[lson[x]] && mx[lson[x]] < val[x];
		}
		if (rson[x]) {
			mx[x] = Max(mx[x], mx[rson[x]]);
			mo &= mon[rson[x]] && val[x] < fst[rson[x]];
		}
		mon[x] = mo;
	}
}

int merge(int a, int b, char mo) {
	if (!a || !b) return a | b;
	if (fix[a] < fix[b]) {
		rson[a] = merge(rson[a], b, mo);
		pushup(a, mo);
		return a;
	} else {
		lson[b] = merge(a, lson[b], mo);
		pushup(b, mo);
		return b;
	}
}

int split(int x, int v, int *a, int *b) {
	if (!x) {*a = *b = 0; return v;}
	if (mx[x] < v) {*a = x; *b = 0; return v;}
	if (mon[x]) {
		if (fst[x] > v) {*a = 0; *b = x; return mx[*b];}
		if (val[x] < v) {
			*a = x; split(rson[x], v, &rson[*a], b);
			pushup(*a, 1); return mx[*b];
		} else {
			*b = x; split(lson[x], v, a, &lson[*b]);
			pushup(*b, 1); return mx[*b];
		}
	} else {
		int ls = lson[x], rs = rson[x];
		lson[x] = rson[x] = 0;
		pushup(x, 1);
		v = split(ls, v, a, b);
		if (val[x] > v) *b = merge(*b, x, 1), v = val[x];
		else *a = merge(*a, x, 0);
		int c, d;
		v = split(rs, v, &c, &d);
		*a = merge(*a, c, 0); *b = merge(*b, d, 1);
		return v;
	}
}

int rt;

int main() {
//	freopen("in", "r", stdin);
	srand(time(NULL));
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int p; scanf("%d", &p);
		rt = merge(rt, new_node(p), 0);
	}
	int ans = 0;
	while (!mon[rt]) {
		++ ans;
		int a, b;
		split(rt, 0, &a, &b);
		rt = merge(a, b, 0);
//		printf("%d\n", ans);
	}
	printf("%d\n", ans);
//	eprintf("time used: %.3f\n", clock() * 1.0 / CLOCKS_PER_SEC);
	return 0;
}
