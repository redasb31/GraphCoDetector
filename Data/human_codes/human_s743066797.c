// AOJ 1632 Scores of Final Examination
// bal4u 2019.8.12

#include <stdio.h>

typedef long long ll;

//// 入出力関係
#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

void out(int n) { // 非負整数の表示（出力）
	int i;
	char b[20];

	if (!n) pc('0');
	else {
		i = 0; while (n) b[i++] = n % 10 + '0', n /= 10;
		while (i--) pc(b[i]);
	}
	pc('\n');
}

//// 本問題関連
int p[52][1002];
		
int main()
{
	int n, m, r, c, a, ans;
	
	while (n = in()) {
		m = in();
		for (r = 0; r < m; r++) for (c = 0; c < n; c++) p[r][c] = in();
		ans = 0;
		for (c = 0; c < n; c++) {
			a = 0; for (r = 0; r < m; r++) a += p[r][c];
			if (a > ans) ans = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
