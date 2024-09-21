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
ll po(ll a,int n){ll x=1;while(n--)x*=a;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

//行列累乗
void matpom(ll*mat,int size,ll n,int m){
	ll*temp=(ll*)malloc(size*size*sizeof(ll));
	ll*ans=(ll*)malloc(size*size*sizeof(ll));

	rep(i,0,size)rep(j,0,size)ans[i*size+j]=i==j;
	while(n){
		if(n%2){
			rep(i,0,size*size)temp[i]=0;
			rep(i,0,size)rep(j,0,size)rep(k,0,size)temp[i*size+j]=(temp[i*size+j]+ans[i*size+k]*mat[k*size+j])%m;
			rep(i,0,size*size)ans[i]=temp[i];
		}
		rep(i,0,size*size)temp[i]=0;
		rep(i,0,size)rep(j,0,size)rep(k,0,size)temp[i*size+j]=(temp[i*size+j]+mat[i*size+k]*mat[k*size+j])%m;
		rep(i,0,size*size)mat[i]=temp[i];
		n/=2;
	}
	rep(i,0,size*size)mat[i]=ans[i];

	free(temp);
	free(ans);
}

ll a[16];
ll L,A,B,M;
char s[20];
int main(){
	ll ans=0;
	scanf("%lld%lld%lld%lld",&L,&A,&B,&M);
	ll l=sprintf(s,"%lld",A);
	ll r=sprintf(s,"%lld",A+(L-1)*B);
	rep(k,l,r+1){
		ll x,y,n;
		//初項xと項数nを求める
		if(k==l)x=A;
		else{
			x=po(10,k-1)/B*B+(A%B);
			if(x<po(10,k-1))x+=B;
			if(x>=po(10,k))continue;
		}
		
		if(k==r)y=A+(L-1)*B;
		else{
			y=po(10,k)/B*B+(A%B);
			if(y>=po(10,k))y-=B;
		}
		
//		printf("%lld %20lld %20lld\n",k,x,y);
		
		n=(y-x)/B+1;
		rep(i,0,16)a[i]=0;
		a[3]=a[6]=a[10]=a[11]=a[15]=1;	
		a[0]=a[5]=pom(10,k,M);
		matpom(a,4,n-1,M);
		ll base=(a[0]+a[2]+a[3])%M;
		ll diff=(a[4]+a[6]+a[7])%M;
		ans=(ans*pom(pom(10,n,M),k,M)+base*(x%M)+diff*(B%M))%M;
	}
	printf("%lld",ans);
}