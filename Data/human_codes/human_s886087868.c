// AOJ 2312: Magical Girl Sayaka-chan
// 2017.11.26 bal4u@uu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, L;
int k[2001];
int s[100001];
long long sum[100002];
long long memo[2001][2001];

char buf[700001], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int cmp(int *a, int *b) { return *a - *b; }

long long kpart(int r, int l) { return (sum[r]-sum[l]) / L; }

long long calc(int l, int r)
{
	int i;
	long long ll, rr;
  
    if (memo[l][r] >= 0) return (memo[l][r]);
	i = r; if (i < l) i = l;
	if (++i == N - 1) return kpart(k[i], k[l]-1) + kpart(k[i], k[r]-1);
     
    ll = calc(i, r) + kpart(k[i], k[l] - 1);
    rr = calc(l, i) + kpart(k[i], k[r] - 1);
	if (ll > rr) ll = rr;
    return memo[l][r] = ll;
}

int main()
{
	int i;

	fgets(p=buf, 30, stdin);
	N = getint(), p++, M = getint(), p++, L = getint();
	fgets(p=buf, sizeof(buf), stdin);
	for (i = 0; i < N; i++) k[i] = getint(), p++;
	qsort(k, N, sizeof(int), cmp);
	fgets(p=buf, sizeof(buf), stdin);
	for (sum[0] = 0, i = 0; i < M; i++) {
		s[i] = getint(), p++;
		sum[i+1] = sum[i] + s[i];
	}
	memset(memo, -1, sizeof(memo));
	printf("%lld\n", calc(0, 0));
	return 0;
}