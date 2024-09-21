// AOJ 2909 Nim without Zero
// 2018.4.5 bal4u

#include <stdio.h>
#include <string.h>

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

int main() {

	int N, a, b = 1, ans = 0;

	N = in();
	while (N--) {
		a = in();
		ans ^= a, b &= !(a & 1);
	}
	puts((ans == 1 || (ans == 0 && b))? "Bob": "Alice");
	return 0;
}

