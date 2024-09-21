// AOJ 417 Gas Station
// 2019.12.7

#include <stdio.h>

#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

void out(int n) { // 正整数の表示（出力）
	int i; char b[30];

	i = 0; while (n) b[i++] = n % 10 + '0', n /= 10;
	while (i--) pc(b[i]);
	pc('\n');
}

int N;
int lane[11][10003], top[11], end[11], sz[11];

int main()
{
	int i, idx, info, M, x;

	N = in(), M = in();
	while (M--) {
		idx = in(), info = in();
		if (idx) {
			x = 1; for (i = 2; i <= N; ++i) {
				if (sz[i] < sz[x]) x = i;
			}
			lane[x][end[x]++] = info, ++sz[x];
		} else out(lane[info][top[info]++]), --sz[info];
	}
	return 0;
}

