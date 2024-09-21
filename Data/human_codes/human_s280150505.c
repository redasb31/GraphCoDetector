// AOJ 1375 Skinny Polygon
// 2018.3.21 bal4u

#include <stdio.h>
#include <stdlib.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int extended_gcd(int a, int b, int *x, int *y)
{
	int _gcd;
	if (b == 0) { *x = 1; *y = 0; return a; }
	_gcd = extended_gcd(b, a%b, y, x);
	*y -= a / b * (*x);
	return _gcd;
}

int main()
{
	int n, x, y, a, b, g;

	n = in();
	while (n--) {
		x = in(), y = in();
		g = extended_gcd(x, y, &a, &b);
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		if (g < 50000) {
			printf("3\n0 0\n%d %d\n%d %d\n", x, y, a, b);
		} else {
			printf("4\n0 0\n%d %d\n1 1\n%d %d\n", x/g, y, x, y/g);
		}
	}
	return 0;
}
