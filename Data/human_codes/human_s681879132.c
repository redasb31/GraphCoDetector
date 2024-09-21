// AOJ 2545: Lion
// 2017.10.5 bal4u@uu

#include <stdio.h>
#include <string.h>

int n, x, m;
int l[11], r[11], s[11];
int ll, rr, ss;
int ans[7], max;
int a[7], sum[7];

int combi(int k)
{
	int i, xx;


	if (k == n+1) {
		for (i = 1; i <= n ; i++) sum[i] = sum[i-1] + a[i];
	    for (i = 0; i < m; i++)
			if (sum[r[i]] - sum[l[i]-1] != s[i]) return 0;
		if (sum[n] > max) max = sum[n], memcpy(ans, a, sizeof(ans));
		return 1;
	}
	xx = x;	if (k >= ll && k <= rr && xx > ss) xx = ss;
	for (i = xx; i >= 0; i--) {
		a[k] = i;
		if (combi(k+1)) return 1;
	}
	return 0;
}
  
int main()
{
	int i;

	scanf("%d%d%d", &n, &x, &m);
	for (ss = 60, i = 0; i < m; i++) {
		scanf("%d%d%d", l+i, r+i, s+i);
		if (s[i] < ss) ss = s[i], ll = l[i], rr = r[i];
	}
	max = 0;
	if (!combi(1)) puts("-1");
	else {
		for (i = 1; i <= n; i++) {
			if (i > 1) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}