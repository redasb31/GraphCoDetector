// AOJ 2564 Tree Reconstruction
// 2018.5.7 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 505

/* UNION-FIND library */
int id[MAX_V], size[MAX_V];
void init(int n) { int i; for (i = 0; i < n; i++) id[i] = i, size[i] = 1; }
int root(int i) { while (i != id[i]) id[i] = id[id[i]], i = id[i]; return i; }
int connected(int p, int q) { return root(p) == root(q); }
void unite(int p, int q)
{
    int i = root(p), j = root(q); if (i == j) return;
    if (size[i] < size[j]) id[i] = j, size[j] += size[i]; else id[j] = i, size[i] += size[j];
}

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

int main()
{
	int n, m, s, t, i, ans;

	n = in(), m = in();
	init(n);
	for (i = 0; i < m; i++) {
		s = in()-1, t = in()-1;
		unite(s, t);
	}
	
	ans = m-n;
	for (i = 0; i < n; i++) {
		if (root(i) == i) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

