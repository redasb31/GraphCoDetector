#include<stdio.h>
int main(void)
{
	int i=0,j=0,q,x,y,a[50],b[50];

	scanf("%d", &x); scanf("%d", &y);

	for (i; i < y; i++)
	{
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
	}

	int c[50] = { 0 };

	for (j;j<x; j++)
	{
		for (q = 1; q <= x; q++)
		{
			if (a[j] == q)
			{
				c[q-1] = c[q-1] + 1;
			}
			if (b[j] == q)
			{
				c[q-1] = c[q-1] + 1;
			}
		}
		
	}

	for (q = 0; q <x; q++)
	{
		printf("%d\n", c[q]);
	}
	return 0;
}