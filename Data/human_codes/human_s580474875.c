#include <stdio.h>
#include <string.h>

int main()
{
	int w, e, n,st, sy;
	long long int map[10000][10000],ans=0;
	int t, y, i,a, b, k;
	scanf("%d%d%d", &w, &e, &n);
	for (t = 1;t <= w;t++) {
		for (y = 1;y <= e;y++) {
			map[t][y] = 0;
		}
	}
	for (i = 1;i <= n;i++) {
		scanf("%d%d", &a, &b);
		map[a][b] += i;
	}
	k = 1;st = 1;sy = 1;
	while (k <= n) {
		for (t = 1;t <= w;t++) {
		for (y = 1;y <= e;y++) {
		 if (map[t][y] == k) {
		   while (1) {
			if (st == t) {
				while (sy != y)sy < y ? sy++ : sy--;ans++;
			}else if (sy == y) {
				while (st != t)st < t ? st++ : st--;ans++;
			}else {
				while (st != t || sy != y)st < t ? st++ : st--;sy < y ? sy++ : sy--;ans++;
			}if (st == t&&sy == y) {
				k++;break;
		    }
		    }
		 }
		}
	    }
	}
	printf("%lld\n", ans);
	return 0;
}