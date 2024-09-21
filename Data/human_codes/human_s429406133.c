// AOJ 2069: Greedy, Greedy.
// 2017.11.5 bal4u@uu

#include <stdio.h>
#include <string.h>
#define TM 0
#if TM
#include <time.h>
#endif

int c[52], n;
int dp[2001];

char buf[302], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int greedy(int p)
{
	int i, s = 0;

	i = n; while (i--) {
		if (p == c[i]) { s++; break; }
		if (p < c[i]) continue;
		s += p/c[i];
		p %= c[i];
	}
	return s;
}

int main()
{
	int cno = 0, i, j, k, lim;
#if TM
	clock_t start, end;
	start = clock();
#endif
	while (fgets(p=buf, 300, stdin) && *p != '0') {
		printf("Case #%d: ", ++cno);
		n = getint(), p++;
		c[0] = getint(), p++;
		if (c[0] != 1) { puts("Cannot pay some amount"); continue; }
		if (n <= 2) { puts("OK"); continue; }
		for (i = 1; i < n; i++) c[i] = getint(), p++;
		lim = c[n-1] + c[n-2];

		memset(dp, 0x33, sizeof(dp)), dp[0] = 0;
		for (i = 1; ; i++) {
			if (i == lim) { puts("OK"); break; }
			for (j = 0; j < n; j++) {
				k = i - c[j];
				if (k >= 0 && dp[i] > dp[k]+1) dp[i] = dp[k] + 1;
			}
			if (greedy(i) != dp[i]) { puts("Cannot use greedy algorithm"); break; }
		}
	}
#if TM
	end = clock();
	printf("time %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
#endif
	return 0;
}