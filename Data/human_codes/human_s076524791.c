// AOJ 	2529: Brainf*ck
// 2018.2.7 bal4u
 
#include <stdio.h>
#include <math.h>

#define ABS(a)	((a)>=0?(a):-(a))

char s[1003];
int memo[16];
char c4d[2] = {'-','+'};
char c4k[2] = {'<','>'};

void pr(char *s) { while (*s) putchar(*s++); }

int main()
{
	int i, k, pk, d, b, f;
	char *p;

	fgets(s, 1003, stdin);
	putchar('>');
	k = 0;
	for (p = s; *p > ' '; p++) {

		pk = k, k = 0;
		for (i = 0; i < 16; i++) {
			if (ABS(memo[k] - *p) > ABS(memo[i] - *p)) k = i;
		}

		i = ABS(k-pk); f = (k>pk); while (i--) putchar(c4k[f]), putchar(c4k[f]);

		d = *p - memo[k], b = (int)sqrt(ABS(d));
		memo[k] = *p;

        if (ABS(d) < 8) {
			i = ABS(d);	f = (d>0); while (i--) putchar(c4d[f]);
		} else {
			putchar('<');
			i = ABS(d)/b; while (i--) putchar('+');
			pr("[>");
			i = b; f = (d>0); while (i--) putchar(c4d[f]);

			pr("<-]>");
			i = ABS(d)-b*(ABS(d)/b), f = (d>0); while (i--) putchar(c4d[f]);
		}
		putchar('.');
	}
    return 0;
}

