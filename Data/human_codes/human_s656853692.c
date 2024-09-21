// AOJ ITP2_9_D Set Symmetric Difference
// 2019.3.8 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in()   // 非負整数の入力
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void out(int n)    // 非負整数の表示　最後に改行あり
{
	int i;
	char ob[20];

	if (!n) pc('0');
	else {
		//		if (n < 0) pc('-'), n = -n;
		i = 0; while (n) ob[i++] = n % 10 + '0', n /= 10;
		while (i--) pc(ob[i]);
	}
	pc('\n');
}

#define INF 1000000001
int n, m;
int a[200002], b[200002];

int main()
{
	int i, j;

	n = in();
	for (i = 0; i < n; i++) a[i] = in();
	a[i] = INF;
	m = in();
	for (j = 0; j < m; j++) b[j] = in();
	b[j] = INF;
	i = j = 0; while (1) {
		while (a[i] < b[j]) out(a[i++]);
		while (b[j] < a[i]) out(b[j++]);
		if (a[i] == INF) break;
		if (a[i] == b[j]) i++, j++;
	}
	return 0;
}
