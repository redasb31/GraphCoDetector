// AOJ 	2302: On or Off
// 2018.1.31 bal4u

#include <stdio.h>
#include <string.h>

typedef struct { int r, c, t; } Q;
Q q[2600]; int top, end;

char map[53][53];
char pr[53][53], prev[53][53][2];		// prev (r,c)
int tbl[3][53][53];
int cost[53][53];
int visited[53][53];
char mk[53][53];
int mv[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

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
	int R, C, M, i, k, r, c, t, nr, nc, sr, sc, gr, gc, tm, ans;
	
	R = in(), C = in(), M = in();
	for (r = 0; r < R; r++) fgets(map[r], 53, stdin);
	for (k = 0; k < 3; k++) {
		for (r = 0; r < R; r++) for (c = 0; c < C; c++) tbl[k][r][c] = in();
	}

	tm = 1;
	sr = in(), sc = in();
	visited[sr][sc] = tm, cost[sr][sc] = tbl[1][sr][sc];
	while (--M) {
		gr = in(), gc = in();
		memset(mk, 0, sizeof(mk));
		q[0].r = sr, q[0].c = sc, q[0].t = tm, top = 0, end = 1;
		while (top != end) {
			r = q[top].r, c = q[top].c, t = q[top++].t;
			if (r == gr && c == gc) break;
			if (mk[r][c]) continue;
			mk[r][c] = 1;
			for (i = 0; i < 4; i++) {
				nr = r+mv[i][0], nc = c+mv[i][1];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
					map[nr][nc] == '#' || mk[nr][nc]) continue;
				prev[nr][nc][0] = r, prev[nr][nc][1] = c;
				q[end].r = nr, q[end].c = nc, q[end++].t = t+1;
			}
		}
		nr = gr, nc = gc, tm = t;
		while (nr != sr || nc != sc) {
			if (!visited[nr][nc]) cost[nr][nc] = tbl[1][nr][nc];
			else {
				k = (t - visited[nr][nc])*tbl[0][nr][nc];
				if (k > tbl[1][nr][nc]+tbl[2][nr][nc]) k = tbl[1][nr][nc]+tbl[2][nr][nc];
				cost[nr][nc] += k;
			}
			visited[nr][nc] = t;
			r = prev[nr][nc][0], c = prev[nr][nc][1], t--;
			nr = r, nc = c;
		}
		sr = gr, sc = gc;
	}

	ans = 0;
	for (r = 0; r < R; r++) for (c = 0; c < C; c++) {
		if (visited[r][c]) ans += cost[r][c] + tbl[2][r][c];
	}
	printf("%d\n", ans);
	return 0;
}
