#include<stdio.h>
int main(){
  int sx,sy,gx,gy,n,x,y,gmin=1000,min,lx,ly,i,j,k,c,ny,nx,d;
  int m[6][410][210]={0};
  int X[]={0,1, 1, 0,-1,-1,0};
  int Y[]={2,1,-1,-2,-1, 1,0};
  scanf("%d %d %d %d %d",&sx,&sy,&gx,&gy,&n);
  while(n--){
    scanf("%d %d",&x,&y);
    x+=100;
    y+=100;
    for(i=0;i<6;i++)m[i][y*2+x%2][x]=-1;
  }
  scanf("%d %d",&lx,&ly);
  sx+=100;
  sy+=100;
  gy+=100;
  gx+=100;
  min=1;
  n=abs(sx+sy-gx-gy);//printf("n%d\n",n);
  sy=sy*2+sx%2;
  gy=gy*2+gx%2;//printf("gy%d gx%d\n",gy,gx);
  min=1;
  while(min-1000){//printf("%d %d\n",r,t);
    m[d][sy][sx]=-1;
    for(i=0;i<7;i++){
      ny=sy+Y[i];
      nx=sx+X[i];//printf("%d %d\n",ny,nx);
      if(abs(nx-100)>lx+1||abs(ny-200)>ly*2+1)continue;
      if(m[d][ny][nx]==-1&&i-6)continue;
      if(i==abs((sx-100)*(sy-sx%2-200)/2*d)%6)c=0;
      else c=1;
      if(m[(d+1)%6][ny][nx]>min+c||m[(d+1)%6][ny][nx]==0){
	m[(d+1)%6][ny][nx]=min+c;//printf("%d\n",m[(d+1)%6][ny][nx]);
      }  
    }
    /*for(i=200-ly-ly;i<=200+ly+ly;i++){
      for(k=0;k<6;k++){
	for(j=100-lx;j<=100+lx;j++){
	  printf("%3d",m[k][i][j]);
	}printf("\t");
      }
      printf("\n");
      }printf("\n");//*/
    min=1000;
    for(i=200-ly-ly-1;i<=200+ly+ly+1;i++){
      for(j=100-lx-1;j<=100+lx+1;j++){
	for(k=0;k<6;k++){
	  if(m[k][i][j]<1)continue;
	  if(min>m[k][i][j])min=m[d=k][sy=i][sx=j];
	}
      }
    }
    if(sy==gy&&sx==gx)break;
  }
  if(min-1000)printf("%d\n",min-1);
  else        printf("-1\n");
  return 0;
}