// AOJ 2769: 28
// 2018.1.6 bal4u@uu

#include <stdio.h>
#include <math.h>

#define HASHSIZ 1000033
long long hash[HASHSIZ+2], *hashend = hash+HASHSIZ;

int lookup(long long n)
{
	long long *p = hash + (int)(n % HASHSIZ);
	while (*p) {
		if (*p == n) return 1;
		if (++p == hashend) p = hash;
	}
	return 0;
}

void insert(long long n)
{
	long long *p = hash + (int)(n % HASHSIZ);
	while (*p) {
		if (*p == n) return;
		if (++p == hashend) p = hash;
	}
	*p = n;
}

int sz;
long long p[524300];		// 2^19
int ans;

//#define getchar_unlocked()  getchar()
long long in()
{
	long long n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int calc(long long n, int id, int s)
{
	int i, a, b;
	long long n1;

	if (n & 1) return 0;
	if (n == 2 || n == 4 || n == 8) {
		if (n == 2) { if (s+1 > ans) ans = s+1; return 1; }
		if (n == 4) { if (s+2 > ans) ans = s+2; return 1; }
		if (n == 8) { if (s+3 > ans) ans = s+3; return 1; }
	}
	if (n < 15) return 0;

	b = (int)sqrt((double)n);
	for (i = id; p[i] <= b; i++) {
		if (n % p[i]) continue;
		n1 = n / p[i], a = 1;
		while (n1 % p[i] == 0) n1 /= p[i], a++;
		if (n1 == 1) {
			if (s+a > ans) ans = s+a; return 1;
		}
		while (a >= 0) {
			if (calc(n1, i+1, s+a)) return 1;
			n1 *= p[i], a--;
		}
	}
	if (lookup(n)) { if (s+1 > ans) ans = s+1; return 1; }
	return 0;
}

int main()
{
	int i, j, k, k2;
	long long n, t;

	sz = 3;
	p[1] = 2, p[2] = 8, insert(2), insert(8);
	for (k = 1, i = 2; i <= 19; i++, k = k2) {
		k2 = k << 1;
		for (j = k; j < k2; j++) {
			t = p[j]*10;
			t += 2, p[sz++] = t, insert(t);
			t += 6, p[sz++] = t, insert(t);
		}
	}

	n = in();
	if (n & 1) { puts("-1"); return 0; }
	ans = 0;
	calc(n, 1, 0);
	if (ans <= 0) puts("-1");
	else printf("%d\n", ans);
	return 0;
}


