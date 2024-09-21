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
char tmp[110][26];

int check(int v)
{
	if (v < 0 || v >= 16) return 0;
	return 1;
}

int main()
{
	int i, pc, cnt;
	char cmd, b1[10], b2[10], b3[10];
	T *tp;

	memset(lin, -1, sizeof(lin));
	scanf("%d", &n);
	for (tp = pgm, i = 0; i < n; i++, tp++) {
		scanf("%d%s", &tp->lin, b1); lin[tp->lin] = i, cmd = *(b1+1);
		if (cmd == 'A') tp->cmd = HALT;
		else if (cmd == 'D' || cmd == 'U') {
			scanf("%s%s%s", b1, b2, b3);
			tp->v1 = *b1-'a', tp->v2 = *b2-'a', f[tp->v1] = f[tp->v2] = 1;
			if (*b3 >= 'a') {
				tp->cmd = (cmd == 'D') ? ADDV : SUBV;
				tp->v3 = *b3-'a', f[tp->v3] = 1;
			} else {
				tp->cmd = (cmd == 'D') ? ADDC : SUBC;
				tp->con = atoi(b3);
			}
		} else if (cmd == 'E') {
			scanf("%s%s", b1, b2);
			tp->v1 = *b1-'a', f[tp->v1] = 1;
			if (*b2 >= 'a') {
				tp->cmd = SETV;
				tp->v2 = *b2-'a', f[tp->v2] = 1;
			} else {
				tp->cmd = SETC;
				tp->con = atoi(b2);
			}
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
			if (!check(var[tp->v2])) break;
			var[tp->v1] = var[tp->v2];
		} else if (tp->cmd == SETC) {
			if (!check(tp->con)) break;
			var[tp->v1] = tp->con;
		} else if (tp->cmd == HALT) break;
		
		if (tp->cmd == IFV && var[tp->v1] != 0) {
			if (lin[tp->to] < 0) break;
			pc = lin[tp->to];
			if (cnt > 100) {
				for (i = 0; ; i++) {
					if (i == 100) { puts("inf"); return 0; }
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