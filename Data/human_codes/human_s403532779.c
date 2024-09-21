#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int H, W, K, i;
	scanf("%lld%lld%lld", &H, &W, &K);
	int *fact = (int *)malloc(sizeof(int) * (H + W + 1));
	fact[0] = 1;
	for(i = 1; i <= H + W; i++){
		fact[i] = MOD(fact[i - 1] * i);
	}
	int *inverse = (int *)malloc(sizeof(int) * (H + W + 1));
	inverse[0] = -1;
	inverse[1] = 1;
	for(i = 2; i <= H + W; i++){
		inverse[i] = MOD(-(p / i) * inverse[p % i]);
	}
	int *fact_inv = (int *)malloc(sizeof(int) * (H + W + 1));
	fact_inv[0] = 1;
	for(i = 1; i <= H + W; i++){
		fact_inv[i] = MOD(fact_inv[i - 1] * inverse[i]);
	}
	int ans = K, C = MOD(inverse[H + W] * MOD(inverse[H + W - 1] * MOD(H * W)));
	for(i = 1; i <= K; i++){
		ans = MOD(ans + 2 * MOD(C * MOD((i - 1) * (K - i + 1))) + (K - i + 1));
	}
	printf("%lld\n", MOD(ans * MOD(fact[H + W] * fact_inv[H + W - K])));
	return 0;
}