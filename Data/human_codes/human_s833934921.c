// AOJ 3002: Factorization
// 2017.11.29 bal4u@uu

#include <stdio.h>

int a[6], n;
int ans[6];

char buf[100], *p;
int getint()
{
	int n = 0;
	if (*p == '-') {
		p++; while (*p >= '0' && *p <= '9') n = (n<<3) + (n<<1) + (*p++ & 0xf);
		return -n;
	}
	if (*p == '+') p++;
	while (*p >= '0' && *p <= '9') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

long long pow(int x, int k)
{
	long long t = 1;
	while (k--) t = t * x;
	return t;
}

int check(int v)
{
	int i;
	long long s = 0;
	for (i = 0; i <= n; i++) {
		if (a[i] == 0) continue;
		s += a[i] * pow(v, i);
	}
	return s == 0;
}

int main()
{
	int i, k, c;

    fgets(p=buf, 100, stdin);
	p += 2, n = *p++ & 0xf, a[n] = 1;
	while (*p >= ' ') {
		k = getint(), i = 0;
		if (*p == 'x') {
			i = 1, p++;
			if (*p == '^') p++, i = *p++ & 0xf;
		}
		a[i] = k;
	}

	c = a[0]; if (c < 0) c = -c;
	for (i = 0, k = -c; k <= c; k++) if (k != 0) {
		if (a[0] % k == 0 && check(-k)) {
			ans[i] = k;	if (++i >= n) break;
		}
	}
	for (i = 0; i < n; i++) printf("(x%+d)", ans[i]);
	putchar('\n');
    return 0;
}