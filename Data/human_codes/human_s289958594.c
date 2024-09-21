// AOJ 2723 Surface Area of Cubes
// 2018.2.7 bal4u
 
#include <stdio.h>
#include <string.h>

#define HSIZ 3011
typedef struct { int x, y, z; } HASH;
HASH hash[HSIZ+2], *hashend = hash+HSIZ;

int lookup(int x, int y, int z)
{
	long long h = (long long)x*103 + (long long)y*331 + z;
	HASH *p = hash + (int)(h % HSIZ);
	while (p->x) {
		if (p->x == x && p->y == y && p->z == z) return 1;
		if (++p == hashend) p = hash;
	}
	return 0;
}

void insert(int x, int y, int z)
{
	long long h = (long long)x*103 + (long long)y*331 + z;
	HASH *p = hash + (int)(h % HSIZ);
	while (p->x) {
		if (p->x == x && p->y == y && p->z == z) return;
		if (++p == hashend) p = hash;
	}
	p->x = x, p->y = y, p->z = z;
}

int x[1002], y[1002], z[1002];
int dx[6] = {1,0,0,-1,0,0}, dy[6] = {0,1,0,0,-1,0}, dz[6] = {0,0,1,0,0,-1};

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	while (c < '0') c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int a, b, c, n, f;
	int i, j, nx, ny, nz;
	long long ans;

	a = in(), b = in(), c = in(), n = in();
	for (i = 0; i < n; i++) {
		x[i] = in(), y[i] = in(), z[i] = in();
		insert(x[i], y[i], z[i]);
	}

	ans = (long long)a*b + (long long)b*c + (long long)c*a;
	ans <<= 1;
	for (i = 0; i < n; i++) {
	    f = 0;
		for (j = 0; j < 6; j++) {
			nx = x[i] + dx[j], ny = y[i] + dy[j], nz = z[i] + dz[j];
			if (nx < 0 || nx >= a || ny < 0 || ny >= b ||
				nz < 0 || nz >= c || lookup(nx, ny, nz)) f--;
			else f++;
		}
		ans += f;
	}
	printf("%lld\n", ans);
	return 0;
}
