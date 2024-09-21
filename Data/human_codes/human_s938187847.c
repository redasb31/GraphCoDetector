// AOJ 2912: Sum of QQ
// 2019.2.23 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int combi(int b)
{
	int p, q, ans;

	b <<= 1, ans = 0;
	for (p = (int)sqrt(b); p > 0; p--) {
		if (b % p == 0) {
			q = b / p;
			if ((p + q) & 1) ans++;
		}
	}
	return ans;
}

int main()
{
	int S, x, y, lim, ans;

	scanf("%d", &S);
	ans = 0;
	lim = (int)sqrt(S);
	for (x = 1; x <= lim; x++) {
		if (S % x == 0) {
			y = S / x;
			if (x == y) {
				int k = combi(x);
				ans += k * k;
			} else ans += 2 * combi(x)*combi(y);
		}
	}
	printf("%d\n", ans);
	return 0;
}
