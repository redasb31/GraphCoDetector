#include<stdio.h>
#include<stdlib.h>
#define ll long long
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

ll a[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		a[t]=-1;
	}
	a[0]=1e9;
	for(int i=1;i<=n;i++){
		if(a[i]==-1)a[i]=0;
		else a[i]=a[i-1]+1;
	}
	sortdown(a+1,n);
	
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		t++;
		printf("%d\n",a[t]>=1e9?-1:a[t]+1);
	}
}
