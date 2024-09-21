#include <stdio.h>

int main()
{
	long long N;
	scanf("%lld", &N);
	
	int p, q;
	long long div = 0, ans = 1;
	for (p = 2; p <= N; p++) {
		for (q = 2; q * q <= p; q++) if (p / q * q == p) break;
		if (q * q <= p) continue;
		for (q = (int)N / p, div = 0; q >= 1; q /= p) div += q;
		ans = ans * (div + 1) % 1000000007;
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}