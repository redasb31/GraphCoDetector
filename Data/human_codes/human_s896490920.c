// AOJ 1633 On-Screen Keyboard
// bal4u 2019.8.12

#include <stdio.h>

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

void ins(char *s) { // 文字列の入力　スペース以下の文字で入力終了
	do *s = gc();
	while (*s++ > ' ');
	*(s-1) = 0;
}

void out(int n) { // 正整数の表示（出力）
	int i; char b[20];
	i = 0; while (n) b[i++] = n % 10 + '0', n /= 10;
	while (i--) pc(b[i]);
	pc('\n');
}

//// 本問題関連
#define ABS(x) ((x)>=0?(x):-(x))
int ch[128][2];
char s[1005];
		
int main()
{
	int h, w, r, c, ans;
	char *p;
	
	while (h = in()) {
		w = in();
		for (r = 0; r < h; r++) {
			for (c = 0; c < w; c++) {
				int a = gc();
				ch[a][0] = r, ch[a][1] = c;
			}
			gc();
		}
		ins(s), ans = 0, r = c = 0;
		for (p = s; *p; p++) {
			ans += 1 + ABS(ch[*p][0] - r) + ABS(ch[*p][1] - c);
			r = ch[*p][0], c = ch[*p][1];
		}
		out(ans);
	}
	return 0;
}
