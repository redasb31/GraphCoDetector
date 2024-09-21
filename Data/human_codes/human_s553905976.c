// AOJ 1541: Yu-kun Likes an Integer
// 2019.2.21 bal4u

#include <stdio.h>
#include <stdlib.h>

int n, m;
int c[10];

int check(int k)
{
	int cnt = n, sum = 0;
	while (k) {
		cnt--;
		sum += c[k % 10];
		if (sum > m) return 0;
		k /= 10;
	}
	if (cnt) {
		sum += c[0] * cnt;
		if (sum > m) return 0;
	}
	return 1;
}

int main()
{
	int i, max;
	char fmt[] = "%0xd\n";

	scanf("%d%d", &n, &m);
	for (i = 0; i < 10; i++) scanf("%d", c + i);
	max = 1; for (i = 0; i < n; i++) max *= 10;
	for (i = 0; i < max; i++) {
		if (check(i)) {
			fmt[2] = n + '0';
			printf(fmt, i);
			break;
		}
	}
	if (i == max) puts("NA");
	return 0;
}
