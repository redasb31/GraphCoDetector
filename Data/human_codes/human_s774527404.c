// AOJ 1212: Mirror Illusion
// 2017.10.23 bal4u@uu

#include <stdio.h>
#include <string.h>

char xmir[10][10], ymir[10][10];

int main() 
{
	int n, i, x0, y0, x, y;
	char buf[5];

	while (scanf("%d", &n) && n >= 0) {
		memset(xmir, 0, sizeof(xmir)), memset(ymir, 0, sizeof(ymir)); 
		for (i = 0; i < n; i++) {
			scanf("%s%d%d", buf, &x, &y);
			if (*buf == 'x') xmir[x][y] = 1; else ymir[x][y] = 1;
		}
		x0 = 75, y0 = 25, x = 100, y = 0;
		while (1) {
			for ( ; x < 900; x += 100, y += 100) if (ymir[x/100][y/100]) break;
			if (x == 900) { x -= 100, y -= 50; break; }

			x -= 100, y += 100;
			for ( ; y < 900; x -= 100, y += 100) if (xmir[x/100][y/100]) break;
			if (y == 900) { x += 150, y -= 100; break; }

			y -= 100;
			for ( ; x >= 0; x -= 100, y -= 100) if (ymir[x/100][y/100]) break;
			if (x < 0) { x += 100, y += 150; break; }

			for ( ; y >= 0; x += 100, y -= 100) if (xmir[x/100][y/100]) break;
			if (y < 0) { x -= 50, y += 100; break; }
			if (x == 0) { x += 75, y += 25; break; }
		}
		printf("%d %d\n", x, y);
	}
	return 0; 
}