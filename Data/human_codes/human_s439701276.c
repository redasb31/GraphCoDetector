#include<stdio.h>
#include<stdlib.h>
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
#define setmin(x,y) if(x>y){x=y;}
int n,k,s;
int tmp;
int x[2000],y[2000],z[2000],p[2000];
int inf = 1e9+7;
int g[2000][2000];
int is_connected(int i, int j) {
    int dx = abs(x[j] - x[i]);
    int dy = abs(y[j] - y[i]);
    int dz = abs(z[j] - z[i]);
    return dx <= s && dy <= s && dz <= s;
}
int intersecting_area(int i, int j) {
    if (!is_connected(i, j)) return 0;
    int dx = s - abs(x[j] - x[i]);
    int dy = s - abs(y[j] - y[i]);
    int dz = s - abs(z[j] - z[i]);
    return 2 * (dx * dy + dy * dz + dz * dx);
}
int dfs(int i, int prev, int depth, int first) {
    if (depth == k) {
        if (3 <= k && is_connected(i, first)) {
            return 6*s*s - intersecting_area(i, first);
        }
        return 6*s*s;
    } else {
        int ans = inf;
        for (int j=0;j<p[i];j++) if (g[i][j] != prev) {
            setmin(ans, 6*s*s - intersecting_area(i, g[i][j]) + dfs(g[i][j], i, depth + 1, first));
        }
        return ans;
    }
}
int main(void){
    while(1){
        scanf("%d%d%d",&n,&k,&s);
        if(n==0&&k==0&&s==0) break;
        rep(i,n) scanf("%d %d %d",&x[i],&y[i],&z[i]);
        rep(i,n){
            tmp=0;
            rep(j,n)
            if (i != j) {
                if (is_connected(i, j)) {g[i][tmp]=j; tmp++;}
            }
            p[i]=tmp;
        }
        int ans = inf;
        rep(i,n) setmin(ans, dfs(i, -1, 1, i));
        if (ans == inf) ans = -1;
        printf("%d\n",ans);
        /*rep(i,n){
            rep(j,p[i]){
                printf("%d ",g[i][j]);
            }
            puts("");
        }*/
    }
    return 0;
}

