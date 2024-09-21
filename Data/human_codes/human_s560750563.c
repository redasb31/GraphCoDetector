// AOJ 1322 ASCII Expression
// 2018.3.5 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define M	2011
int  n, W;
char buf[22][85], *p;

int expr(int bs, int tp, int bm);

int powmod(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		n >>= 1;
	}
	return ans;
}

int parse(int c, int tp, int bm)
{
	int bs;
	for ( ; c < W; c++) {
		for (bs = tp; bs < bm; bs++) if (buf[bs][c] != '.') goto done;
	}
done:
	p = buf[bs] + c;
	return expr(bs, tp, bm);
}

int primary(int bs, int tp, int bm)
{
	int x;
	if (*p == '(' && *(p+1) == '.') {
		p += 2, x = expr(bs, tp, bm), p += 2;
	} else x = *p++ & 0xf;
	return x;
}

int powexpr(int bs, int tp, int bm)
{
	int d;
	int x = primary(bs, tp, bm);
	if (tp <= bs-1 && *p > ' ' && isdigit(d=buf[bs-1][p-buf[bs]])) {
		x = powmod(x, d & 0xf), p++;
	}
	return x;
}

int factor(int bs, int tp, int bm)
{
	int x, c, si, bo;
	if (*p != '-') x = powexpr(bs, tp, bm);
	else {
		if (*(p+1) == '.') {
			p += 2;
			x = M - factor(bs, tp, bm);
			if (x >= M) x -= M;
		} else {
			c = p-buf[bs];
			si = parse(c, tp  , bs);
			bo = parse(c, bs+1, bm);
			p = buf[bs]+c;
			while (*p == '-') p++;
			x = (si * powmod(bo, M-2)) % M;
		}
	}
	return x;
}

int term(int bs, int tp, int bm)
{
	int x = factor(bs, tp, bm);
	while (*p == '.' && *(p+1) == '*' && *(p+2) == '.') {
		p += 3;
		x = (x * factor(bs, tp, bm)) % M;
	}
	return x;
}

int expr(int bs, int tp, int bm)
{
	char op;
	int x = term(bs, tp, bm), y;
	while (*p == '.' && (*(p+1) == '+' || *(p+1) == '-') && *(p+2) == '.') {
		op = *(p+1), p += 3;
		y = term(bs, tp, bm);
		if (op == '+') { x += y; if (x >= M) x -= M; }
		else           { x -= y; if (x < 0 ) x += M; }
	}
	return x;
}

int main()
{
	int r;

	while (fgets(p=buf[0], 10, stdin) && *p != '0') {
		n = atoi(buf[0]);
		for (r = 0; r < n; r++) {
			fgets(buf[r], 85, stdin);
			if (!r) { p = buf[0]; while (*p > ' ') p++; W = p-buf[0]; }
		}
		printf("%d\n", parse(0, 0, n));
	}
	return 0;
}
