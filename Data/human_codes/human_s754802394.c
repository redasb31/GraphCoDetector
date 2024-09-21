// AOJ 2265: Programming Contest Challenge Book
// 2017.10.15 bal4u@uu

#include <stdio.h>
#include <stdlib.h>

long long a[100005];
char buf[50], *p;

int cmp(long long *a, long long *b)
{
	if (*a < *b) return 1;
	if (*a > *b) return -1;
	return 0;
}

long long getInt()
{
	long long n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int check(int i)
{
	if (a[i+4]+a[i+5] > a[i+3]) return 1;
	if (a[i+4]+a[i+5] > a[i] && a[i+3]+a[i+2] > a[i+1]) return 1;
	if (a[i+3]+a[i+5] > a[i] && a[i+4]+a[i+2] > a[i+1]) return 1;
	if (a[i+3]+a[i+4] > a[i] && a[i+5]+a[i+2] > a[i+1]) return 1;
	if (a[i+2]+a[i+5] > a[i] && a[i+4]+a[i+3] > a[i+1]) return 1;
	if (a[i+2]+a[i+4] > a[i] && a[i+5]+a[i+3] > a[i+1]) return 1;
	if (a[i+2]+a[i+3] > a[i] && a[i+5]+a[i+4] > a[i+1]) return 1;
	if (a[i+1]+a[i+3] > a[i] && a[i+5]+a[i+4] > a[i+2]) return 1;
	if (a[i+1]+a[i+4] > a[i] && a[i+5]+a[i+3] > a[i+2]) return 1;
	if (a[i+1]+a[i+5] > a[i] && a[i+4]+a[i+3] > a[i+2]) return 1;
	return 0;
}

int main()
{
	int n, i, ii;
	long long *aa, pair1, pair2;

	fgets(buf, 10, stdin); n = atoi(buf);
	aa = a, i = n; while (i--) fgets(p = buf, 40, stdin), *aa++ = getInt();
	qsort(a, n, sizeof(long long), cmp);

	// searching first triangle
	for (i = 2; i < n; i++) if (a[i-2] < a[i-1] + a[i]) {
		pair1 = a[i-2] + a[i-1] + a[i];
		break;
	}
	if (i + 3 >= n) { puts("0"); return 0; }

	if (check(ii = i-2)) pair2 = a[ii+3] + a[ii+4] + a[ii+5];
	else {
		// searching second triangle
		for (i += 3; i < n; i++) if (a[i-2] < a[i-1] + a[i]) {
			pair2 = a[i-2] + a[i-1] + a[i];
			break;
		}
		if (i == n) { puts("0"); return 0; }
	}

	printf("%lld\n", pair1 + pair2);
	return 0;
}