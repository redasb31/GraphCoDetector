// AOJ 2643: AI
// 2018.1.28 bal4u

#include <stdio.h>

char map[53][53];
char s[1002];
char tr['Z'];
char rot[2][4] = {{3,0,1,2},{1,2,3,0}};
char mov[2][4] = {{-1,0,1,0},{0,1,0,-1}};	// N,E,S,W
char mk[53][53][4][1002];
int ans, r, c, d;		// d: dir
int gr, gc;				// goal

char *prg(char *p);

char *act(char *p)
{
	int nr, nc;

	ans++;
	if (*p == '<' || *p == '>') d = rot[*p=='>'][d];
	else {
		if (*p == '^') nr = r+mov[0][d], nc = c+mov[1][d];
		else           nr = r-mov[0][d], nc = c-mov[1][d];
		if (!map[nr][nc]) r = nr, c = nc;
	}
	return p+1;
}

char *con(int *res, char *p)
{
	int f;

	f = 1; if (*p == '~') p++, f = 0;
	*res = !f;

	if (*p == 'T') *res = f;
	else if (*p == 'C') {
		if (map[r+mov[0][d]][c+mov[1][d]]) *res = f;
	} else if (d == tr[*p]) *res = f;
	return p+1;
}

char *skip(char *p, char a, char b)
{
	int f = 1;
	while (*p > ' ') {
		if (*p == b) f++;
		else if (*p == a) { if (--f == 0) break; }
		p++;
	}
	return p;
}

char *do_if(char *p)
{
	int f;

	p = con(&f, p);
	if (f) { if ((p = prg(p)) == NULL) return NULL; }
	else p = skip(p, ']', '[');
	if (*p != ']') return NULL;
	return p+1;
}

char *do_while(char *p)
{
	int f;
	char *q;

	for (q = p; ; p = q) {
		p = con(&f, p);
		if (f) { if ((p = prg(p)) == NULL) return NULL; }
		else { p = skip(p, '}', '{'); break; }
	}
	if (*p != '}') return NULL;
	return p+1;
}

char *prg(char *p)
{
	while (1) {
		if (r == gr && c == gc) return NULL;
		if (mk[r][c][d][p-s]) { ans = -1; return NULL; }
		mk[r][c][d][p-s] = 1;

		if (*p <= ' ') { ans = -1; return NULL; }
		if (*p == ']' || *p == '}') break;
		if      (*p == '[') { if ((p = do_if   (p+1)) == NULL) return NULL; }
		else if (*p == '{') { if ((p = do_while(p+1)) == NULL) return NULL; }
		else p = act(p);
	}
	return p;
}

int main()
{
	int H, W, sr, sc;
	char *p;

	tr['N'] = 0, tr['E'] = 1, tr['S'] = 2, tr['W'] = 3;

	fgets(s, 10, stdin), sscanf(s, "%d%d", &H, &W);
	for (r = 0; r < H; r++) {
		fgets(p=map[r], 1002, stdin);
		for (c = 0; c < W; c++, p++) {
			if      (*p == 's') sr = r, sc = c;
			else if (*p == 'g') gr = r, gc = c;
			*p = (*p == '#');
		}
	}
	fgets(s, 1002, stdin);

	r = sr, c = sc, d = 0;
	ans = 0;
	prg(s);
	printf("%d\n", ans);
	return 0;
}

