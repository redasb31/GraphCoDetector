// AOJ 1245: Gap
// 2017.10.18 bal4u@uu

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define HASHSIZ 120011
unsigned hash[HASHSIZ+2], *hashend = hash + HASHSIZ;

// for hash tabel
int insert(unsigned x)
{
	unsigned *p = hash + x % HASHSIZ;
	while (*p) {
		if (*p == x) return 1;
		if (++p == hashend) p = hash;
	}
	*p = x;
	return 0;
}

typedef struct { char r, c; } P;
#define QMAX 70000
typedef struct { P gap[4]; char tbl[4][8]; int s; } Q;
Q q[QMAX+3]; int top, end;

char tbl[4][8];
P gap[4];

// check if finished, and calc hash value
unsigned check(char tbl[4][8])
{
	int r, c, v, f;
	unsigned x;

	for (x = 0, f = 0, v = 11, r = 0; r < 4; r++, v += 10) {
		for (c = 1; c < 7; c++) {
			x = (x << 1) + tbl[r][c];
			if (tbl[r][c] != v+c) f = 1;
		}
		x = (x << 1) + tbl[r][7];
	}
	if (f) return x;
	return 0;
}

int main()
{
	int t, i, r, c, r2, c2, v, s, ans;
	unsigned x;

	scanf("%d", &t);
	while (t-- > 0) {
		memset(hash, 0, sizeof(hash));
		for (r = 0; r < 4; r++) for (c = 1; c < 8; c++) scanf("%d", &v), tbl[r][c] = v;

		// initial layout
		for (i = 0, v = 11, r = 0; r < 4; r++, v += 10) {
			tbl[r][0] = v;
			for (c = 1; c < 8; c++)	if (tbl[r][c] % 10 == 1) {
				tbl[r][c] = 0, gap[i].r = r, gap[i++].c = c;
			}
		}
		if ((x = check(tbl)) == 0) { puts("0"); continue; }
		insert(x);

		ans = -1, top = 0, end = 1;
		memcpy(q[0].gap, gap, sizeof(gap)), memcpy(q[0].tbl, tbl, sizeof(tbl)), q[0].s = 0;

		while (top < end) {
			for (i = 0; i < 4; i++) {
				memcpy(gap, q[top].gap, sizeof(gap)),
				memcpy(tbl, q[top].tbl, sizeof(tbl)), s = q[top].s + 1;
				r = gap[i].r, c = gap[i].c;
				v = tbl[r][c-1]; if (v == 0 || v % 10 == 7) continue;
				v++;
				for (r2 = 0; r2 < 4; r2++) for (c2 = 1; c2 < 8; c2++) if (tbl[r2][c2] == v) {
					tbl[r2][c2] = 0, tbl[r][c] = v, gap[i].r = r2, gap[i].c = c2;
					goto next;
				}
		next:
				if ((x = check(tbl)) == 0) { ans = s; goto done; }
				if (insert(x)) continue;
				memcpy(q[end].gap, gap, sizeof(gap)), memcpy(q[end].tbl, tbl, sizeof(tbl)), q[end++].s = s;
			}
			++top;
		}
done:	printf("%d\n", ans);
	}
 	return 0;
}