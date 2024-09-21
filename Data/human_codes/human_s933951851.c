#include<stdio.h>
#include<stdlib.h>
long long int x[100005], y[100005];
int asc1(const void* a, const void* b)
{
	if (x[*(int*)a] > x[*(int*)b])return 1;
	if (x[*(int*)a] < x[*(int*)b])return -1;
	return 0;
}
int asc2(const void* a, const void* b)
{
	if (y[*(int*)a] > y[*(int*)b])return 1;
	if (y[*(int*)a] < y[*(int*)b])return -1;
	return 0;
}
long long int llabs(long long int n)
{
	if (n < 0)
		n *= -1;
	return n;
}
long long int dist(long long int a, long long int b)
{
	if (llabs(x[a] - x[b]) < llabs(y[a] - y[b]))
		return llabs(x[a] - x[b]);
	else
		return llabs(y[a] - y[b]);
}
long long int h[200005], l;
void swap_h(long long int a, long long  int b)
{
	long long int f = h[a];
	h[a] = h[b];
	h[b] = f;
	return;
}
int comp_h(long long int a, long long int b)
{
	long long int a1, a2, b1, b2;
	a = h[a];
	b = h[b];
	a1 = a / 100000;
	a2 = a % 100000;
	b1 = b / 100000;
	b2 = b % 100000;
	if (dist(a1, a2) > dist(b1, b2))return 1;
	return 0;
}
void f1(long long int n)
{
	h[l] = n;
	long long int now = l;
	l++;
	while (now > 0)
	{
		if (comp_h((now - 1) / 2, now) > 0)
			swap_h((now - 1) / 2, now);
		now = (now - 1) / 2;
	}
	return;
}
long long int f2()
{
	l--;
	swap_h(0, l);
	long long int now = 0;
	for (;;)
	{
		if (2 * now + 2 < l)
		{
			if (comp_h(2 * now + 1, 2 * now + 2) > 0)
			{
				if (comp_h(now, 2 * now + 2) > 0)
					swap_h(now, 2 * now + 2);
				now = 2 * now + 2;
			}
			else
			{
				if (comp_h(now, 2 * now + 1) > 0)
					swap_h(now, 2 * now + 1);
				now = 2 * now + 1;
			}
		}
		else if (2 * now + 1 < l)
		{
			if (comp_h(now, 2 * now + 1) > 0)
				swap_h(now, 2 * now + 1);
			now = 2 * now + 1;
		}
		else
			break;
	}
	return h[l];
}
int p[100005];
int root(int n)
{
	if (p[n] != n)
		p[n] = root(p[n]);
	return p[n];
}
void uni(int a, int b)
{
	a = root(a);
	b = root(b);
	if (a != b)
		p[a] = b;
	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	int a[100005], b[100005];
	for (i = 0; i < n; i++)
		a[i] = b[i] = i;
	qsort(a, n, sizeof(int), asc1);
	qsort(b, n, sizeof(int), asc2);
	l = 0;
	for (i = 0; i < n - 1; i++)
		f1(100000 * a[i] + a[i + 1]);
	for (i = 0; i < n - 1; i++)
		f1(100000 * b[i] + b[i + 1]);
	for (i = 0; i < n; i++)
		p[i] = i;
	long long int ans = 0;
	while (l > 0)
	{
		i = f2();
		j = i / 100000;
		i %= 100000;
		if (root(i) != root(j))
		{
			ans += dist(i, j);
			uni(i, j);
		}
	}
	printf("%lld\n", ans);
	return 0;
}