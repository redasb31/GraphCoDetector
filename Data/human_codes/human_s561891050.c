#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll f(ll x){
	if(x==1)return 0;
	return 1+(int)log2(x-1);
}

ll h,w;
char s[200][200];
int main(){
	scanf("%lld%lld",&h,&w);
	rep(i,0,h)scanf(" %s",s[i]);
	ll x=0,y=0;
	rep(i,0,h-1){
		int flag=1;
		rep(j,0,w)flag&=(s[i][j]==s[i+1][j]);
		x+=flag;
	}
	rep(j,0,w-1){
		int flag=1;
		rep(i,0,h)flag&=(s[i][j]==s[i][j+1]);
		y+=flag;
	}
	printf("%lld",f(h-x)+f(w-y));
}