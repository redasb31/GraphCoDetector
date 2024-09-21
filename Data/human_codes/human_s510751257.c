#include<stdio.h>
#include<string.h>
#define min(x,y) (x)<(y)?(x):(y)
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
typedef struct{
    int group;
    int spare;
}Data;
int h,w,s,all,t[32][32];
int rec[32][32][32][32];
Data dp[32][32][32][32];
Data max(Data x,Data y){
    if(x.group<y.group) return y;
    else if(x.group==y.group){
        if(x.spare<y.spare) return y;
        else return x;
    }
    else return x;
}
void mkRec(){
    memset(rec,0,sizeof(rec));
    rep(i,h){
        rep(j,w){
            rec[i][j][i][j]=t[i][j];
            for(int y=i-1;y>=0;y--)
                rec[y][j][i][j]=rec[y+1][j][i][j]+t[y][j];
            for(int y=i;y>=0;y--){
                int sum=0;
                for(int x=j;x>=0;x--){
                    sum+=rec[y][x][i][x];
                    rec[y][x][i][j]=sum;
                }
            }
        }
    }
}
Data dfs(int lx,int ly,int hx,int hy){
    if(dp[ly][lx][hy][hx].group!=0) return dp[ly][lx][hy][hx];
    Data res={1,s-(all-rec[ly][lx][hy][hx])};
    for(int i=ly;i<hy;i++){
        if(all-rec[ly][lx][i][hx]>s ||
           all-rec[i+1][lx][hy][hx]>s) continue;
        Data a=dfs(lx,ly,hx,i);
        Data b=dfs(lx,i+1,hx,hy);
        Data cal={a.group+b.group,min(a.spare,b.spare)};
        res=max(res,cal);
    }
    for(int j=lx;j<hx;j++){
        if(all-rec[ly][lx][hy][j]>s ||
           all-rec[ly][j+1][hy][hx]>s) continue;
        Data a=dfs(lx,ly,j,hy);
        Data b=dfs(j+1,ly,hx,hy);
        Data cal={a.group+b.group,min(a.spare,b.spare)};
        res=max(res,cal);
    }
    return dp[ly][lx][hy][hx]=res;
}
int main(){
    while(1){
        scanf("%d%d%d",&h,&w,&s);
        all=0;
        if(h+w+s==0) break;
        rep(i,h){
            rep(j,w){
                scanf("%d",&t[i][j]);
                all+=t[i][j];
            }
        }
        mkRec();
        memset(dp,0,sizeof(dp));
        Data d=dfs(0,0,w-1,h-1);
        printf("%d %d\n",d.group,d.spare);
    }
}

