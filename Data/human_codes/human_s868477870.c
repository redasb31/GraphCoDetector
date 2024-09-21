// AOJ 2946 You Should Avoid
// 2019.8.8 bal4u

#include <stdio.h>
#include <string.h>

#if 1
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#endif

int in(int *x)   // 整数の入力（負数対応）
{
	int n = 0, c = gc();
	if (c < 0) return 0;
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		*x = -n;
	} else {
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		*x = n;
	}
	return 1;
}

void out(int n) { // 正整数の表示（出力）
	int i;
	char b[20];
	i = 0; while (n) b[i++] = n % 10 + '0', n /= 10;
	while (i--) pc(b[i]);
}

int main()
{
	int x, y;
	
	while (in(&x)) {
		in(&y);
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		if (x+y == 0) pc('0');
		else if (x+y == 1 || (x && y && x+y == 2)) pc('1');
		else {
			if ((x == 0 || y == 0) && ((x+y) & 1)) x += y+1;
			else if ((x & 1) && (y & 1)) x += y-1;
			else x += y;
			out(x);
		}
		pc('\n');
	}
	return 0;
}
