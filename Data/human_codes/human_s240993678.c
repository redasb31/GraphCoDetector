#include<stdio.h>
#include<string.h>
int x[8000][2000],y[8000][2000];
char m[10000][10][10];
int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};
int main(){
  int w,h,i,j,min,ex,ey,nx,ny,tt,rr,t,r;
  while(scanf("%d %d",&h,&w),h||w){
    int c[10000][10][10]={0};
    min=500;
    for(i=tt=0;i<h;i++){
      for(j=0;j<w;j++){
	scanf(" %c",&m[0][i][j]);
	if(m[0][i][j]=='@'){
	  x[0][0]=j;
	  y[0][0]=i;
	  m[0][i][j]='.';
	  c[0][i][j]=1;
	}
	if(m[0][i][j]=='E'){
	  ex=j;
	  ey=i;
	  m[0][ey][ex]='.';
	}
      }
    }
    for(rr=1;rr-tt;tt++){
      t=0;
      for(r=1;t-r;t++){
	if(min<c[tt][y[tt][t]][x[tt][t]])break;
	for(i=0;i<4;i++){
	  nx=x[tt][t]+X[i];
	  ny=y[tt][t]+Y[i];
	  if(nx==ex&&ny==ey&&m[tt][ny][nx]=='.'){
	    min=c[tt][y[tt][t]][x[tt][t]];
	    break;
	  }
	  if(nx<0||w<=nx||ny<0||h<=ny)continue;
	  if(m[tt][ny][nx]=='#')continue;
	  if(m[tt][ny][nx]=='w')continue;
	  if(c[tt][ny][nx]&&c[tt][ny][nx]<c[tt][y[tt][t]][x[tt][t]]+1)continue;
	  if(m[tt][ny][nx]=='c'){
	    if(m[tt][ny+Y[i]][nx+X[i]]=='c')continue;
	    if(m[tt][ny+Y[i]][nx+X[i]]=='#')continue;
	    for(j=0;j<h;j++)strcpy(m[rr][j],m[tt][j]);
	    x[rr][0]=nx;
	    y[rr][0]=ny;
	    m[rr][ny][nx]='.';
	    c[rr][ny][nx]=c[tt][y[tt][t]][x[tt][t]]+1;
	    for(j=1;m[rr][ny+Y[i]*j][nx+X[i]*j]=='.';j++);
	    if(m[rr][ny+Y[i]*j][nx+X[i]*j]=='w'){
	      m[rr][ny+Y[i]*j][nx+X[i]*j]='.';
	    }
	    else {
	      j--;
	      m[rr][ny+Y[i]*j][nx+X[i]*j]='c';
	    }
	    rr++;
	  }
	  else{
	    x[tt][r  ]=nx;
	    y[tt][r++]=ny;
	    c[tt][ny][nx]=c[tt][y[tt][t]][x[tt][t]]+1;
	  }
	}
      }
    }
    if(500-min)printf("%d\n",min);
    else        printf("-1\n");
  }
  return 0;
}