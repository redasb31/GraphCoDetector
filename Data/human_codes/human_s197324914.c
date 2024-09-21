// AOJ 1145: The Genome Database of All Space Life
// 2017.11.13 bal4u@uu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct { char *p; int n; } S;
S stack[102]; int top;
char buf[102];
char ans[1000003];

int main()
{
	int w, W, n, m, k;
	char *bp, *p, *q;

	while (scanf("%s%d", bp=buf, &w) && *bp != '0') {
		n = 0, p = ans, top = 0, W = w++;
		while (*bp) {
			if (isdigit(*bp)) {
				n = 0; while (isdigit(*bp)) n = (n<<3) + (n<<1) + (*bp++ & 0xf);
			} else if (*bp == '(') {
				bp++;
				stack[top].p = p, stack[top++].n = n;
				n = 0;
			} else if (*bp == ')') {
				bp++;
				q = stack[--top].p, k = p-q, m = stack[top].n;
				while (--m) {
					if (w - k < 0) k = w;
					memcpy(p, q, k), p += k; w -= k;
					if (w < 0) goto done;
				}
			} else {
				if (n > 0) { w -= n; while (n--) *p++ = *bp; bp++; }
				else while (isalpha(*bp)) *p++ = *bp++, w--;
				if (w < 0) goto done;
				n = 0;
			}
		}
done:	if (p-ans <= W) putchar('0');
		else putchar(ans[W]);
		putchar('\n');
	}
	return 0;

}