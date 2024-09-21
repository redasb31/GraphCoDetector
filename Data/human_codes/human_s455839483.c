// AOJ 1542: Yu-kun Likes Letters in the English Alphabet
// 2019.2.23 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

#define MAX 100003
char a[MAX]; int p[MAX];
int hi[MAX], *to[MAX];
int V, E;

int leastBit(int pat)
{
	int i = 0, a = 1;
	while (pat & a) i++, a <<= 1;
	return i;
}

int main()
{
	int i, j, f, s, t;
	int *memo, sz;

	V = in(), E = in(), f = 0;
	for (i = 0; i < V; i++) {
		j = gc(), gc();
		if (j != '?') a[i] = j;
		else f++;
	}
	if (f == 0) goto Done;
	if (f == V && V == 0) {
		while (f--) pc('a');
		pc('\n');
		return 0;
	}

	memo = malloc(E * 2 * sizeof(int)), sz = 0;
	for (i = 0; i < E; i++) {
		memo[sz++] = s = in(), memo[sz++] = in();
		hi[s]++;
	}
	for (i = 0; i < V; i++) if (hi[i]) to[i] = malloc(hi[i] * sizeof(int));

	memset(hi, 0, V * sizeof(int));
	sz = 0;
	for (i = 0; i < E; i++) {
		s = memo[sz++], t = memo[sz++];
		if (a[s]) p[t] |= 1 << (a[s] - 'a');
		if (a[t]) p[s] |= 1 << (a[t] - 'a');
		to[s][hi[s]++] = t;
	}
	free(memo);

	for (i = 0; i < V; i++) {
		if (a[i] == 0) a[i] = 'a' + leastBit(p[i]);
		for (j = 0; j < hi[i]; j++) p[to[i][j]] |= 1 << (a[i] - 'a');
	}

Done:
	for (i = 0; i < V; i++) pc(a[i]);
	pc('\n');
	return 0;
}
