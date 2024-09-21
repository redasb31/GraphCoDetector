#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	char s[5003];
	scanf("%s", s);
	int i, j, k;
	int ans = 0;
	int count;
	for (i = 0; i <= n - 1 - ans; i++)
	{
		for (j = i + ans; j <= n - ans; j++)
		{
			count = 0;
			for (k = 0; i + k < j && j + k < n; k++)
			{
				if (s[i + k] == s[j + k])
					count++;
				else
					break;
			}
			if (ans < count)
				ans = count;
		}
	}
	printf("%d\n", ans);
	return 0;
}
