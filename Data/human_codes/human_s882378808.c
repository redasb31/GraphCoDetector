#include <stdio.h>
long long int bitwise(int k, int n, int *a, int *b) {
	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if ((k|a[i])==k)	ans += b[i];
	}
	return ans;
}

int main() {
	int n, k, a[100010], b[100010], temp;
	long long int ans, x;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	ans = bitwise(k, n, a, b);
	for (int j = 0; j < 30; j++)
	{
		if (k &(1 << j))
		{
			temp = (k&~(1 << j)) | ((1 << j) - 1);
			x = bitwise(temp, n, a, b);
			ans = (ans > x) ? ans : x;
		}
	}
	printf("%d", ans);
	return 0;
}