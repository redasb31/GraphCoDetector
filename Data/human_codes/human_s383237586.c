#include<stdio.h>
#include<string.h>
char s[50][50];
int n;
int i;
int f1(int x);
int f2(int x);
int f1(int x)
{
	int res = 0;
	int d = strlen(s[x]);
	i = x + 1;
	for (; i < n; i++)
	{
		if (strlen(s[i]) != d + 1)
			break;
		if (s[i][d] >= '0' && s[i][d] <= '9')
			res += s[i][d] - '0';
		if (s[i][d] == '+')
			res += f1(i);
		if (s[i][d] == '*')
			res += f2(i);
	}
	i--;
	return res;
}
int f2(int x)
{
	int res = 1;
	int d = strlen(s[x]);
	i = x + 1;
	for (; i < n; i++)
	{
		if (strlen(s[i]) != d + 1)
			break;
		if (s[i][d] >= '0' && s[i][d] <= '9')
			res *= s[i][d] - '0';
		if (s[i][d] == '+')
			res *= f1(i);
		if (s[i][d] == '*')
			res *= f2(i);
	}
	i--;
	return res;
}
int main()
{
	int k, j;
	int ans[10002];

	for (j = 0;; j++)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (k = 0; k < n; k++)
			scanf("%s", s[k]);
		if (n == 1)
		{
			ans[j] = s[0][0] - '0';
			continue;
		}
		if (s[0][0] == '+')
			ans[j] = f1(0);
		else
			ans[j] = f2(0);
	}
	for (k = 0; k < j; k++)
		printf("%d\n", ans[k]);
	return 0;
}
