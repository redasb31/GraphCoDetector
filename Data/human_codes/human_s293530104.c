// AOJ 2570: Shipura
// 2017.12.1 bal4u@uu

#include <stdio.h>
#include <ctype.h>

#define M  1000000007
#define BASE -1
#define SFT  -2
#define S    -3

char buf[2000002], *p;
int stack[2000002], *top;

int main()
{
	int x, y;
	char *q;

	while (fgets(p=buf, sizeof(buf), stdin) && *p != '#') {
		top = stack, *top++ = BASE;
		while (*p >= ' ') {
			while (*p == ' ' || *p == '<') p++;
			if (*p == 'S') { p++, *top++ = S; continue; }
			if (*p == '>' && *(p+1) == '>') {
				q = p+2;
				while (*q == ' ') q++;
				if (*q == '>' || *q == '<' || *q < ' ');
				else { p = q, *top++ = SFT; continue; }
			}
			if (*p >= '0' && *p <= '9') {
				x = 0; while (*p >= '0' && *p <= '9')
					x = (x<<3) + (x<<1) + (*p++ & 0xf);
			} else {		//  '>'
				p++;
				x = *--top;
				x = (long long)x * x % M;
				top--;
			}
			if (*(top-1) == SFT) {
				top -= 2;
				y = *top;
				if (x > 31) y = 0; else y >>= x;
				x = y;
			}
			*top++ = x;
		}
		printf("%d\n", x);
	}
	return 0;
}