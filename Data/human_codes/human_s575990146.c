// AOJ 1591 Graph Making
// 2018.4.18 bal4u

#include <stdio.h>

// バッファを経ずstdinから数値を得る
#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int main()
{
	int n, d;

	n = in(), d = in();
	if (d == 1) printf("%lld\n", (long long)n*(n-1)>>1);
	else printf("%lld\n", (n-1)+(long long)(n-d-1)*n-((long long)(n-d-1)*(n+d-2)>>1));
	return 0;
}
