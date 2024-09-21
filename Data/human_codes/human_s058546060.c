// AOJ 0272: The Lonely Girl's Lie
// 2017.10.14 bal4u@uu
// 2017.11.1 retry

#include <stdio.h>
#include <stdlib.h>

int a[40003], b[40003];

int cmp(int *a, int *b) { return *b - *a; }

char buf[280100], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int n, i, k, ans;

	while (fgets(p=buf, 10, stdin) && *buf != '0') {
		n = getint();
		fgets(p=buf, 280100, stdin);
		for (i = 0; i < n; i++) a[i] = getint(), p++;
		fgets(p=buf, 280100, stdin);
		for (i = 0; i < n; i++) b[i] = getint(), p++;
		
		qsort(a, n, sizeof(int), cmp);
		qsort(b, n, sizeof(int), cmp);

		for (ans = n, i = k = 0; k < n; i++, k += 2) {
			if (a[k] > b[i]) { ans = k + 1; break; }
		}
		if (ans == n) puts("NA");
		else printf("%d\n", ans);
	}
	return 0;
}