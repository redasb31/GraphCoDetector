#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n = 0 ;
	int l = 0;
	scanf("%d%d", &l,&n);
	int *p;
	p = calloc(l,sizeof(int));
	int i,j,k=0;
	int point = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		p[k] = 1;
	}
	int left_point=0;
	int right_point=0;
	int left = 0;
	int right = 0;
	int sum = 0;
	for (j = 0; j < n; j++) {
		left_point = right_point = point;
		for (i = 0; i < l; i++)
		{
			if (left_point == 0)
				left_point = l - 1;
			else
				left_point--;
			if (p[left_point] == 1)
			{
				left = left_point;
				break;
			}
		}
		for (k = 0; k < l; k++)
		{
			if (right_point == l - 1)
				right_point = 0;
			else
				right_point++;
			if (p[right_point] == 1)
			{
				right = right_point;
				break;
			}
		}

		if (i >= k)
		{
			point = left;
			sum += (i+1);
		}
		else
		{
			point = right;
			sum += (k+1);
		}
		p[point] = 0;
	}
	free(p);
		printf("%d",sum);
	return 0;
}