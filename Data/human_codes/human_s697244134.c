#include <stdio.h>          // printf(), scanf()
#include <stdlib.h>         // qsort()
#include <string.h>         // memset(), memcpy(), strchr()
#include <stdbool.h>

// #define DEBUG 1

#define MAX_W 200
#define MAX_H 200
#define MAX_N 10

typedef struct order_tbl
{
	int s;
	int bx;
	int by;
	int angle;
	double rate;
} order_t;

const char NUL = '\0';

#ifdef DEBUG
static int O = 0;
#endif

int H, W;
char field[MAX_H][MAX_W + 1];
char puzzle[MAX_H][MAX_W + 1];
int n;
int h0[MAX_N][4];
int w0[MAX_N][4];
char piece[MAX_N][4][MAX_H][MAX_W + 1];
int k;
int t[MAX_N];

void
bury(order_t *u)
{
	int s = u->s;
	int a = u->angle;
	int h = h0[s][a];
	int w = w0[s][a];

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (piece[s][a][y][x] == '#')
				field[u->by + y][u->bx + x] = '*';
		}
	}
}

double
fitin(order_t *u, int a, int bx, int by)
{
	int s = u->s;
	int h = h0[s][a];
	int w = w0[s][a];

	int dx[4] = { 0, 1, 0,-1};
	int dy[4] = { 1, 0,-1, 0};

	int count = 0;
	int total = 0;
	for (int x = -1; x <= w; ++x)
	{
		int nx = bx + x;
		for (int y = -1; y <= h; ++y)
		{
			int ny = by + y;
			if (0 <= x && x < w && 0 <= y && y < h && piece[s][a][y][x] == '#')
			{
				if (field[ny][nx] != '.')
					return -100.0;
			}
			else // piece[s][a][y][x] == '.' ?
			{
				int i;
				for (i = 0; i < 4; ++i)
				{
					int tx = x + dx[i], ty = y + dy[i];
					if (0 <= tx && tx < w && 0 <= ty && ty < h && piece[s][a][ty][tx] == '#')
						break;
				}

				if (i < 4)
				{
					total++;
					if (nx < 0 || W <= nx || ny < 0 || H <= ny || field[ny][nx] != '.')
						count++;
				}
			}
		}
	}

	return count * 100.0 / total;
}

void
probe(order_t *u)
{
	int s = u->s;
	for (int a = 0; a < 4; ++a)
	{
		int h = h0[s][a];
		int w = w0[s][a];

		int fx = strchr(piece[s][a][0], '#') - piece[s][a][0];
		for (int by = 0; by + h <= H; ++by)
		{
			for (int bx = 0; bx + w <= W; ++bx)
			{
				if (field[by][bx + fx] == '.')
				{
#ifdef DEBUG
					O++;
#endif
					double r = fitin(u, a, bx, by);
					if (r > u->rate)
					{
						u->rate = r;
						u->bx = bx;
						u->by = by;
						u->angle = a;

						if (u->rate >= 100.0)
						{
							bury(u);
							return;
						}
					}
				}
			}
		}
	}
}

int
cmp_func(const void *l_, const void *r_)
{
	const order_t *l = (const order_t*) l_;
	const order_t *r = (const order_t*) r_;

	if (l->rate < r->rate)
		return 1;

	if (l->rate > r->rate)
		return -1;

	return 0;
}

bool
solve()
{
	order_t u;
	order_t order[MAX_N];
	int memo[MAX_N];
	int ix, ix2;

	memcpy(field, puzzle, sizeof(field));
	ix = 0;
	for (int i = 0; i < k; ++i)
		memo[ix++] = t[i];

	while (ix != 0)
	{
		ix2 = 0;
		for (int i = 0; i < ix; ++i)
		{
#ifdef DEBUG
			memset(&u, 0x00, sizeof(u));
#endif
			u.s = memo[i];
			u.rate = -100.0;
			probe(&u);
			if (u.rate != 100.0)
				order[ix2++] = u;
		}

		if (ix2 == 0)
			break;

		qsort(order, ix2, sizeof(order_t), cmp_func);
		if (order[0].rate == -100.0)
			return false;

		bury(&order[0]);

		ix = 0;
		for (int i = 1; i < ix2; ++i)
			memo[ix++] = order[i].s;
	}

	for (int y = 0; y < H; ++y)
	{
		for (int x = 0; x < W; ++x)
		{
			if (field[y][x] == '.')
				return false;
		}
	}

	return true;
}

int
main(int argc, char **argv)
{
	while (true)
	{
		scanf("%d%d", &H, &W);
		if (H == 0 && W == 0)
			break;

		for (int i = 0; i < H; ++i)
			scanf("%s", &puzzle[i][0]);

		scanf("%d", &n);
		for (int s = 0; s < n; ++s)
		{
			scanf("%d%d", &h0[s][0], &w0[s][0]);
			int h = h0[s][0];
			int w = w0[s][0];

			for (int y = 0; y < h; ++y)
				scanf("%s", &piece[s][0][y][0]);

			h0[s][1] = w;
			w0[s][1] = h;
			for (int y = 0; y < h; ++y)
			{
				for (int x = 0; x < w; ++x)
					piece[s][1][x][h - y - 1] = piece[s][0][y][x];
			}

#ifdef DEBUG
			for (int x = 0; x < w; ++x)
				piece[s][1][x][h] = NUL;
#endif

			h0[s][2] = h;
			w0[s][2] = w;
			for (int y = 0; y < h; ++y)
			{
				for (int x = 0; x < w; ++x)
					piece[s][2][h - 1 - y][w - 1 - x] = piece[s][0][y][x];

#ifdef DEBUG
				piece[s][2][h - 1 - y][w] = NUL;
#endif
			}

			w0[s][3] = h;
			h0[s][3] = w;
			for (int y = 0; y < h; ++y)
			{
				for (int x = 0; x < w; ++x)
					piece[s][3][w - 1 - x][y] = piece[s][0][y][x];
			}

#ifdef DEBUG
			for (int x = 0; x < w; ++x)
				piece[s][3][x][h] = NUL;
#endif
		}

		int p;
		scanf("%d", &p);
		for (int i = 0; i < p; ++i)
		{
			scanf("%d", &k);
			for (int j = 0; j < k; ++j)
			{
				scanf("%d", &t[j]);
				t[j]--;
			}

			printf("%s\n", solve() ? "YES" : "NO");
		}
	}

#ifdef DEBUG
	fprintf(stderr, "O:%d\n", O);
#endif
	return 0;
}