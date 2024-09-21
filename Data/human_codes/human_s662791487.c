#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define MOD 1000000007
typedef long long ll;
ll PMRS(ll N, ll P, ll M){
	if (P == 0){
		return 1;
	}else if (P % 2 == 0){
		ll t = PMRS(N, P/2, M); 
		return t * t % M;
	}else{
		return N * PMRS(N, P - 1, M) % M;
	}
}  

ll inv_Felmat(ll a, ll M){
	return PMRS(a, M - 2, M);
}

ll perm(ll n, ll k, ll M){
	if (k == 1) return n;
	return perm(n, k - 1, M) * (n - k + 1) % M;
}

ll comb(ll n, ll k, ll M){
	ll x = perm(n, k, M);
	ll y = perm(k, k, M);
	return x * inv_Felmat(y, M);
}

int main(){
	ll n, k, ans = 0;
	scanf("%lld%lld",&n,&k);
	if (n > k) k = n - 1;
	rep(i, k)	ans = (ans + comb(n, i, MOD) *comb(n - 1, i, MOD)) % MOD;
	printf("%lld", ans);
}
