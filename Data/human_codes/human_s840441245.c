// AOJ 2413: Tree Planting
// 2017.12.8 bal4u@uu

#include <stdio.h>

char m[1001][2005];
char sr[1001], sc[1001];

int main()
{
	int h, w, r, c;
	char buf[12], *p;

	fgets(buf, 12, stdin);
	sscanf(buf, "%d%d", &h, &w);
	for (r = 0; r < h; r++) {
		fgets(p=m[r], 2005, stdin);
		for (c = 0; c < w; c++, p+=2) {
			if (*p == '0') sr[c] = 1-sr[c], sc[r] = 1-sc[r];
		}
	}
	for (r = 0; r < h; r++) {
		p = m[r];
		if (*p & 1) putchar('0'+(sc[r]^sr[0]));
		else        putchar('1'-(sc[r]^sr[0]));
		for (c = 1; c < w; c++) {
			putchar(' ');
			p += 2;
			if (*p & 1) putchar('0'+(sc[r]^sr[c]));
			else 		putchar('1'-(sc[r]^sr[c]));
		}
		putchar('\n');
	}
	return 0;
}