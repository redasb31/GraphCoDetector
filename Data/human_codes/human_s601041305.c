// Aizu Vol-2 0287: Jinkoki
// 2017.8.10

#include <stdio.h>

#define N       10000
#define SIZE    25

void mpMul(int *ret, int *a, int *b);
void mpPow(int *ret, int *a, int *b);

char *unit[19] = { 0, "\0", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", "Jou", "Ko", "Kan",
"Sei", "Sai", "Gok", "Gps", "Asg", "Nyt", "Fks", "Mts" };

int mm[SIZE], nn[SIZE], ans[SIZE];

int main()
{
	int m, n;
	int i, j;
	int *p;
	char b[10], *q;

	while (1) {
		scanf("%d%d", &m, &n); if (m == 0) break;
		mm[0] = 1, mm[1] = m;
		nn[0] = 1, nn[1] = n;
		mpPow(ans, mm, nn);

		p = ans;
		if (*p == 0 || (*p == 1 && *(p + 1) == 0)) { putchar('0'), putchar('\n'); continue; }
		for (i = ans[0], p = ans + i; i >= 1; i--, p--) {
			int x = *p;
			if (x == 0) continue;
			for (q = b+5, *q = 0, j = 0; j < 4 && x > 0; j++) *--q = x % 10 + '0', x /= 10;
			printf("%s%s", q, unit[i]);
		}
		putchar('\n');
	}
	return 0;
}

void mpPow(int *ret, int *a, int *b)
{
	int i, len, cur;
	unsigned k, bit;
	static int tmp[2][SIZE];

	if (*b == 0 || (*b == 1 && *(b + 1) == 0) || (*a == 1 && *(a + 1) == 1)) { *ret = 1, *(ret + 1) = 1; return; }
	if (*b == 1 && *(b + 1) == 1) {
		for (i = 0, len = *a; i <= len; i++) *ret++ = *a++;
		return;
	}
	k = *(b + 1), tmp[0][0] = 1, tmp[0][1] = 1, cur = 0;
	for (bit = 0x10000; bit > 0; bit >>= 1) {
		if (tmp[cur][0] > 1 || tmp[cur][1] > 1) mpMul(tmp[!cur], tmp[cur], tmp[cur]), cur = !cur;
		if (k & bit) mpMul(tmp[!cur], tmp[cur], a), cur = !cur;
	}
	for (i = 0, len = tmp[cur][0]; i <= len; i++) *ret++ = tmp[cur][i];
}

void mpMul(int *ret, int *a, int *b)
{
	int  i, j, la, lb, ca;
	int  *aa;
	long long x;

	la = *a, lb = *b;
	if (la == 0 || lb == 0) { *ret = 0;	return;	}
	for (i = la + lb; i > 0; i--) *(ret + i) = 0;
	for (j = 1; j <= lb; j++) {
		ca = 0, b++;
		for (i = 1, aa = a; i <= la; i++) {
			x = *++aa;
			x = x * *b + *(ret + i + j - 1) + ca;
			*(ret + i + j - 1) = x % N;
			ca = (int)(x / N);
		}
		*(ret + i + j - 1) = ca;
	}
	*ret = (ca != 0) ? la + lb : la + lb - 1;
}