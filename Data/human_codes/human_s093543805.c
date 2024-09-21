#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}


//座圧(破壊的)
int cocomp(ll*a,int n){
	//0～cnt-1に圧縮
	ll*b=(ll*)malloc(sizeof(ll)*n);
	memcpy(b,a,sizeof(ll)*n);
	sortup(b,n);
	int cnt=1;
	rep(r,1,n)if(b[r]!=b[cnt-1])b[cnt++]=b[r];
	rep(i,0,n){
		int l=0,r=cnt;
		while(r-l>1){int m=(l+r)/2;if(b[m]>a[i])r=m;else l=m;}
		a[i]=l;
	}
	free(b);
	return cnt;
}

ll a[200010];
ll cum[200010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		a[2*i]=x;
		a[2*i+1]=y+1;
	}
	cocomp(a,2*n);
	rep(i,0,n){
		cum[a[2*i]]++;
		cum[a[2*i+1]]--;
	}
	ll ans=cum[0];
	rep(i,0,2*n+5){
		cum[i+1]+=cum[i];
		ans=max(ans,cum[i+1]);
	}
	printf("%lld\n",ans);
}
