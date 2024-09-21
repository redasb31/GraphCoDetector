#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(a) (((a)>0)?(a):(-a))

int main()
{
	int n, a[200020];
	long int ans;
	int b, i = 0, j = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		b = 0;
		ans += j - i;
		for (; j < n && !(b&a[j]); j++)
		{
			b = b | a[j];
			ans++;
		}
	}
	printf("%ld", ans);
	return 0;
}