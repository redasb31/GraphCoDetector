// Aizu 1111: Cyber Guardian
// 2017.9.13 bal4u@uu

#include <stdio.h>

#define PERMIT 1
#define DENY 0
#define UNKNOWN 2

typedef struct { int p; char s[10], d[10]; } FW;
FW fw[1050];

typedef struct { int p; char s[10], d[10], m[52]; } PK;
PK pk[1050];

int match(char *add, char *pat)
{
	int i;
	for (i = 0; i < 8; i++) if (pat[i] != '?' && pat[i] != add[i]) return 0;
	return 1;
}

int main()
{
	int n, m, i, j, s, d;
	char rule[10], *ss, *dd;

	while (scanf("%d%d", &n, &m) && (n|m)) {
		for (i = 0; i < n; i++)
			scanf("%s%s%s", rule, fw[i].s, fw[i].d), fw[i].p = *rule == 'p';
		for (i = 0; i < m; i++)
			scanf("%s%s%s", pk[i].s, pk[i].d, pk[i].m);
		for (i = 0; i < m; i++) {
			s = d = UNKNOWN, pk[i].p = 0, ss = pk[i].s, dd = pk[i].d;
			for (j = n-1; j >= 0; j--) {
				if (fw[j].p) {
					int sf, df;
					sf = match(ss, fw[j].s); if (sf) s = PERMIT;
					df = match(dd, fw[j].d); if (df) d = PERMIT;
					if (s == PERMIT && d == PERMIT) { pk[i].p = 1; break; }
				} else {
					int sf, df;
					sf = match(ss, fw[j].s); if (sf) s = DENY;
					df = match(dd, fw[j].d); if (df) d = DENY;
					if (s == DENY && d == DENY) break;
				}
			}
		}
		for (s = i = 0; i < m; i++) s += pk[i].p; printf("%d\n", s);
		for (i = 0; i < m; i++) if (pk[i].p)
			printf("%s %s %s\n", pk[i].s, pk[i].d, pk[i].m);
	}
	return 0;
}