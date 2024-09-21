/*
   AOJ 1392 Shortest Common Non-Subsequence
   2019.3.27 bal4u
   オートマトンで状態遷移図をつくり、BFSで初期状態を表す頂点
   から、最終状態を表す頂点への最短経路を求める。
   計算量はO(MN)。M、Nはそれぞれの文字列の長さ。
   オートマトンで解く問題が多くないが、0,1だけの文字列等には使える可能性が高い。
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
int ins(char *s)  // 文字列の入力　スペース以下の文字で終了
{
	char *p = s;
	do *s = gc();
	while (*s++ > ' ');
	*--s = 0;
	return s - p;
}


//// 本問題関連
#define QMAX 10000000
#define MAX 4005       // 文字列の最大長さ
#define ONE  (1<<30)
#define SFT 12
#define MASK ((1<<12)-1)

typedef struct { int n; int s, t; } QUE;
QUE que[QMAX+5]; int top, end;
char S[MAX], T[MAX];   // それぞれの入力文字列
char ans[MAX];         // 答えを格納する
int vis[MAX][MAX];     // 状態の記録用

void dfs()
{
	int s, t, n, s0, s1, t0, t1;

	que[0].n = que[0].s = que[0].t = 0;
	top = 0, end = 1;
	while (top != end) {
		n = que[top].n, s = que[top].s, t = que[top].t;
		top++;  // if (++top == QMAX) top = 0;

		if (S[s] == 0 && T[t] == 0) break;   // 成功

		s0 = s1 = s, t0 = t1 = t;

		while (S[s0] && S[s0++] == '1');   // S文字列上の、次の 非'1'文字 まで
		while (S[s1] && S[s1++] == '0');   // S文字列上の、次の 非'0'文字 まで
		while (T[t0] && T[t0++] == '1');   // T文字列上の、次の 非'1'文字 まで
		while (T[t1] && T[t1++] == '0');   // T文字列上の、次の 非'0'文字 まで

		// '0'による遷移の記録
		if (!vis[s0][t0]) {
			vis[s0][t0] = (s << SFT) | t;
			que[end].n = n + 1, que[end].s = s0, que[end].t = t0;
			end++;  // if (++end == QMAX) end = 0;
		}

		// '1'による遷移の記録
		if (!vis[s1][t1]) {
			vis[s1][t1] = (s << SFT) | t | ONE;
			que[end].n = n + 1, que[end].s = s1, que[end].t = t1;
			end++;  // if (++end == QMAX) end = 0;
		}
	}

	// 最短遷移のパスを復元し、解答とする。逆順に注意
	ans[n] = 0;
	do {
		int st = vis[s][t];
		s = (st >> SFT) & MASK, t = st & MASK;
		ans[--n] = '0';
		if (st & ONE) ans[n]++;
	} while (s | t);
}

int main()
{
	int w;

	w = ins(S), S[w] = 'X', S[w + 1] = 0;
	w = ins(T), T[w] = 'X', T[w + 1] = 0;
	dfs();
	printf("%s\n", ans);
	return 0;
}
