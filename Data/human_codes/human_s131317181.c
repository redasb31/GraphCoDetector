// AOJ 1604 Deadlock Detection
// 2018.4.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10005];
char dp[1024][10];
int  a[10005][2], sz;

int calc(int n)
{
	int i, s, k, l, w, sw;
	char *p;

	memset(dp, 0, sizeof(dp));
	s = 0, sz = 0;
	for (p = str; *p > ' '; p++) {
		if (*p == 'u') s = 0;
		else {
			k = *p & 0xf;
			if (s) {
				if (s & (1<<k)) return 0;
				dp[s][k] = 1;
				a[sz][0] = s, a[sz++][1] = k;
			}
			s |= 1<<k;
		}
	}
 	for (l = 1; l < 1024; l++) for (w = 0; w < 10; w++) {
		if (!dp[l][w]) continue;
		sw = 1<<w;
		if (l & sw) return 0;
 
		for (i = 0; i < sz; i++) {
			if ((l & a[i][0]) == 0 && (sw & a[i][0])) {
				dp[l|a[i][0]][a[i][1]] = 1;
			}
		}
	}
	return 1;
}
 
int main()
 {
	int n;
	
	while (fgets(str, 10, stdin) && *str != '0') {
		n = atoi(str);
		fgets(str, sizeof(str), stdin);
		puts(calc(n)? "SAFE": "UNSAFE");
	}
	return 0;
}
