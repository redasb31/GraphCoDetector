#include <stdio.h>
#include<math.h>

int main()
{
	int i, k = 0;
	double arr[50][11] = { 0 };
	
	while (scanf("%lf",&arr[k][1])!=EOF)
	{
		for (i = 2; i <11; i++)
		{
			if (i%2)
			{
				arr[k][i] = arr[k][i - 1] / 3;
			}
			else
			{
				arr[k][i] = arr[k][i - 1] * 2;
			}
			arr[k][1] += arr[k][i];
		}
		++k;
	}
	
	
	for (i = 0; i < k; i++)
	{
		printf("%.8f\n",arr[i][1]);
	}

	return 0;
}
