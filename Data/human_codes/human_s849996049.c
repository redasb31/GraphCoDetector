// AOJ 0330: Halting Problem
// 2017.10.25 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADDV	1
#define ADDC	2
#define SUBV	3
#define SUBC	4
#define SETV	5
#define SETC	6
#define IFV		7
#define HALT	8

typedef struct { int lin, cmd, v1, v2, v3, con, to; } T;
T pgm[52]; int n;

char var[26], f[26];
int lin[1002];
char tmp[10][26];

int check(int v)
{
	if (v < 0 || v >= 16) return 0;
	return 1;
}

int main()
{
	int i, pc, cnt;
	char cmd[10], b1[10], b2[10], b3[10];
	T *tp;

	memset(lin, -1, sizeof(lin));
	scanf("%d", &n);
	for (tp = pgm, i = 0; i < n; i++, tp++) {
		scanf("%d%s", &tp->lin, cmd); lin[tp->lin] = i;
		if (*cmd == 'H') tp->cmd = HALT;
		else if (*cmd == 'A' || (*cmd == 'S' && *(cmd+1) == 'U')) {
			scanf("%s%s%s", b1, b2, b3);
			if (*b3 <= '9') {
				tp->cmd = (*cmd == 'A') ? ADDC : SUBC;
				tp->v1 = *b1-'a', tp->v2 = *b2-'a', tp->con = atoi(b3);
				f[tp->v1] = f[tp->v2] = 1;
			} else {
				tp->cmd = (*cmd == 'A') ? ADDV : SUBV;
				tp->v1 = *b1-'a', tp->v2 = *b2-'a', tp->v3 = *b3-'a';
				f[tp->v1] = f[tp->v2] = f[tp->v3] = 1;
			}
		} else if (*cmd == 'S') {
			scanf("%s%s", b1, b2);
			tp->cmd = (*b2 <= '9') ? SETC : SETV;
			tp->v1 = *b1-'a', f[tp->v1] = 1;
			if (*b2 <= '9') tp->con = atoi(b2); else tp->v2 = *b2-'a', f[tp->v2] = 1;
		} else {		// IF
			scanf("%s%d", b1, &tp->to);
			tp->cmd = IFV, tp->v1 = *b1-'a', f[tp->v1] = 1;
		}
	}
	pc = 0, cnt = 0;
	while (1) {
		tp = pgm+pc;
		if (tp->cmd == ADDV) {
			if (!check(var[tp->v2] + var[tp->v3])) break;
			var[tp->v1] = var[tp->v2] + var[tp->v3];
		} else if (tp->cmd == ADDC) {
			if (!check(var[tp->v2] + tp->con)) break;
			var[tp->v1] = var[tp->v2] + tp->con;
		} else if (tp->cmd == SUBV) {
			if (!check(var[tp->v2] - var[tp->v3])) break;
			var[tp->v1] = var[tp->v2] - var[tp->v3];
		} else if (tp->cmd == SUBC) {
			if (!check(var[tp->v2] - tp->con)) break;
			var[tp->v1] = var[tp->v2] - tp->con;
		} else if (tp->cmd == SETV) {
			var[tp->v1] = var[tp->v2];
		} else if (tp->cmd == SETC) {
			var[tp->v1] = tp->con;
		} else if (tp->cmd == HALT) break;
		
		if (tp->cmd == IFV && tp->v1 != 0) {
			if (lin[tp->to] < 0) break;
			pc = lin[tp->to];
			if (cnt > 10) {
				for (i = 0; ; i++) {
					if (i == 10) { puts("inf"); return 0; }
					if (memcmp(tmp[i], var, sizeof(var)) != 0) break;
				}
				cnt = 0;
			} else memcpy(tmp[cnt++], var, sizeof(var));
		} else {
			pc++;
			if (pc == n) break;
		}
	}
	for (i = 0; i < 26; i++) if (f[i]) printf("%c=%d\n", i+'a', var[i]);
	return 0;
}