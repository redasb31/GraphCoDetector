#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int int_pow(int a, int x)
{
	int i = 0;
	int r = 1;
	while (i < x)
	{
		r = r*a;
		i++;
	}
	return (r);
}
int main (void)
{
	int n, m;
	scanf("%d %d",&n,&m);
	int *k;
	k = (int *)malloc(sizeof(int)*(m));
	int **s;
	s = (int **)malloc(sizeof(int *)*(m));
	int i = 0;
	int j = 0;
	while (i < m)
	{
		j = 0;
		scanf("%d", &(k[i]));
		s[i] = (int *)malloc(sizeof(int)*(k[i]));
		while (j < k[i])
		{
			scanf("%d",&(s[i][j]));
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	int *p;
	int on = 0;
	int l = 0;
	p = (int *)malloc(sizeof(int)*(m));
	while (i < m)
	{
		scanf("%d",&p[i]);
		i++;
	}
	int sum = 0;
	i = 0;
	int dig[10];
	//printf("debug0002000\n");
	while (i < int_pow(2,n))
	{
		j = 0;
		//printf("i:%d, j:%d\n",i,j);
		while (j < 10)
		{
			//printf("debug 00090 j:%d\n",j);
			dig[j] = (i/int_pow(2,j))%2;
			j++;
		}
		j = 0;
		//printf("debug 00100 i:%d, j:%d\n",i,j);
		while (j < m)
		{
			l = 0;
			on = 0;
			while (l < k[j])
			{
				if (dig[s[j][l]-1] == 1 )
					on++;
				l++;
			}
			if(on%2 != p[j])
				break;
			j++;
		}
		if (j == m)
			sum++;
		//printf("sum:%d, i:%d\n",sum,i);
		i++;
	}
	printf("%d\n",sum);
	return (0);
}
