#include<stdio.h>
int Y[]={1,0,-1,0};
int X[]={0,1,0,-1};
int main(){
  int h,w,i,j,r=1,t,ny,nx,gx,gy,x[100010],y[100010],d[100][100]={};
  char s,g,m[100][100]={};
  scanf("%d %d %c %c",&h,&w,&s,&g);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      scanf(" %c",&m[i][j]);
      if(m[i][j]==g){
	gy=i;
	gx=j;
      }
      if(m[i][j]==s)m[y[t=0]=i][x[0]=j]='.';
    }
  }
  for(r=1;r-t;t++){
    for(i=0;i<4;i++){
      ny=y[t]+Y[i]*2;
      nx=x[t]+X[i]*2;
      if(m[ny][nx]!='-'&&i%2   )continue;
      if(m[ny][nx]!='|'&&i%2==0)continue;
      for(j=1;1;j++){
	if(m[ny+Y[i]*j][nx+X[i]*j]=='o')break;
      }
      ny=ny+Y[i]*(j+1);
      nx=nx+X[i]*(j+1);
      if(m[ny][nx]=='.')continue;
      m[y[r]=ny][x[r]=nx]='.';
      d[y[r]][x[r]]=d[y[t]][x[t]]+1;
      r++;
    }
  }/*printf("\n");
  for(i=0;i<h;i++)printf("%s\n",m[i+1]+1);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++)printf("%d",d[i][j]);
    printf("\n");
    }printf("%d %d\n",gy,gx);//*/
  printf("%d\n",d[gy][gx]);
  return 0;
}

