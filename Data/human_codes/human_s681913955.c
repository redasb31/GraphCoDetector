// AOJ 1380 Medical Checkup
// 2018.2.6 bal4u

#include <stdio.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int n, t, h, b, p;

	n = in(), t = in();
	b = p = 0;
	while (n--) {
		h = in();
		if (p < h) p = h;
		printf("%d\n", 1+(t-b)/p + ((t-b)%p >= h));
		b += h;
	}
	return 0;
}
