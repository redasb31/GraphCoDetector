// AOJ 2383: Rabbit Game Playing
// 2017.10.4 bal4u@uu
// 2017.11.12

#include <stdio.h>
#include <stdlib.h>

#define M 1000000007
int d[100002], n;

int cmp(int *a, int *b) { return *a - *b; }

int bsch(int x)
{
	int m, l = 0, r = n;

    while (l < r) {
        m = (l + r) >> 1;
        if (d[m] < x) l = m + 1; else r = m;
    }
	return l;
}

char buf[20], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int t, i;
	long long ans;

	fgets(p=buf, 20, stdin);
	n = getint(), p++, t = getint();
	for (i = 0; i < n; i++) fgets(p=buf, 10, stdin), d[i] = getint();
    qsort(d, n, sizeof(int), cmp);
    for (ans = 1, i = 0; i < n; i++) ans = (ans * (i+1-bsch(d[i]-t))) % M;
    printf("%lld\n", ans);
    return 0;
}