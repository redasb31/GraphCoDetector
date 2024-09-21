// AOJ 3024 RMQ 2
// 2019.4.2 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x7fffffff

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void out(int n)
{
	int i;
	char ob[30];

	if (!n) pc('0');
	else {
		i = 0; while (n) ob[i++] = n % 10 + '0', n /= 10;
		while (i--) pc(ob[i]);
	}
	pc('\n');
}


//// セグメント木
int seg[2][1 << 19]; int sz;

void segInit(int n) {
	sz = 1; while (sz < n) sz <<= 1;
	memset(seg, INF, sizeof(seg));
}

// k番目（0-index）の値を v に変更
void update(int id, int k, int v)
{
	int a, b;

	k += sz - 1;
//	if (seg[id][k] == v) return;
	seg[id][k] = v;
	while (k > 0) {
		k = (k - 1) >> 1;
		a = seg[id][(k << 1) + 1];
		b = seg[id][(k << 1) + 2];
		seg[id][k] = (a <= b)? a: b;
	}
}

// 空間 [a, b) 内の最小値
int getMin(int id, int a, int b, int k, int l, int r)
{
	int left, right;

	if (r <= a || b <= l) return INF;
	if (a <= l && r <= b) return seg[id][k];
	left = getMin(id, a, b, (k << 1) + 1, l, (l + r) >> 1);
	right = getMin(id, a, b, (k << 1) + 2, (l + r) >> 1, r);
	return left <= right ? left : right;
}


//// 本問題
typedef struct { int y, p, n; } T;  // 位置と更新前後の値
T memo[2][200005]; int len[2];

int main()
{
	int i, k, N, Q, x, y, z;
	int syn;

	N = in();
	segInit(N);            // セグメント木の初期化
	for (i = 0; i < N; i++) update(0, i, in());
	for (i = 0; i < N; i++) update(1, i, in());

	Q = in(), syn = 0;
	while (Q--) {
		x = in(), y = in()-1, z = in();      // 0-index
		if (x == 1 || x == 2) {
			x--;   // 0と1にする. 0->A, 1->B
			if (syn) {
				// 位置と更新前後の値を記録
				k = len[x]++;
				memo[x][k].y = y, memo[x][k].n = z;
				memo[x][k].p = seg[x][y+(sz-1)];     // 元の値は y+(sz-1) の位置にある
			}
			update(x, y, z);
		}
		else if (x == 3 || x == 4) out(getMin(x-3, y, z, 0, 0, sz));
		else {
			x -= 5;   // 0と1にする. 0->A, 1->B
			if (syn) {
				// 元に戻して、相手のしてきた変更を施し、相手と同じにする
				for (i = len[x] - 1; i >= 0; i--)   // 戻す作業
					update(x, memo[x][i].y, memo[x][i].p);
				for (i = 0; i < len[!x]; i++)       // 相手に同期
					update(x, memo[!x][i].y, memo[!x][i].n);
				len[0] = len[1] = 0;
			}
			else {
				memcpy(seg[x], seg[!x], sizeof(int)*sz*2);
				syn = 1;
			}
		}
	}
	return 0;
}

