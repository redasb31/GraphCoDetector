#include<stdio.h>
int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int max(int a, int b)
{
	if (a > b)return a;
	else return b;
}
int m;
int smin[500005], smax[500005];
void make()
{
	int i;
	for (i = m - 2; i >= 0; i--)
	{
		smin[i] = min(smin[2 * i + 1], smin[2 * i + 2]);
		smax[i] = max(smax[2 * i + 1], smax[2 * i + 2]);
	}
	return;
}
int fmin(int l, int r, int x, int y, int n)
{
	if (x <= l && r <= y)
		return smin[n];
	if (y < l || r < x)
		return 1000000009;
	return min(fmin(l, (l + r) / 2, x, y, 2 * n + 1), fmin((l + r + 1) / 2, r, x, y, 2 * n + 2));
}
int fmax(int l, int r, int x, int y, int n)
{
	if (x <= l && r <= y)
		return smax[n];
	if (y < l || r < x)
		return 0;
	return max(fmax(l, (l + r) / 2, x, y, 2 * n + 1), fmax((l + r + 1) / 2, r, x, y, 2 * n + 2));
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int i;
	int p[200005];
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	m = 1;
	while (m < n)
		m *= 2;
	for (i = 0; i < m; i++)
	{
		if (i < n)
			smin[i + m - 1] = smax[i + m - 1] = p[i];
		else
		{
			smin[i + m - 1] = 1000000009;
			smax[i + m - 1] = 0;
		}
	}
	make();
	int ans = n - k + 1;
	int count;
	int v[200005];
	for (i = 0; i < n; i++)
		v[i] = 1;
	for (i = n - 2; i >= 0; i--)
		if (p[i] < p[i + 1])
			v[i] += v[i + 1];
	int z = 0;
	if (v[0] >= k)z = 1;
	for (i = 1; i <= n - k; i++)
	{
		if (p[i - 1] == fmin(0, n - 1, i - 1, i + k - 2, 0) && p[i + k - 1] == fmax(0, n - 1, i, i + k - 1, 0))
			ans--;
		else if (v[i] >= k)
		{
			if (z == 0)
				z++;
			else
				ans--;
		}
	}
	printf("%d\n", ans);
	return 0;
}