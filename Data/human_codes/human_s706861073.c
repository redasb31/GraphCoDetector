// AOJ 2447 A Two Floors Dungeon
// 2018.2.2 bal4u

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define QMAX 800000
typedef struct { short s; char f, r, c; } Q;
Q q[QMAX+10]; int top, end;

int W, H, S;
char map[53][53];
char sw[11][53][53];
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int memo[1024][2][53][53];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int check(int s, int f, int r, int c)
{
	int i, g;

    if (map[r][c] == '|') return 1;
    g = map[r][c] == '^' || isupper(map[r][c]);
    for (i = 0; i < S; ++i) if ((s >> i) & 1) g ^= sw[i][r][c];
    return f == g;
}

void enq(int ns, int nf, int nr, int nc, int s, int f, int r, int c)
{
	int k;

	if (memo[ns][nf][nr][nc] >= 0) return;
	memo[ns][nf][nr][nc] = k = memo[s][f][r][c] + 1;
	q[end].s = ns, q[end].f = nf, q[end].r = nr, q[end++].c = nc;
}

int calc(int sr, int sc)
{
	int k, s, f, r, c, nr, nc;

	memset(memo, -1, sizeof memo);
	q[0].s = q[0].f = 0, q[0].r = sr, q[0].c = sc, top = 0, end = 1;
	memo[0][0][sr][sc] = 0;
    while (top != end) {
		if (end >= QMAX) break;
		s = q[top].s, f = q[top].f, r = q[top].r, c = q[top++].c;
		if (map[r][c] == '&') return memo[s][f][r][c];
		if (map[r][c] == '|') enq(s, f ^ 1, r, c, s, f, r, c);
		if (isalpha(map[r][c])) {
			k = tolower(map[r][c]) - 'a';
			enq(s ^ (1 << k), f ^ sw[k][r][c], r, c, s, f, r, c);
        }
        for (k = 0; k < 4; k++) {
            nr = r + mov[k][0], nc = c + mov[k][1];
			if (map[nr][nc] == '#') continue;
			if (!check(s, f, nr, nc)) continue;
			enq(s, f, nr, nc, s, f, r, c);
		}
	}
	return -1;
}

int main()
{
	int i, r, c, sr, sc; 
	char buf[53];

	W = in(), H = in();
	sr = -1;
	for (r = 0; r < H; r++) {
		fgets(map[r], 53, stdin);
		if (sr >= 0) continue;
		for (c = 0; c < W; c++) {
			if (map[r][c] == '%') sr = r, sc = c;
        }
	}

	S = in();
	for (i = 0; i < S; i++) {
		for (r = 0; r < H; r++) {
			fgets(buf, 53, stdin);
			for (c = 0; c < W; c++) {
				if (buf[c] == '*') sw[i][r][c] = 1;
			}
		}
	}
	printf("%d\n", calc(sr, sc));
    return 0;
}
