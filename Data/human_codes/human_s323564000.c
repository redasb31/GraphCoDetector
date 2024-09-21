#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

int w[100010];
int deg[100010];

//辺の情報を個別に持つタイプ
typedef struct edge{ll s,g;}E;
typedef struct graph{
	int vcnt,ecnt;
	E  e[200010];//適宜変える(ecnt)
	int id[100010];//適宜変える(vcnt)
}G;
G g;

int esort(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}
void readgraph(){
	//適宜変える
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%d",w+i);
	rep(i,0,m){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--,y--;
		g.e[2*i].s=x;
		g.e[2*i].g=y;
		g.e[2*i+1].s=y;
		g.e[2*i+1].g=x;
		deg[x]++;
		deg[y]++;
	}
	g.vcnt=n;
	g.ecnt=2*m;
	qsort(g.e,g.ecnt,sizeof(E),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//番兵
}

int oya[100010];
//dfs
void dfs(int v,int pre){
	oya[v]=pre+1;
	rep(i,g.id[v],g.id[v+1]){
		if(!oya[g.e[i].g]){
			dfs(g.e[i].g,v);
		}
	}
}


int d[100010];

int q[100010],qcnt;
int main(){
	readgraph();
	dfs(0,-1);
	rep(i,0,g.vcnt)if(deg[i]==1)q[qcnt++]=i;
	rep(ii,0,qcnt){
		int i=q[ii];
		if(i==0)continue;
		int v=oya[i]-1;
		d[v]=max(d[v],w[i]+d[i]);
		deg[i]--;
		deg[v]--;
		if(deg[v]==1)q[qcnt++]=v;
	}
	int ans=w[0];
	rep(i,1,g.vcnt)if(deg[i])ans+=w[i];
	int ddd=0;
	rep(i,0,g.vcnt)ddd=max(ddd,d[i]);
	printf("%d\n",ans+ddd);
}
