// AOJ 1237: Shredding Company
// 2017.10.16 bal4u@uu

#include <stdio.h>
#include <string.h>

int calc(char *s, char *cut, int w)
{
	int i, k = 0, sum = 0;
	for (i = 0; i <= w; i++) {
		k = 10*k + (s[i] & 0xf);
		if (cut[i]) sum += k, k = 0;
	}
	return sum + k; 
}

int main()
{
	int t, i, j, k, w, lim, max, many;
	char s[8], cut[6], ans[6];

	while (scanf("%d%s", &t, s) && t > 0) {
		w = strlen(s)-1, lim = 1 << w;
		for (max = 0, i = 0; i < lim; i++) {
			memset(cut, 0, sizeof(cut));
			for (j = 0; j <= w; j++) if ((i >> j) & 1) cut[j] = 1;
			k = calc(s, cut, w);
			if (k <= t && k > max) {
				max = k, many = 0;
				memcpy(ans, cut, sizeof(ans)); 
			} else if (k == max) many = 1;
		}
		if (max == 0) puts("error");
		else if (many) puts("rejected");
		else {
			printf("%d ", max);
			for (j = 0; j <= w; j++) { putchar(s[j]); if (ans[j]) putchar(' ');	}
			putchar('\n');
		}
    }
	return 0;
}