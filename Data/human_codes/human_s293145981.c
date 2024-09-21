#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int N, A, B, C, i, j, s, k, l, t, ans = 0;
	scanf("%lld%lld%lld%lld", &N, &A, &B, &C);
	if(B % 2 == 1){
		printf("0\n");
		return 0;
	}
	int *fact = (int *)malloc(sizeof(int) * (N + 1));
	int *fact_inv = (int *)malloc(sizeof(int) * (N + 1));
	fact[0] = 1;
	for(i = 1; i <= N; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for(i = 2; i <= N; i++){
		fact_inv[i] = MOD(-(p / i) * fact_inv[p % i]);
	}
	for(i = 1; i <= N; i++){
		fact_inv[i] = MOD(fact_inv[i] * fact_inv[i - 1]);
	}
/*	for(i = 0; i <= N; i++){
		printf("(fact * fact_inv)[%lld] = %lld\n", i, MOD(fact[i] * fact_inv[i]));
	}
*/	for(i = 0; i <= A; i++){
		for(j = 0; i + 3 * j <= C; j++){
			s = C - i - 3 * j;
			k = B / 2;
			l = A + j;
			if(k == 0){
				t = 1;
			}
			else{
				t = MOD(fact[s + k - 1] * MOD(fact_inv[s] * fact_inv[k - 1]));
			}
			t = MOD(t * MOD(fact[l + k] * MOD(fact_inv[l] * fact_inv[k])));
			t = MOD(t * MOD(fact[l] * MOD(fact_inv[A - i] * MOD(fact_inv[i] * fact_inv[j]))));
			ans = MOD(ans + t);
		}
	}
	printf("%lld\n", ans);
	return 0;
}