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
ll gcd(ll p,ll q){while(q){ll t=p%q;p=q;q=t;}return p;}

ll h[100010];
//*
//プラキュー（二分ヒープ）（最低限バージョン）
//int PQhikaku(int i,int j);//jの方が優先度が高いならtrueを返す
int PQhikaku(ll*heap,int i,int j){return heap[i]<heap[j];}
void heap_utod(ll*heap,int n){
	if(2*n>heap[0])return;
	int rflag=(2*n+1<=heap[0])&&(PQhikaku(heap,2*n,2*n+1));
	if(PQhikaku(heap,n,2*n+rflag)){
		ll temp=heap[2*n+rflag];
		heap[2*n+rflag]=heap[n];
		heap[n]=temp;
		heap_utod(heap,2*n+rflag);
	}
}
void heap_dtou(ll*heap,int n){
	if(n==1||PQhikaku(heap,n,n/2))return;
	ll temp=heap[n];
	heap[n]=heap[n/2];
	heap[n/2]=temp;
	heap_dtou(heap,n/2);
}
ll PQpop(ll*heap){
	ll rr=heap[1];
	heap[1]=heap[heap[0]--];
	heap_utod(heap,1);
	return rr;
}
void PQpush(ll*heap,ll n){
	heap[++heap[0]]=n;
	heap_dtou(heap,heap[0]);
}
//*/


ll a[100010],b[100010],idx[100010];
int c1(const void*p,const void*q){
	if(a[*(int*)p]-b[*(int*)p]<a[*(int*)q]-b[*(int*)q])return -1;
	return 1;
}
int c2(const void*p,const void*q){
	if(a[*(int*)p]<a[*(int*)q])return -1;
	if(a[*(int*)p]>a[*(int*)q])return  1;
	if(b[*(int*)p]>b[*(int*)q])return -1;
	return 1;
}
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld%lld",a+i,b+i),idx[i]=i;
	qsort(idx,n,sizeof(ll),c1);
	int cnt=0;
	while(cnt<n&&a[idx[cnt]]<b[idx[cnt]])cnt++;
	if(cnt==0){
		puts("0 1");
		return 0;
	}
	qsort(idx+cnt,n-cnt,sizeof(ll),c2);
	rep(i,0,cnt)PQpush(h,b[idx[i]]);
	ll s=0,pre;
	rep(i,0,cnt){
		if(s<a[idx[i]])s+=pre=PQpop(h);
		s-=a[idx[i]];
	}

	rep(i,cnt,n){
		if(s<a[idx[i]]){
			PQpush(h,b[idx[i]]);
			ll nex=PQpop(h);
			ll ppre=pre,nnex=nex,ss=s;
			if(pre<nex){
				ppre=nex;
				nnex=pre;
				ss=ppre-(pre-s);
			}
			if((a[idx[i]]-ss)*ppre+ss*nnex>=ppre*nnex)break;
			
			s+=nnex-a[idx[i]];
			pre=nnex;
		}else{
			PQpush(h,b[idx[i]]);
			s-=a[idx[i]];
		}
	}
	// (h[0] + s/pre)/n
	ll nume=h[0]*pre+s;
	ll deno=n*pre;
	ll d=gcd(nume,deno);
	printf("%lld %lld\n",nume/d,deno/d);
}