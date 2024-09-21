// AOJ 1524 Rolling Block
// 2019.2.28 bal4u

#include <stdio.h>
#include <stdlib.h>

#define QMAX 5000000
typedef struct { char r, c, d, sw; int s; } Q;
Q q[QMAX + 2]; int top, end;
int mv[3][4][3] = {
	{{-1,0,2},{1,0,2},{0,-1,1},{0,1,1}},  // 直列状態から上下左右に転ぶ
	{{-1,0,1},{1,0,1},{0,-1,0},{0,1,0}},  // 横（東西方向）の状態から
	{{-1,0,0},{1,0,0},{0,-1,2},{0,1,2}}   // 縦（南北方向）の状態から
};

int H, W, L;
char map[30][30];
int SR, SC, GR, GC;
char visited[30][30][128];

void add(int r, int c, int d, int sw, int s)
{
	if (visited[r][c][(d << 5) | sw]) return;
	q[end].r = r, q[end].c = c, q[end].d = d, q[end].sw = sw, q[end].s = s;
	if (++end == QMAX) end = 0;
}

int bfs()
{
	int i, j, r, c, d, rr, cc, dd, s, sw;

	q[0].r = SR, q[0].c = SC, q[0].d = 0, q[0].sw = 0, q[0].s = 0;
	top = 0, end = 1;
	while (top != end) {
		r = q[top].r, c = q[top].c, d = q[top].d, sw = q[top].sw;
		s = q[top].s;
//		printf("(%d,%d) dir=%d, sw=%d, step=%d, top=%d, end=%d\n", r, c, d, sw, s, top, end);
		if (++top == QMAX) top = 0;
		if (r == GR && c == GC && d == 0) return s;
		if (visited[r][c][(d << 5) | sw]) continue;
		visited[r][c][(d << 5) | sw] = 1;

		s++;
		for (i = 0; i < 4; i++) {
			rr = r + mv[d][i][0], cc = c + mv[d][i][1], dd = mv[d][i][2];
			if      (d == 0 && dd == 2 && i == 0) rr -= L - 1;
			else if (d == 0 && dd == 1 && i == 2) cc -= L - 1;
			else if (d == 1 && dd == 0 && i == 3) cc += L - 1;
			else if (d == 2 && dd == 0 && i == 1) rr += L - 1;

			if (dd == 0) {  // 直列状態になった
				if (rr < 0 || rr >= H || cc < 0 || cc >= W) continue;
				if (map[rr][cc] == '^' || map[rr][cc] == '#') continue;
				if (map[rr][cc] >= 'a' && map[rr][cc] <= 'e') {
					if (sw ^ (1 << (map[rr][cc] - 'a'))) continue;
				}
				if (map[rr][cc] >= 'A' && map[rr][cc] <= 'E') {
					int a = sw ^ (1 << (map[rr][cc] - 'A'));
					add(rr, cc, dd, a, s);
				}
				else add(rr, cc, dd, sw, s);
			}
			else if (dd == 1) {  // 横（東西方向）に転んだ
				if (rr < 0 || rr >= H || cc < 0 || cc + L >= W) continue;
				for (j = 0; j < L; j++) {
					if (map[rr][cc + j] == '#') break;
					if (map[rr][cc + j] >= 'a' && map[rr][cc + j] <= 'e') {
						if (sw ^ (1 << (map[rr][cc + j] - 'a'))) break;
					}
				} if (j < L) continue;
				add(rr, cc, dd, sw, s);
			}
			else {  // 縦（南北方向）に転んだ
				if (rr < 0 || rr + L >= H || cc < 0 || cc >= W) continue;
				for (j = 0; j < L; j++) {
					if (map[rr + j][cc] == '#') break;
					if (map[rr + j][cc] >= 'a' && map[rr + j][cc] <= 'e') {
						if (sw ^ (1 << (map[rr + j][cc] - 'a'))) break;
					}
				} if (j < L) continue;
				add(rr, cc, dd, sw, s);
			}
		}
	}
	return -1;
}

int main()
{
	int r, c;

	scanf("%d%d%d", &H, &W, &L);
	for (r = 0; r < H; r++) {
		scanf("%s", map[r]);
		for (c = 0; c < W; c++) {
			if (map[r][c] == 'S') SR = r, SC = c, map[r][c] = '.';
			else if (map[r][c] == 'G') GR = r, GC = c, map[r][c] = '.';
		}
	}
	printf("%d\n", bfs());
	return 0;
}
