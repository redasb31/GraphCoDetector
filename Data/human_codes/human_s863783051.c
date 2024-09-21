#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Mod 1000000007
#define Max 1000
long long ans=1;

long p[Max][Max];

void node(long n,long k,long **tree,long in[],long node_num,long parent){
	long i;

	ans=(ans*p[k-2][in[node_num]-1])%Mod;

	for(i=1;i<=in[node_num];i++){
		if(tree[node_num][i]!=parent){
			node(n,k,tree,in,tree[node_num][i],node_num);
		}
	}
}

void root(long n,long k,long **tree,long in[]){
	long i;

	ans=p[k][in[1]+1]%Mod;

	for(i=1;i<=in[1];i++){
		node(n,k,tree,in,tree[1][i],1);
	}
}

int main(void){
	long i,j;

	for(i=1;i<Max;i++){
		p[i][0]=1;
		for(j=1;j<Max;j++){
			if(j>i) break;
			p[i][j]=(p[i][j-1]*(i-j+1))%Mod;
		}
	}

	long n,k;
	scanf("%ld%ld",&n,&k);

	long **tree,*tree_child;

	tree=malloc(sizeof(long *)*(n+1));
	tree_child=malloc(sizeof(long)*(n+1)*Max);
	for(i=0;i<=n;i++){
		tree[i]=tree_child+i*Max;
	}

	long a,b,in[n+1];

	for(i=1;i<=n;i++){
		in[i]=0;
	}

	for(i=1;i<n;i++){
		scanf("%ld%ld",&a,&b);
		in[a]++;
		tree[a][in[a]]=b;
		in[b]++;
		tree[b][in[b]]=a;
	}

	root(n,k,tree,in);

	printf("%lld\n",ans);

	free(tree_child);
	free(tree);

	return 0;
}
