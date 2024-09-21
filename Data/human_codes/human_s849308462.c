#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))
ll gcd(ll p,ll q){for(ll t;q;)t=p%q,p=q,q=t;return p;}
ll exgcd(ll p,ll q,ll*x,ll*y){
	ll tx,ty,t,x2=0,y2=1;
	*x=1;*y=0;
	while(q){
		tx=*x-p/q*x2;*x=x2;x2=tx;
		ty=*y-p/q*y2;*y=y2;y2=ty;
		t=p%q;p=q;q=t;
	}
	return p;
}
//非素数での逆元
ll inv(ll a,ll p){
	ll x,y;
	ll d=exgcd(a,p,&x,&y);
	if(d!=1)return-1;
	return x>0?x:x+p;
}

int main(){
	ll A,B;
	scanf("%lld%lld",&A,&B);
	//(A*n)/B>0 && (A*n)%B<A && n<(A*n)/B+(A*n)%B となる最小のn<B
	//(A*n)%Bで全探索
	ll d=gcd(A,B);
	ll invA=inv(A/d,B/d);
	ll ans=INF;
	for(int r=d;r<A;r+=d){
		ll n=(r/d)*invA%(B/d);
		if((A*n)/B>0 && (A*n)%B<A && n<(A*n)/B+(A*n)%B)ans=min(ans,n);
	}
	printf("%lld\n",ans==INF?-1:ans*A);
}
