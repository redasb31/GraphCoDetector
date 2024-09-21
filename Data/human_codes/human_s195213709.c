#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)(((n)>>(m))&1)
#define min(p,q)((p)<(q)?(p):(q))

ll a[20];
ll s[110];
ll ans[1<<15];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n){
		rep(i,0,n)scanf("%lld",a+i);
		rep(i,0,m)scanf("%lld",s+i);
		rep(i,1,1<<n)ans[i]=1e9;
		rep(i,1,1<<n){
			//もらうDP
			ll sum=0;
			rep(k,0,n)if(bit(i,k))sum+=a[k];
			rep(k,0,n)if(bit(i,k)){
				int be=i^(1<<k);
				ll temp=0;
				rep(x,0,m)if(sum-a[k]<=s[x]&&s[x]<sum)temp+=min(llabs(s[x]-(sum-a[k])),llabs(s[x]-sum));
				ans[i]=min(ans[i],ans[be]+temp);
			}
		}
		ll sum=0;
		rep(k,0,n)sum+=a[k];
		ll temp=0;
		rep(x,0,m)if(sum<=s[x])temp+=llabs(s[x]-sum);
		printf("%lld\n",ans[(1<<n)-1]+temp);
	}
}
