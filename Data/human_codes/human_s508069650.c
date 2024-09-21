#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p 998244353

typedef struct {
	int a;
	int b;
	int c;
}tuple;

int ABS(int a){
	return a >= 0 ? a : -a;
}

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

signed compare_tuple(const void *_a, const void *_b){
	tuple a = *(tuple *)_a, b = *(tuple *)_b;
	if(a.a != b.a){
		return a.a - b.a;
	}
	else{
		return a.b - b.b;
	}
}

int search(tuple *tps, int L, tuple tp){
	int l = -1, h, r = L;
	while(r - l > 1){
		h = (l + r) / 2;
		if(compare_tuple(&tps[h], &tp) < 0){
			l = h;
		}
		else{
			r = h;
		}
	}
	if(compare_tuple(&tps[r], &tp) == 0){
		return tps[r].c;
	}
	else{
		return -1;
	}
}

int coefficient(int c, int d, int b){
	if(c == -1 && d == -1){
		return 2;
	}
	else if(c == -1 || d == -1){
		return 1;
	}
	else if(c ^ d == b){
		return 1;
	}
	else{
		return 0;
	}
}

signed main(){
	int N, M, a, b, c, i, j, k;
	scanf("%lld%lld", &N, &M);
	tuple *in = (tuple *)malloc(sizeof(tuple) * M);
	tuple *out = (tuple *)malloc(sizeof(tuple) * M);
	for(i = 0, j = 0, k = 0; i < M; i++){
		scanf("%lld%lld%lld", &a, &b, &c);
		a--;
		b--;
		if(ABS(a - b) < 3){
			in[j] = (tuple){a, b, c};
			j++;
		}
		else{
			out[k] = (tuple){a, b, c};
			k++;
		}
	}
	int L_in = j, L_out = k;
	qsort(in, L_in, sizeof(tuple), compare_tuple);
	qsort(out, L_out, sizeof(tuple), compare_tuple);

	int f, rest;
	for(i = 0, j = 0, f = 1; i < L_out; i++){
		c = search(out, L_out, (tuple){out[i].b, out[i].a, 0});
		if(c == -1){
			j++;
		}
		else if(out[i].a < out[i].b){
			if(out[i].c ^ c == 0){
				j++;
			}
			else{
				f = 0;
			}
		}
	}
	if(f == 0){
		rest = 0;
	}
	else{
		rest = power(2, ((N - 2) * (N - 3)) / 2 - j);
	}
//	printf("j = %lld\n", j);
//	printf("rest = %lld\n", rest);

	int **dp = (int **)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		dp[i] = (int *)malloc(sizeof(int) * 2);
		for(j = 0; j < 2; j++){
			dp[i][j] = 0;
		}
	}
	int c0, c10, c11, c20, c21;
	c0 = search(in, L_in, (tuple){0, 0, 0});
	if(c0 == -1 || c0 == 0){
		dp[0][0] = 1;
	}
	if(c0 == -1 || c0 == 1){
		dp[0][1] = 1;
	}
	int k0, k1;
	for(i = 1; i < N; i++){
		c0 = search(in, L_in, (tuple){i, i, 0});
		c10 = search(in, L_in, (tuple){i, i - 1, 0});
		c11 = search(in, L_in, (tuple){i - 1, i, 0});
		c20 = search(in, L_in, (tuple){i + 1, i - 1, 0});
		c21 = search(in, L_in, (tuple){i - 1, i + 1, 0});
		if(c0 == -1 || c0 == 0){
			k0 = coefficient(c10, c11, 0) * coefficient(c20, c21, 0);
			k1 = coefficient(c10, c11, 1) * coefficient(c20, c21, 0);
			dp[i][0] = MOD(k0 * dp[i - 1][0] + k1 * dp[i - 1][1]);
		}
		if(c0 == -1 || c0 == 1){
			k0 = coefficient(c10, c11, 1) * coefficient(c20, c21, 1);
			k1 = coefficient(c10, c11, 0) * coefficient(c20, c21, 1);
			dp[i][1] = MOD(k0 * dp[i - 1][0] + k1 * dp[i - 1][1]);
		}
	}
/*	for(i = 0; i < N; i++){
		printf("dp[%lld] = (%lld, %lld)\n", i, dp[i][0], dp[i][1]);
	}
*/	printf("%lld\n", MOD(MOD((dp[N - 1][0] + dp[N - 1][1]) * power(2, p - 2)) * rest));
	return 0;
}