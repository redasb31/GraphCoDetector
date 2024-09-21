#include <stdio.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	if(a >= 0){
		return a % p;
	}
	else{
		return p + a % p;
	}
}

signed main(){
	int n, m, k, ans;
	scanf("%lld%lld", &n, &m);
	if(n == 1 || n - 1 > m){
		printf("%lld\n", MOD(m + 1));
		return 0;
	}
	k = MOD(m / (n - 1));
	ans = MOD(MOD(m + 1) + MOD(k * MOD(2 * (m + 1) - (k + 1) * (n - 1))));
	printf("%lld\n", ans);
	return 0;
}