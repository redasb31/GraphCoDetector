// AOJ 2978 Undo Swapping
// 2019.9.24 bal4u

#include <stdio.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

char R[100005], C[100005];
int rel[100005];

int dfs(int r, int n) {
	int c = rel[r];
	if (c == 0) return n;
	rel[r] = 0;
	return dfs(c, n+1);
}

int main()
{
	int i, N, r, c, ans;
	
	N = in();
	i = N; while (i--) {
		r = in(), c = in();
		if (R[r]) { puts("-1"); return 0; }
		R[r] = 1;
		if (C[c]) { puts("-1"); return 0; }
		C[c] = 1;
		if (r != c) rel[r] = c;
	}
	ans = 0; for (r = 1; r <= N; r++) if (rel[r]) ans += dfs(r, 0)-1;
	printf("%d\n", ans);
	return 0;
}
