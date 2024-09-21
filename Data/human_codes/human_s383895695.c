#include <stdio.h>

#define K	1344	/* https://oeis.org/A066150 */
#define MD	1000000007
#define V2	500000004

long long power(int a, int k) {
	long long b = a, p = 1;

	while (k) {
		if (k & 1)
			p = p * b % MD;
		b = b * b % MD;
		k >>= 1;
	}
	return p;
}

int main() {
	static int mm[K], xx[K];
	int n, a, m, l, r, k, i, j, ans;

	scanf("%d%d", &n, &a);
	l = 0, r = K - 1;
	for (m = 1; m <= n / m; m++)
		if (n % m == 0) {
			mm[l] = m, xx[l] = power(a, (m + 1) / 2), l++;
			if (m != n / m)
				mm[r] = n / m, xx[r] = power(a, (n / m + 1) / 2), r--;
		}
	while (++r < K)
		mm[l] = mm[r], xx[l] = xx[r], l++;
	k = l;
	ans = 0;
	for (j = 0; j < k; j++) {
		for (i = 0; i < j; i++)
			if (mm[j] % mm[i] == 0)
				xx[j] = (xx[j] - xx[i] + MD) % MD;
		ans = (ans + (long long) xx[j] * (mm[j] % 2 == 0 ? mm[j] / 2 : mm[j])) % MD;
	}
	printf("%d\n", ans);
	return 0;
}
