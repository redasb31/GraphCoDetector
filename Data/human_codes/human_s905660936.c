// AOJ 1225: e-market
// 2017.10.25 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZ 2003
typedef struct { char *s; int id; } HASH;
HASH hash[HASHSIZ+2], *hashend = hash + HASHSIZ;			// Hash table

int lookup(char *s, int id)
{
	int w = strlen(s);
	int i = (101 * *s + 103 * *(s+w-1) + 107 * w) % HASHSIZ;
	HASH *tp = hash + i;

	while (tp->s != NULL) {
		if (!strcmp(tp->s, s)) return tp->id;
		if (++tp == hashend) tp = hash;
	}
	tp->s = s, tp->id = id;
	return -1;
}

typedef struct { int id, buy, m, p, fin; } T;
T tbl[1002]; int n;
typedef struct { int min, max, sum, n; } M;
M mono[26];
typedef struct { char *nm; int paid, got; } D;
D dealer[1002];
char dealerName[1002][12]; int sz;

int cmp(D *a, D *b) { return strcmp(a->nm, b->nm); }
int main()
{
	int i, j, id;
	char b1[10], b2[5];
	T *tp;

	while (scanf("%d", &n) && n > 0) {
		memset(hash, 0, sizeof(hash)); memset(mono, 0, sizeof(mono));
		for (sz = 0, tp = tbl, i = 0; i < n; i++, tp++) {
			scanf("%s%s%s%d", dealerName[sz], b1, b2, &tp->p);
			if ((id = lookup(dealerName[sz], sz)) < 0) {
				dealer[sz].nm = dealerName[sz], dealer[sz].paid = dealer[sz].got = 0;
				id = sz++;
			}
			tp->id = id, tp->buy = (*b1=='B'), tp->m = (*b2-'A'), tp->fin = 0;
		}

		for (i = 1; i < n; i++) {
			int buy, p, best, m, jj;
			if (tbl[i].fin) continue;
			buy = tbl[i].buy, m = tbl[i].m, p = tbl[i].p, best = -1;
			for (j = 0; j < i; j++) {
				if (tbl[j].id != tbl[i].id && tbl[j].buy != buy && tbl[j].m == m && !tbl[j].fin) {
					if (buy && tbl[j].p <= p) {
						if (best < 0 || best < tbl[j].p) best = tbl[j].p, jj = j;
					} else if (!buy && p <= tbl[j].p) {
						if (best < 0 || best > tbl[j].p) best = tbl[j].p, jj = j;
					}
				}
			}

			if (best >= 0) {
				tbl[i].fin = tbl[jj].fin = 1;
				best = (p + tbl[jj].p)/2;
				if (mono[m].n == 0) mono[m].min = mono[m].max = best;
				else {
					if      (best < mono[m].min) mono[m].min = best;
					else if (best > mono[m].max) mono[m].max = best;
				}
				mono[m].sum += best, mono[m].n++;
				id = tbl[jj].id;
				if (buy) dealer[id].got += best; else dealer[id].paid += best;
				id = tbl[i].id;
				if (buy) dealer[id].paid += best; else dealer[id].got += best;
			}
		}

		for (i = 0; i < 26; i++) if (mono[i].n > 0) {
			printf("%c %d %d %d\n", i+'A', mono[i].min, mono[i].sum/mono[i].n, mono[i].max);
		}
		puts("--");
		qsort(dealer, sz, sizeof(D), cmp);
		for (i = 0; i < sz; i++) {
			printf("%s %d %d\n", dealer[i].nm, dealer[i].paid, dealer[i].got);
		}
		puts("----------");
	}
	return 0;
}