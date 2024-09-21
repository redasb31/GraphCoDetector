#include<stdio.h>
#include<math.h>
#define REP(i,m,n) for(i=m;i<n;i++)
#define rep(i,n) REP(i,0,n)
int dfs(int,int);
int boad[110][110];
int w,h,xs,ys,xg,yg,n,c,d;
const char Dx[]={1,0,-1,0},Dy[]={0,1,0,-1};
int main(void){
  int x,y,i,j,a,b;

  while(1){
   
    scanf("%d %d",&w,&h);
    if(w==0 && h==0)break;
    scanf("%d %d",&xs,&ys);
    scanf("%d %d",&xg,&yg);
    scanf("%d",&n);
    
    for(i=0;i<110;i++){
      for(j=0;j<110;j++){
	boad[i][j]=-1;
      }
    }
    int k;
    for(k=0;k<n;k++){
      scanf("%d %d %d %d",&c,&d,&x,&y);
      
      if(d){a=4;b=2;}
      else {a=2;b=4;}
	for(i=y;i<y+a;i++){
	  for(j=x;j<x+b;j++){
	    boad[i][j]=c;
	  }
	}

    }
    c=boad[xs][ys];
 
  
    if(dfs(xs,ys))printf("OK\n");
    else printf("NG\n");
    /*for(i=0;i<15;i++){
      for(j=0;j<15;j++)
printf("%2d",boad[i][j]);
      printf("\n");
      }*/
  }
  return 0;
}
  
int dfs(int x,int y){
  int i;
  if(x<=0||x>w||y<=0||y>h||boad[x][y]!=c)return 0;
  if(x==xg && y==yg)return 1;
  
  boad[x][y]=-1;
  
rep(i,4)if(dfs(x+Dx[i],y+Dy[i]))return 1;
  return 0;
}