#include <stdio.h>

int main(void)
{
	int n, k, a;
	int i;
	int result;

	scanf("%d %d", &n, &k);

	int numbers[n][1];

	i = 0;
	while (i < (n + 1))
	{
		numbers[i++][0] = 0;
	}

	i = 0;
	while (i < n)
	{
		scanf("%d ", &a);
		numbers[a][0]++;
		i++;
	}

	result = 0;
	while (1)
	{
		int count;
		int	min;
		int j;

		min = 9999;
		count = i = j = 0;
		while (i < (n + 1))
		{
			if (numbers[i][0] != 0)
			{
				count++;
			}
			if (numbers[i][0] < min && numbers[i][0] != 0)
			{
				j = i;
				min = numbers[i][0];
			}
			i++;
		}
		if (k < count)
		{
			result += numbers[j][0];
			numbers[j][0] = 0;
		}
		else
		{
			break;
		}
	}

	printf("%d", result);

	return 0;
}