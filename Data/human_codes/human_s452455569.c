// Aizu Vol-3 0355: String Game
// 2017.8.26 bal4u@uu

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *gets(char *);
char U[200010], *up;
char buf[30], *bp;

int getInt(void)
{
	int n = 0;
	while (isspace(*bp)) bp++;
	while (isdigit(*bp)) n = 10 * n + (*bp++ - '0');
	return n;
}

int cmp(char *a, char *as, char *b, char *bs)
{
	int x;
	while (a < as && b < bs) { if (x = *a++ - *b++) return x; }
	if (a == as && b == bs) return 0;
	return a == as ? -1 : 1;
}

int main()
{
	int N, Q, a, b, c, d;
	int cmd, x;

	gets(bp = buf), N = getInt();
	gets(U);
	gets(bp = buf), Q = getInt();
	while (Q-- > 0) {
		gets(bp = buf), cmd = *bp; while (isalpha(*bp)) bp++;
		if (cmd == 's') {
			a = getInt(), b = getInt(); while (isspace(*bp)) bp++; c = *bp;
			memset(U+a-1, c, b-a+1);
		} else {
			a = getInt(), b = getInt(), c = getInt(), d = getInt();
			x = cmp(U+a-1, U+b, U+c-1, U+d);
			if (!x) putchar('e');
			else putchar(x < 0 ? 's' : 't');
			putchar('\n');
		}
	}
	return 0;
}