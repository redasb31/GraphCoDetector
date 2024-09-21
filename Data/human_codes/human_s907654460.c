// AOJ 2666 Arojam's Mask
// 2019.4.3 bal4u

#include <stdio.h>
#include <stdlib.h>

//// 高速入力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

// 数値のハッシュ関数
#define HASHSIZ 2000081
int hash[HASHSIZ + 5], *hashend = hash + HASHSIZ;

int insert(int node, int days, unsigned char event)
{
	int x = ((node + 1) << 16) | (days << 8) | event;
	int *p = hash + x % HASHSIZ;
	while (*p) {
		if (*p == x) return 0;
		if (++p == hashend) p = hash;
	}
	*p = x;
	return 1;
}

//// 本問題関連
typedef struct { int node, days, step; unsigned char event; } Q;
Q que[2000000]; int top, end;

typedef struct { int to; unsigned char cond; } T;  // 移動先、発生するイベント、移動できる条件
T to[102][102]; int hi[102];
int N, E, R;
int goEvent[102];

int bfs(int start, int goal)
{
	int i, node, days, step, event;

	top = 0, end = 1;
	que[0].node = start, que[0].days = 0, que[0].event = 1;
	while (top != end) {
		node = que[top].node, days = que[top].days, step = que[top].step, event = que[top++].event;
		if (node == goal) return step;

//		printf("node=%d, days=%d, step=%d, event=%x\n", node, days, step, event);
		if (!insert(node, days, event)) continue;

		event |= goEvent[node];    // 頂点に到着すると発生するイベント
		if (days < R) {
			for (i = 0; i < hi[node]; i++) {
				int _to = to[node][i].to, _cond = to[node][i].cond;
				if (_cond & event) {
					que[end].node = _to, que[end].days = days + 1, que[end].step = step + 1;
					que[end++].event = event;
				}
			}
		}
		que[end].node = start, que[end].days = 0, que[end].step = step + 1;
		que[end++].event = event;
	}
	return -1;
}

int main()
{
	int i, k, M, S, T, a, b, c;

	N = in(), M = in(), E = in();
	S = in(), T = in(), R = in();
	for (i = 0; i < M; i++) {
		a = in(), b = in();
		k = hi[a]++, to[a][k].to = b, to[a][k].cond = 0xff;
		k = hi[b]++, to[b][k].to = a, to[b][k].cond = 0xff;
	}
	for (i = 1; i <= E; i++) {
		a = in(), b = in(), c = in();
		k = hi[a]++, to[a][k].to = b, to[a][k].cond = 1 << i;  // イベント1 を無条件移動に使う
		k = hi[b]++, to[b][k].to = a, to[b][k].cond = 1 << i;
		goEvent[c] = 1 << i;
	}
	printf("%d\n", bfs(S, T));
	return 0;
}
