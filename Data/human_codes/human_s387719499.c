// AOJ 1534 Sum of Last Digits
// 下一桁のべき乗について、その周期性に注目
// 2019.3.31 bal4u

#include <stdio.h>
#include <stdlib.h>

int t[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
int f[4];

int main()
{
	int i, n, m, k, a, nm;
	long long _n, ans;

	scanf("%lld%d%d", &_n, &m, &k);
	n = (int)(_n % 10);
	if (n == 0 || n == 1 || n == 5 || n == 6) ans = n * (long long)k;  // いくらべき乗しても下一桁が変わらないもの
	else {
		nm = t[n][m % 4];                      // n^m　の下一桁

		f[0] = f[1] = f[2] = f[3] = --k / 4;   // n^m, n^(2m), n^(3m), n^(4m) それぞれの個数
		for (i = 0; i < k % 4; i++) f[i]++;

		ans = t[n][1];                         // 最初の項  n%10
		a = 1;  for (i = 0; i < 4; i++) {      // n^m ~ n^(4m)各項の累積和
			a *= nm;                           // aは n^m, n^(2m), n^(3m), n^(4m) の下一桁になる
			ans += (long long)f[i] * ((a*n) % 10);          // されに n をかける
		}
	}
	printf("%lld\n", ans);
	return 0;
}
