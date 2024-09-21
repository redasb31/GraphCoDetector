#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int n,m,p[100001],x[100001],y[100001];
int par[100001];

int find(int x){
    if (par[x]==x){
        return x;
    } else {
        return par[x]=find(par[x]);
    }
}

bool same(int x, int y){
    if (find(x)==find(y)){
        return true;
    } else {
        return false;
    }
}

void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return ;
    }
    par[x]=y;
}

int main(void){
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++){
        scanf("%d",&p[i]);
        par[i]=i;
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&x[i],&y[i]);
        unite(x[i],y[i]);
    }
    int ans=0;
    for (int i=0; i<n; i++){
        if (same(i,p[i]-1)==true){
            ans++;
        }
    }
    printf("%d\n",ans);
	return 0 ;
}