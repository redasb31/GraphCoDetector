#include<stdio.h>
typedef long long ll;

int main(){
	ll n, a, b, old, now;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &old);
	ll ans = 0;
	for(int i = 1; i < n; ++i){
		scanf("%lld", &now);
		ans += (a * (now - old) > b ? b : a * (now - old));
		old = now;
	}
	printf("%lld\n", ans);
	return 0;
}