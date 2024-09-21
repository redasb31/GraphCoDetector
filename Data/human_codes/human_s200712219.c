#include<stdio.h>
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == 2)
	{
		if (k == 0)
		{
			printf("1\n");
			printf("1 2\n");
			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	if (n == 3)
	{
		if (k == 0)
		{
			printf("3\n");
			printf("1 2\n2 3\n1 3\n");
			return 0;
		}
		if (k == 1)
		{
			printf("2\n");
			printf("1 2\n2 3\n");
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	int max = (n - 1) * (n - 2) / 2;
	if (k > max)
	{
		printf("-1\n");
		return 0;
	}
	int m = 0;
	int ans1[10004], ans2[10004];
	int i, j;
	for (i = 1; i < n; i++)
	{
		ans1[m] = 1;
		ans2[m] = i + 1;
		m++;
	}
	i = 2;
	j = 3;
	while (max > k)
	{
		max--;
		ans1[m] = i;
		ans2[m] = j;
		m++;
		j++;
		if (j > n)
		{
			i++;
			j = i + 1;
		}
	}
	printf("%d\n", m);
	for (i = 0; i < m; i++)
		printf("%d %d\n", ans1[i], ans2[i]);
	return 0;
}
