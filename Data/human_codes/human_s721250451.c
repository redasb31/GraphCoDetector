// AOJ 2808: Password
// 2017.10.11 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

#define MAX 400004
#define P4  531441		// 27^4

char s[MAX+10];
char f[P4+10];

int main()
{
	int n, i, a, a1, a2, a3, a4;
	char *p;

	fgets(s, 50, stdin); n = atoi(s);
	while (n-- > 0) {
		fgets(s, MAX, stdin); p = s;
		a1 = a2 = a3 = a4 = 0;
		while (*p >= 'a') {
			a = *p++ - 'a'+1;
			a4 = a3*27 + a, f[a4] = 1;
			a3 = a2*27 + a, f[a3] = 1;
			a2 = a1*27 + a, f[a2] = 1;
			a1 =         a, f[a1] = 1;
		}
	}

	for (i = 1; i < P4; i++) {
		if (i % 27 > 0 && f[i] == 0) {
			p = s+10; *p = 0;
			a = i; while (1) {
				if (!a) { puts(p); return 0; }
				*--p = a % 27 + 'a'-1;
				if (*p == 'a'-1) break;
				a /= 27;
			}
		}
	}
	// panic
	return 0;
}