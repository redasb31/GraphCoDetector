// AOJ 1517: Matrix Operations
// 2017.9.27 bal4u@uu

#include <stdio.h>
#include <string.h>

int n;
char map[17][17];
char mk[17][17];
int mv[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void rotate(int r, int c, int h, int a)
{
	int i, j, k;
	char tmp[17][17];

	if (a == 360 || n == 1 || h == 1) return;
	k = a / 90; while (k-- > 0) {
		memcpy(tmp, map, sizeof(tmp));
		for (i = 0; i < h; i++) for (j = 0; j < h; j++) {
			map[r+j][c+h-1-i] = tmp[r+i][c+j];
		}
	}
}

void reverse(int r, int c, int h)
{
	int i, j;
	for (i = 0; i < h; i++) for (j = 0; j < h; j++) map[r+i][c+j] = !map[r+i][c+j];
}

void shift(int r, int lr)
{
	int c, t;

	if (n == 1) return;
	if (lr) {
		t = map[r][0];
		for (c = 1; c < n; c++) map[r][c-1] = map[r][c];
		map[r][n-1] = t;
	} else {
		t = map[r][n-1];
		for (c = n-2; c >= 0; c--) map[r][c+1] = map[r][c];
		map[r][0] = t;
	}
}

int q[300][2], top;
void islandRev(int r, int c)
{
	int a, i, r2, c2;

	memset(mk, 0, sizeof(mk));
	a = map[r][c]; map[r][c] = !a; mk[r][c] = 1;
	q[0][0] = r, q[0][1] = c, top = 1;
	while (top > 0) {
		r = q[--top][0], c = q[top][1];
		for (i = 0; i < 4; i++) {
			r2 = r + mv[i][0], c2 = c + mv[i][1];
			if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || map[r2][c2] != a) continue;
			if (mk[r2][c2]) continue;
			mk[r2][c2] = 1;
			map[r2][c2] = !a;
			q[top][0] = r2, q[top++][1] = c2;
		}
	}
}

int main()
{
	int m, o, r, c, h, a;

	scanf("%d%d", &n, &m);
	for (r = 0; r < n; r++) for (c = 0; c < n; c++) scanf("%d", &a), map[r][c] = a;
	while (m-- > 0) {
		scanf("%d", &o);
		if (o == 0) {  // rotate
			scanf("%d%d%d%d", &r, &c, &h, &a);
			rotate(r-1, c-1, h, a);
		} else if (o == 1) {
			scanf("%d%d%d", &r, &c, &h);
			reverse(r-1, c-1, h);
		} else if (o == 2) {
			scanf("%d", &r);
			shift(r-1, 1);
		} else if (o == 3) {
			scanf("%d", &r);
			shift(r-1, 0);
		} else {
			scanf("%d%d", &r, &c);
			islandRev(r-1, c-1);
		}
	}
	for (r = 0; r < n; r++) {
		printf("%d", map[r][0]);
		for (c = 1; c < n; c++) printf(" %d", map[r][c]);
		putchar('\n');
	}
	return 0;
}