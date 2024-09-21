// AOJ 1584: Sum of Sequences
// 2017.11.17 bal4u@uu

#include <stdio.h>
#include <string.h>

int ab[40002];
int aa[200002], bb[200002], amin, amax, bmin, bmax;
char c[200002]; int ans[200002];
char buf[80010], *p;

int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int n, m, q, i, j;
	int v, s;

	fgets(p=buf, 30, stdin), n = getint(), p++, m = getint(), p++, q = getint();

	fgets(p=buf, 80010, stdin);
	for (i = 1; i <= n; i++) ab[i] = ab[i-1] + getint(), p++;
	amin = amax = ab[1];
	for (i = 1; i <= n; i++) for (j = 0; j < i; j++) {
		v = ab[i]-ab[j], aa[v]++;
		if (v < amin) amin = v;
		else if (v > amax) amax = v;
	}

	fgets(p=buf, 80010, stdin);
	for (i = 1; i <= m; i++) ab[i] = ab[i-1] + getint(), p++;
	bmin = bmax = ab[1];
	for (i = 1; i <= m; i++) for (j = 0; j < i; j++) {
		v = ab[i]-ab[j], bb[v]++;
		if (v < bmin) bmin = v;
		else if (v > bmax) bmax = v;
	}

	while (q--) {
		fgets(p=buf, 10, stdin);
		v = getint();
		if (c[v]) { printf("%d\n", ans[v]); continue; }
		for (s = 0, i = amin; i <= amax; i++) {
			if (i-v >= bmin && bb[i-v]) s += aa[i] * bb[i-v];
			if (i+v <= bmax && bb[i+v]) s += aa[i] * bb[i+v];
		}
		ans[v] = s; printf("%d\n", ans[v]);
	}
	return 0;
}