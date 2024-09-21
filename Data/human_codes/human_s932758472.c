// AOJ 2769: 28
// 2018.1.6 bal4u@uu

#include <stdio.h>
#include <math.h>

#define HASHSIZ 1000033
typedef struct { long long p; char k; } HASH;
HASH hash[HASHSIZ+2], *hashend = hash+HASHSIZ;

int lookup(long long n)
{
	HASH *p = hash + (int)(n % HASHSIZ);
	while (p->p) {
		if (p->p == n) return p->k;
		if (++p == hashend) p = hash;
	}
	return 0;
}

void insert(long long n, char k)
{
	HASH *p = hash + (int)(n % HASHSIZ);
	while (p->p) {
		if (p->p == n) { p->k = k+1; return; }
		if (++p == hashend) p = hash;
	}
	p->p = n, p->k = k+1;
}

int sz;
long long p[524300];		// 2^19
int ans;

long long special[20] = {
8, 88, 888, 8888, 88888, 888888, 8888888, 88888888, 222888288,
888888888, 8888888888LL, 88888888888LL, 888888888888LL, 8888888888888LL,
88888888888888LL, 888888888888888LL, 8888888888888888LL,
88888888888888888LL, 888888888888888888LL, 0};

//#define getchar_unlocked()  getchar()
long long in()
{
	long long n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int calc(long long n, int i, int s)
{
	int k, a, b, c;
	long long n1;

	if (n & 1) return 0;
	if ((k = lookup(n)) > 0) { if (s+k > ans) ans = s+k; return 1; }
	if (n == 4) { if (s+2 > ans) ans = s+2; return 1; }
	if (n < 15) return 0;

	b = (int)sqrt((double)n);
	for ( ; p[i] <= b; i++) {
		if (!p[i]) continue;
		if (n % p[i]) continue;
		c = (int)p[i];
		n1 = n / c, a = 1;
		while (1) {
			if (n1 % c || n1 < c) break;
			n1 /= c, a++;
		}
		if (n1 == 1) { if (s+a > ans) ans = s+a; return 1; }
		if (n1 < c) n1 *= c, a--;
		while (a >= 0) {
			if (calc(n1, i+1, s+a)) return 1;
			n1 *= c, a--;
		}
	}
	return 0;
}

void init()
{
	int i, j, k, k2;
	long long t;

	sz = 3;
	p[1] = 2, p[2] = 8, insert(2, 0), insert(8, 0);
	k = 1; for (i = 2; i <= 19; i++) {
		k2 = k << 1;
		for (j = k; j < k2; j++) {
			t = p[j]*10;
			t += 2, p[sz++] = t, insert(t, 0);
			t += 6, p[sz++] = t, insert(t, 0);
		}
		k = k2;
	}
	for (i = 0; special[i]; i++) insert(special[i], 2);
	p[2] = p[6] = p[14] = 0;
}

int main()
{
	long long n;

	init();
	n = in();
	calc(n, 1, 0);
	if (ans <= 0) puts("-1");
	else printf("%d\n", ans);
	return 0;
}

