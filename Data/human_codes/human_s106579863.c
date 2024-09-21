#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
#define MOD 998244353

ll n,a,b,k,ans;
ll fact[300010];
ll choose(ll n,ll r){return fact[n]*invp(fact[r]*fact[n-r],MOD)%MOD;}
int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	fact[0]=1;
	rep(i,0,n)fact[i+1]=fact[i]*(i+1)%MOD;
	rep(i,0,n+1){
		ll j=(k-i*a)/b;
		if(0<=j&&j<=n&&i*a+j*b==k)ans=(ans+choose(n,i)*choose(n,j))%MOD;
	}
	printf("%lld",ans);
}