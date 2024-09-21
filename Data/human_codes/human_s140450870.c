// AOJ 2199: Differential Pulse Code Modulation
// 2017.9.21 bal4u@uu
// 2017.11.22

#include <stdio.h>
#include <string.h>

int code[18];			// code book
char y[2][260];			// signal
long long ss[2][260];	// Sum of Squares

char buf[20], *p;
int getint()
{
	int n = 0;
	if (*p == '-') {
		p++;
		while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
		return -n;
	}
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}
int main()
{
	int n, m, i, j, k, x, k1, k2;
	long long ans, s;

	while (fgets(p=buf, 20, stdin) && *p != '0') {
		n = getint(), p++, m = getint();
		for (j = 0; j < m; j++) {
			fgets(p=buf, 10, stdin);
			code[j] = getint();
		}
		memset(ss, -1, sizeof(ss)), memset(y, 0, sizeof(y)); y[0][128] = 1, ss[0][128] = 0;
		for (k1 = 0, k2 = 1, k = 0; k < n; k++, k1 = k2, k2 = !k2) {
			for (i = 0; i < 256; i++) y[k2][i] = 0, ss[k2][i] = -1LL;
			fgets(p=buf, 10, stdin);
			x = getint();
			for (i = 0; i < 256; i++) {
				if (!y[k1][i]) continue;
				for (j = 0; j < m; j++) {
					int t = i + code[j];
					if (t < 0) t = 0;
					if (t >= 256) t = 255;
					y[k2][t] = 1;
					s = (t-x)*(t-x) + ss[k1][i];
					if (ss[k2][t] < 0 || s < ss[k2][t])	ss[k2][t] = s;
				}
			}
		}
		for (ans = 1LL << 60, i = 0; i < 256; i++) 
			if (ss[k1][i] >= 0 && ss[k1][i] < ans) {
				ans = ss[k1][i]; if (ans == 0) break;
			}
		printf("%lld\n", ans);
	}
	return 0;
}