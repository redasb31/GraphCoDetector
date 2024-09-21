#include<stdio.h>

int main(void)
{
	int r = 0;
	int g = 0;
	int b = 0;
	int n = 0;
	int c = 0;

	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);
	scanf("%d", &n);

	for (int i = 0; i <= n / r; i++)
	{
		for (int j = 0; j <= (n - i * r) / g; j++)
		{
			for (int k = 0; k <= (n - i * r - j * g) / b; k++)
			{
				if (k == 0) {
					if ((n - i * r - j * g) == 0) { c = c + 1; }
				}
				else if ((n - i * r - j * g) % b*k == 0)
				{
					c = c + 1; 
				}
				
			}
		}
	}
	printf("%d", c);
	return 0;
}