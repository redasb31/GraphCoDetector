// AOJ 2856: Window
// 2017.11.23 bal4u@uu

#include <stdio.h>

char buf[102];
char f[10102];

int main()
{
	int n, h, w, x;
	int i, l, r, ans;
	
	scanf("%d%d%d", &n, &h, &w);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		l = i*w, r = l+w;
		if (i & 1) l -= x, r -= x;
		else       l += x, r += x;
		if (l < 0) l = 0;
		while (l < r) f[l++] = 1;
	}
	ans = 0, i = n*w; while (i--) if (!f[i]) ans++;
	printf("%d\n", ans*h);
	return 0;
}