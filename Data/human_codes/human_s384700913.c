#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	int first;
	int second;
} P;

P max(P a, P b)
{
	if (a.first == b.first)
	{
		if (a.second > b.second)
			return a;
		else
			return b;
	}
	else if (a.first > b.first)
		return a;
	else
		return b;
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
int cave[1111][1111];
bool is_prime[1111111];
P memo[1111][1111];
P none;

P dfs(int x, int y)
{
	if (memo[x][y].first != -1 && memo[x][y].second != -1)
	{
		return memo[x][y];
	}
	P res;
	res.first = 0;
	res.second = 0;
	int xx;
	for (xx = x - 1; xx <= x + 1; xx++)
	{
		if (xx >= 0 && xx < 1111 && y + 1 >= 0 && y + 1 < 1111 && cave[xx][y + 1] != 0 && cave[xx][y + 1] <= m)
		{
			res = max(res, dfs(xx, y + 1));
		}
	}
	if (is_prime[cave[x][y]])
	{
		res.first++;
		if (res.second == 0)
		{
			res.second = cave[x][y];
		}
	}
	return memo[x][y] = res;
}

int main(void)
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	int i, j;
	for (i = 0; i < 1111111; i++)
	{
		if (is_prime[i])
		{
			int j;
			for (j = i * 2; j < 1111111; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	int num = 1;
	int x = 1111 / 2;
	int y = 1111 / 2;
	int len = 1;
	int dir = 0;
	none.first = -1;
	none.second = -1;
	while (true)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < len; j++)
			{
				cave[x][y] = num++;
				x += dx[dir];
				y += dy[dir];
			}
			dir = (dir + 1) % 4;
		}
		if (num > 1000000)
		{
			break;
		}
		len++;
	}
	while (true)
	{
		scanf("%d %d", &m, &n);
		if (n == 0)
		{
			break;
		}
		int sx, sy;
		for (i = 0; i < 1111; i++)
		{
			for (j = 0; j < 1111; j++)
			{
				if (cave[i][j] == n)
				{
					sx = i;
					sy = j;
				}
			}
		}
		for (i = 0; i < 1111; i++)
		{
			for (j = 0; j < 1111; j++)
			{
				memo[i][j] = none;
			}
		}
		P ans = dfs(sx, sy);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
