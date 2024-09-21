#include <stdio.h>
#include <math.h>

//問題文より、入力されるデータの最大個数
#define MAXCOUNT 100

//ユークリッド距離を求める
double euclidean_distance(double x[MAXCOUNT], double y[MAXCOUNT], int n, double p);
//ヘェビシェフ距離を求める
double chebyshev_distance(double x[MAXCOUNT], double y[MAXCOUNT], int n);

int main(void)
{
	int i, j, n;
	double x[MAXCOUNT], y[MAXCOUNT];

	//データの個数を入力
	scanf("%d", &n);

	//ベクトルxを入力
	for(i = 0; i < n; i++){
		scanf("%lf", &x[i]);
	}
	//ベクトルyを入力
	for(i = 0; i < n; i++){
		scanf("%lf", &y[i]);
	}

	//p=1、p=2、p=3の結果を出力
	for(i = 1; i <= 3; i++){
		printf("%lf\n", euclidean_distance(x, y, n, (double)i));
	}
	//p=infinityの結果を出力
	printf("%lf\n", chebyshev_distance(x, y, n));

	return 0;
}

//距離 = (Σ[i = 0 → n] abs(x[i] - y[i])^p)^1/p
double euclidean_distance(double x[MAXCOUNT], double y[MAXCOUNT], int n, double p)
{
	int i;
	double ans;

	ans = 0;

	//データの数だけ繰り返す
	for(i = 0; i < n; i++){
		//fabsでdouble型の絶対値を求める
		ans += pow(fabs(x[i] - y[i]), p);
	}

	ans = pow(ans, (1 / p));

	return ans;
}

//距離 = max(Σ[i = 0 → n] abs(x[i] - y[i]))
double chebyshev_distance(double x[MAXCOUNT], double y[MAXCOUNT], int n)
{
	int i;
	double ans;

	ans = 0;

	for(i = 0; i < n; i++){
		//ansに最大値を格納する
		if(ans < fabs(x[i] - y[i])){
			ans = fabs(x[i] - y[i]);
		}
	}

	return ans;
}
