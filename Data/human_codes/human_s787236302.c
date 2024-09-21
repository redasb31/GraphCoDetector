#include<stdio.h>
int m[15][15];
int gy,gx,w,h,rr;
int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};
char d[15][15];
short int f(int x,int y,short int c[15][15],short int b[150]){
  int i,j,k,t=0,r,ny,nx,min=1000;
  short int cc[15][15],cb[15000],qx[15000],qy[15000];
  qx[0]=x;//printf("\n");
  qy[0]=y;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++)cc[i][j]=c[i][j];
  }
  for(i=1;i<rr;i++)cb[i]=b[i];//printf("a\n");
  for(r=1;r-t;t++){
    for(i=0;i<4;i++){
      nx=qx[t]+X[i];
      ny=qy[t]+Y[i];
      if(d[ny][nx]=='#'||d[ny][nx]==0)continue;//printf("a\n");
      if(cc[ny][nx])continue;
      cc[qy[r]=ny][qx[r]=nx]=cc[qy[t]][qx[t]]+1;
      //printf("%d %d %d\n",ny,nx,cc[ny][nx]);
      if(d[ny][nx]=='X'){
	if(cb[m[ny][nx]]==0)continue;
	cb[m[ny][nx]]--;
	k=f(nx,ny,cc,cb);
	if(min>k)min=k;
	//if(k)return min;
	cb[m[ny][nx]]++;
	continue;
      }//printf("%3d %d %d\n",t,nx,ny);
      if(ny==gy&&nx==gx)return cc[ny][nx];
      r++;
    }
  }//printf("b\n");
  return min;
}
int main(){
  int i,j,k,ny,nx,r,t,co,x,y,qx[150],qy[150];
  short int c[15][15],b[150]={0};
  while(scanf("%d %d",&w,&h),w||h){
    for(i=0;i<15;i++){
      for(j=0;j<15;j++)d[i][j]=c[i][j]=m[i][j]=0;
    }
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
	scanf(" %c",&d[i][j]);
	if(d[i][j]=='S')d[ y=i][ x=j]='#';
	if(d[i][j]=='G')d[gy=i][gx=j]='.';
      }
    }
    c[y][x]=1;
    for(i=rr=1;i<=h;i++){
      for(j=1;j<=w;j++){
	if(m[i][j]==0&&d[i][j]=='X'){
	  m[qy[co=0]=i][qx[t=0]=j]=rr;
	  for(r=1;r-t;t++){
	    for(k=0;k<4;k++){
	      nx=qx[t]+X[k];
	      ny=qy[t]+Y[k];
	      if(d[ny][nx]-'X'||m[ny][nx])continue;
	      co++;
	      m[qy[r]=ny][qx[r]=nx]=rr;
	      r++;
	    }
	  }
	  b[rr++]=++co/2;
	}
      }
    }
    printf("%d\n",f(x,y,c,b)-1);
  }
  return 0;
}