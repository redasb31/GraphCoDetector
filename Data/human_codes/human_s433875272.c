#include <stdio.h>
#define int long long

int MOD(int a, int M){
	a %= M;
	return a >= 0 ? a : a + M;
}

int power(int a, int N, int M){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a, M), N / 2, M);
	}
	else{
		return MOD(a * power(a, N - 1, M), M);
	}
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b){
	return (a / gcd(a, b)) * b;
}

//オイラーのφ関数
//M以下でMと互いに素なものの個数を求める
int Eulers_phi_function(int M){
	int i, j, ans = 1;
	for(i = 2; i * i <= M; i++){
		for(j = 0; M % i == 0; j++, M /= i);
		if(j > 0){
			for(ans *= i - 1; j > 1; j--, ans *= i);
		}
	}
	if(M > 1){
		ans *= M - 1;
	}
	return ans;
}

typedef struct {
	int s;
	int t;
}pair;

//拡張ユークリッドの互除法
//ax + by = gcd(x, y) となる(a, b)を求める
//x > 0, y >= 0 を仮定している
pair Extension_Euclidean(int x, int y){
	if(y == 0){
		return (pair){1, 0};
	}
	else{
		pair p = Extension_Euclidean(y, x % y);
		return (pair){p.t, p.s - p.t * (x / y)};
	}
}

//a = b mod gcd(N, M) を満たすときに連立合同式
//x = a mod N
//x = b mod M
//を解く
int CRT(int a, int b, int N, int M){
	pair p = Extension_Euclidean(N, M);
	return MOD(a + MOD(((b - a) / gcd(N, M)) * p.s, M / gcd(N, M)) * N, lcm(N, M));
}

int solve(int A, int M){
	int x, y;
	if(M == 1){
		x = 100;
	}
	else{
		int phiM = Eulers_phi_function(M);
		y = solve(A, gcd(M, phiM));
		x = CRT(power(A, y, M), MOD(y, phiM), M, phiM);
		if(x < 100){
			x += lcm(M, phiM) * (100 / lcm(M, phiM) + 1);
		}
	}
	return x;
}

signed main(){
	int Q, q, A, M;
	scanf("%lld", &Q);
	for(q = 0; q < Q; q++){
		scanf("%lld%lld", &A, &M);
		printf("%lld\n", solve(A, M));
	}
	return 0;
}