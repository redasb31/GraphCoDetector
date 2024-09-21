#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIG 2000000007

#define MOD 1000000007
typedef unsigned long long ull;
typedef   signed long long sll;


#define N_MAX 100
#define M_MAX 20

ull n, m, k;
ull h, w;
ull a[N_MAX];
// ull b[M_MAX][N_MAX];
ull dp[N_MAX][M_MAX + 1];
// char s[N_MAX][M_MAX + 1];

void swap_adj(ull *a, ull *b){
	ull tmp = *b;
	*b = *a;
	*a = tmp;
	return;
}

int comp(const void *a, const void *b){
	if (*(ull*)a > *(ull*)b) {
		return -1;
	} else if (*(ull*)a < *(ull*)b) {
		return +1;
	} else {
		return 0;
	}
}

ull divide(ull a, ull b){
	ull x = MOD - 2;
	ull ans = 1;
	while (x) {
		if (x & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		x /= 2;
	}
	return (a * ans) % MOD;
}

int digits(ull x){
	int i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

int min(ull x, ull y){
	return (x < y) ? x : y;
}

ull gdb(ull x, ull y){
	if (x < y) {
		return gdb(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return (y, x % y);
	}
}

ull solve(){
	int i, j;
	ull result = 1;

	for (i = 0; i < n; i++) {
		result = (result / gdb(result, a[i])) * a[i];
		printf("%d %llu\n", i, result);
	}

	return result;
}

int main(void){
	ull i, j;

	scanf("%llu", &n);
	for (i = 0; i < n; i++) scanf("%llu", &a[i]);

	printf("%llu\n", solve());

	return 0;
}
