// Aizu 1078: SAT-EN-3
// 2017.9.17 bal4u@uu

#include <stdio.h>
#include <string.h>

char exp[510], *p;
char tbl['z'];

int literal(int *v)
{
	*v = 1; if (*p == '~') *v = -1, p++;
	return *p++;
}

int clause()
{
	int x, v, f = 1;

	memset(tbl, 0, sizeof(tbl));
	x = literal(&v), tbl[x] = v;
	while (1) {
		if (*p != '&') break;
		p++;
		x = literal(&v);
		if (tbl[x] + v == 0) f = 0;
		tbl[x] = v;
	}
	return f;
}

int expression()
{
	p++; if (clause()) return 1; p++;
	while (1) {
		if (*p != '|') break;
		p++; p++; if (clause()) return 1; p++;
	}
	return 0;
}

int main()
{
	while (1) {
		fgets(p = exp, 505, stdin); if (*p == '#') break;
		puts(expression() ? "yes" : "no");
	}
	return 0;
}