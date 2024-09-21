#include <stdio.h>

int sum_digit(int a);
int nPower(int x, int n);

int main(void)
{
	int i;
	int a, n, m;
	int count;
	
	scanf("%d %d %d", &a, &n, &m);
	
	for (i = 1, count = 0; i <= m; i++){
		if (i == nPower((sum_digit(i) + a), n)){
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return (0);
}

int sum_digit(int a)
{
	int sum = 0;
	
	while (a > 0){
		sum += a % 10;
		a /= 10;
	}
	
	return (sum);
}

int nPower(int x, int n)
{
	int i;
	int res;
	
	if (n == 0) return (1);
	
	for (i = 0, res = x; i < n - 1; i++) res *= x;
	
	return (res);
}

