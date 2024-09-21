// AOJ 2544: Older Research Bldg. No.7
// 2017.10.5 bal4u@uu

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { int y; char nm[32]; } T;
T tbl[52];

int cmp(T *a, T *b) { return a->y - b->y; }

int main()
{
	int n, q, i;

	tbl[0].y = 1, strcpy(tbl[0].nm, "kogakubu10gokan");
	scanf("%d%d", &n, &q); n++;
	for (i = 1; i < n; i++) scanf("%d%s", &tbl[i].y, tbl[i].nm);
	qsort(tbl, n, sizeof(T), cmp);
	for (i = 1; i < n; i++) if (tbl[i].y > q) break;
	printf("%s\n", tbl[i-1].nm);
	return 0;
}