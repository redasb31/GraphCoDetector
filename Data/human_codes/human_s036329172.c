#include<stdio.h>
#include<string.h>

#define max(a,b) (a>b?a:b)

int mv[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int ori[10][10];
int map[10][10];
int fa[100];
int color[100];

int x,y,tar;

int find(int now){
  if(fa[now]==-1)return now;
  return fa[now] = find(fa[now]);
}

void chkun()
{
  int i,j,k;
  int dx,dy;
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      for(k=0;k<4;k++){
        dx = i + mv[k][0];
        dy = j + mv[k][1];
        if(0<=dx && dx<x && 0<=dy && dy<y){
          if(find(map[dx][dy])!=find(map[i][j]) && color[find(map[dx][dy])]==color[find(map[i][j])]){
            fa[find(map[dx][dy])] = find(map[i][j]);
          }
        }
      }
    }
  }
}

int dfs(int a,int b, int c, int d, int e){

    int i,j;

    memset(fa,-1,sizeof(fa));
    int cn = 0;
    int tem,total;

    for(i=0;i<x;i++){
      for(j=0;j<y;j++){

        tem = ori[i][j];
        map[i][j] = cn;
        color[cn] = tem;
        cn++;
      }
    }
    chkun();

    color[find(map[0][0])] = a;
    chkun();
    color[find(map[0][0])] = b;
    chkun();
    color[find(map[0][0])] = c;
    chkun();
    color[find(map[0][0])] = d;
    chkun();
    color[find(map[0][0])] = e;
    chkun();

    tem = find(map[0][0]);
    if(color[tem]!=tar)return 0;

    total = 0;
    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
        if(find(map[i][j])==tem)total++;
      }
    }
    return total;

}

int main()
{
  int i,j,k,l,m;
  int ans;
  while(scanf("%d%d%d",&x,&y,&tar)!=EOF){
    if(!(x+y+tar))break;
    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
        scanf("%d",&ori[i][j]);
      }
    }

    ans = 1;
    for(i=1;i<=6;i++){
      for(j=1;j<=6;j++){
        for(k=1;k<=6;k++){
          for(l=1;l<=6;l++){
            for(m=1;m<=6;m++){
              ans = max(ans,dfs(i,j,k,l,m));

            }
          }
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}