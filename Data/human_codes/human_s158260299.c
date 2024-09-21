#include<stdio.h>
#include<stdbool.h>
#define MAX_N 200200
int par[MAX_N], rank[MAX_N];
void init(int n){for(int i=0; i<n; i++){par[i] = i;rank[i] = 0;}}
int root(int x){return par[x]==x?x:(par[x]=root(par[x]));}
bool same(int x, int y){return root(x) == root(y);}
void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y])rank[x]++;
    }
}
int sz[1<<18];
int N, M, ans = 0;
int main(){
	scanf("%d%d", &N, &M);
	init(N);
	while(M--){
		int A, B;
		scanf("%d%d", &A, &B);
		A--; B--;
		unite(A, B);
	}
	for(int i=0; i<N; i++){
		sz[par[i]]++;
		if(ans < sz[root(i)])ans = sz[root(i)];
	}
	printf("%d\n", ans);
	return 0;
}