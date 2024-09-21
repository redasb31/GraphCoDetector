#include<stdio.h>
#include<string.h>
int main(void)
{
	int count=0,nagasa,bangou[500],kotae[500], i, n=1, t;
	
	scanf("%d", &nagasa);
	
	for (i = 0; i < nagasa; i++)
		scanf("%d", &bangou[i]);
	
	for (i = 0; i < nagasa; i++)
	{	
		if (i != 0)
			n += nagasa+1;
		if (bangou[i] == n)
			count++;
	}
	
	if (count == nagasa)
	{
		printf("Yes\n");
		for (i = 1; i <= nagasa; i++)
		{
			for (n = 0; n < nagasa; n++)
			{
				printf("%d ", i);
			}
		}
	}
	else
		printf("No");
	return 0;
}