// AOJ 2905: Colorful Drink
// 2019.2.23 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void ins(char *s)
{
	do *s = gc();
	while (*s++ > ' ');
	*(s - 1) = 0;
}


// 文字列のハッシュ関数
#define HASHSIZ 500009
typedef struct { char *s; int id; } HASH;
HASH hash[HASHSIZ + 2], *hashend = hash + HASHSIZ;

int insert(char *s, int id)
{
	unsigned long long i;
	int j;
	char *p;
	HASH *tp;

	i = 0, p = s;
	for (j = 0; *p && j < 12; j++) i = (i << 5) + *p++;
	tp = hash + (int)(i % HASHSIZ);
	while (tp->s != NULL) {
		if (!strcmp(tp->s, s)) return tp->id;
		if (++tp == hashend) tp = hash;
	}
	tp->s = s, tp->id = id;
	return -1;
}

int N, SZ;
char color[100005][22];
int idx[100005], hi[100005], *den[100005];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i, k, id, M;
	int *memo, sz;
	char buf[22];

	N = in();
	sz = 0, memo = malloc(N * 2 * sizeof(int));
	for (i = 0; i < N; i++) {
		ins(color[SZ]);
		if ((id = insert(color[SZ], SZ)) < 0) id = SZ++;
		hi[id]++;
		memo[sz++] = id, memo[sz++] = in();
	}

	for (id = 0; id < SZ; id++) if (hi[id])
		den[id] = malloc(hi[id] * sizeof(int));
	memset(hi, 0, SZ * sizeof(int));

	i = 0; while (i < sz) {
		id = memo[i++];
		den[id][hi[id]++] = memo[i++];
	}
	free(memo);

	for (id = 0; id < SZ; id++) qsort(den[id], hi[id], sizeof(int), cmp);

	k = 0, M = in();
	while (M--) {
		ins(buf);
		if ((id = insert(buf, SZ)) < 0) goto No;
		while (idx[id] < hi[id] && den[id][idx[id]] <= k) idx[id]++;
		if (idx[id] >= hi[id]) goto No;
		k = den[id][idx[id]++];
	}
	puts("Yes");
	return 0;
No:	puts("No");
	return 0;
}
