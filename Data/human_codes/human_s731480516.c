#include <stdio.h>
#include <stdlib.h>
#define ll int
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

//ワーシャルフロイド
//頂点数（と隣接行列）を引いて全点間最短距離を返す
//O(V^3)
//*
ll cost[300][300];
ll dddd[300][300];
void waasharuhuroido(ll n){
	rep(i,0,n)rep(j,0,n)dddd[i][j]=cost[i][j];//辺が無いところはINFにする前処理が必要
	rep(k,0,n)rep(i,0,n)rep(j,0,n)dddd[i][j]=min(dddd[i][j],dddd[i][k]+dddd[k][j]);
}

int main(){
	rep(i,0,300)rep(j,0,300)cost[i][j]=i==j?0:1e9;
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);
		cost[x-1][y-1]=1;
	}
	waasharuhuroido(n);
	
	rep(i,0,n){
		int cnt=0;
		rep(j,0,n)if(dddd[i][j]!=1e9&&dddd[j][i]!=1e9)printf(cnt++?" %d":"%d",j+1);
		puts("");
	}
}
