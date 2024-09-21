#include<stdio.h>
#include<stdlib.h>
long long int a[5003], b[5003], c[5003];
int asc(const void* x, const void* y)
{
	if (a[*(long long int*)x] > a[*(long long int*)y])return 1;
	if (a[*(long long int*)x] < a[*(long long int*)y])return -1;
	return 0;
}
int main()
{
	long long int n, m, p;
	scanf("%lld %lld %lld", &n, &m, &p);
	long long int i;
	for (i = 0; i < m; i++)
	{
		scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		a[i]--;
		b[i]--;
	}
	long long int d[5003];
	for (i = 0; i < m; i++)
		d[i] = i;
	qsort(d, n, sizeof(long long int), asc);
	long long int ans = 0;
	long long int t;
	int min, max, mid;
	long long int res[2][2503];
	for (i = 0; i < n; i++)
		res[0][i] = 0;
	for (t = 0; t < n * m + 100; t++)
	{
		for (i = 0; i < n; i++)
			res[1][i] = 0;
		for (i = 0; i < n; i++)
		{
			min = 0;
			max = m - 1;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (a[d[mid]] >= i)
					max = mid;
				else
					min = mid;
			}
			while (a[d[min]] == i)
			{
				if (res[1][b[d[min]]] < res[0][a[d[min]]] + c[d[min]])
					res[1][b[d[min]]] = res[0][a[d[min]]] + c[d[min]];
				min++;
			}
		}
		for (i = 0; i < n; i++)
			res[0][i] = res[1][i];
		if (ans < res[0][n - 1] - (p * (t + 1)))
			ans = res[0][n - 1] - (p * (t + 1));
	}
	for (; t < n * m + 200; t++)
	{
		for (i = 0; i < n; i++)
			res[1][i] = 0;
		for (i = 0; i < n; i++)
		{
			min = 0;
			max = m - 1;
			while (max - min > 1)
			{
				mid = (max + min) / 2;
				if (a[d[mid]] >= i)
					max = mid;
				else
					min = mid;
			}
			while (a[d[min]] == i)
			{
				if (res[1][b[d[min]]] < res[0][a[d[min]]] + c[d[min]])
					res[1][b[d[min]]] = res[0][a[d[min]]] + c[d[min]];
				min++;
			}
		}
		for (i = 0; i < n; i++)
			res[0][i] = res[1][i];
		if (ans < res[0][n - 1] - (p * (t + 1)))
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}