#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll ans;
void gcd(ll p,ll q){
	if(p%q){
		ll d=p/q;
		ans+=2*q*d;
		gcd(q,p%q);
	}else{
		ll d=p/q;
		ans+=q*(2*d-1);
	}
}

int main(){
	ll n,x;
	scanf("%lld%lld",&n,&x);
	gcd(x,n-x);
	printf("%lld\n",ans+n);
	return 0;
}