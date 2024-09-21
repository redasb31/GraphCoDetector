/*
   AOJ 2141 Girls' Party
   2019.3.26 bal4u
   Josephus問題。1から数えてN番目のひとを外す。
   ただし、途中最大１回は、Nではなく、N+1にすることができる。
   輪の人数が最大200人なので、シュミュレーションして解く。
   人数が10万なら、他の方法を考えるしかない。
   計算量は最大 O(N^3) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// 入力処理
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数の入力
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

int ins(char *s)  // 文字列の入力　スペース以下の文字で入力終了
{
	char *p = s;
	do *s = gc();
	while (*s++ > ' ');
	*--s = 0;
	return s - p;
}

int N;                 // N番目のひとを外す
char S[205]; int W;    // 人の輪、長さ
int ans;

int check(int k, int ng, int nb)
{
	int i, n, start;
	char s[205], *p; int w;

	memcpy(s, S, W+1);
	w = W, start = 0;
	for (i = 0; i < W; i++) {
		if (i == k) n = N+1; else n = N;     // 外す人の間隔

		start = (start + n-1) % w;
		if (s[start] == 'G') ng--; else nb--;  // どのチームのひとが外れたか
		if (ng == 0 || nb == 0) break;      // 相手チームのひとが残っていなければ
		if (nb < ans) return 0;             // 残りの無駄な調べを省く

		p = s + start;                      // 外した人を外す
		while (*p) *p = *(p + 1), p++;
		w--;

		if (start >= w) start -= w;
	}
	return nb;
}

int main()
{
	int cs, i, a;
	int ng, nb;   // 'G'の人数、'B'の人数
	char *p;

	cs = in();
	while (cs--) {
		N = in(), W = ins(S);

		// 人数を数える
		p = S, ng = nb = 0; while (*p) if (*p++ == 'G') ng++; else nb++;

		ans = 0;
		// i回目でNをN+1にする。(-1)はそうしないケース。
		for (i = -1; i < W; i++) {
			a = check(i, ng, nb);
			if (a > ans) ans = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
