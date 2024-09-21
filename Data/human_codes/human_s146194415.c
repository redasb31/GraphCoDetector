// AOJ 3126 Ninja E869120
// 2020.1.14 bal4u

#include <stdio.h>
#include <string.h>

#define gc() getchar_unlocked()

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

int ins(char *s) { // 文字列の入力　スペース以下の文字で入力終了
	char *p = s--;
	do *++s = gc();
	while (*s > ' ');
	*s = 0;
	return s - p;
}

char S[105];
char *E = "E869120";

int main()
{
	int N, w, ans;
	
	N = in();
	ans = 0;
	while (N--) {
		w = ins(S);
		if (w == 7 && memcmp(S, E, 7) == 0) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}

