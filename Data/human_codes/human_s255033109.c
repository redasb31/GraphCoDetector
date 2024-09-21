// Aizu 2833: Displayed tweets
// 2017.11.25 bal4u@uu
// 2018.1.9

#include <stdio.h>
#include <string.h>

int a[100001], k[100001];
char f[100001];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int N, K, i, re, v, ans;

	N = in(), K = in();
	memset(k, 0x33, sizeof(int)*(N+1));
	for (i = 1; i <= N; i++) a[i] = in();

	ans = 0;
	for (i = N; i > 0; i--) {
		re = a[i];
		if (re) {
			if (!f[i]) v = 0, ans++;
			else if ((v = k[i]) < K) ans++;
			v++;
			if (v < K && k[re] > v) k[re] = v;
			f[re] = 1;
		} else ans++;
	}
	printf("%d\n", ans);
	return 0;
}

