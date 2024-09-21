#include<stdio.h>
#define ll long long
#define MOD 1000000007

int main(){
	//公差d>0のときm+1-d(n-1)通り
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll S=m+1-(n-1);
	if(n==1||S<0){
		printf("%lld\n",(m+1)%MOD);
		return 0;
	}
	ll T=S%(n-1);
	ll c=(S-T)/(n-1)+1;
	ll ans=(S+T)%MOD*(c%MOD)%MOD;
	printf("%lld\n",(ans+m+1)%MOD);
}
