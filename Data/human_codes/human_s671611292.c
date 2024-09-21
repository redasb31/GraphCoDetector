#include<stdio.h>
int main(){
  int sx,sy,gx,gy,n,x,y,min,gmin,lx,ly,i,j,c,ny,nx;
  int m[410][210]={0};
  int t[410][210]={0};
  int X[]={0,1, 1, 0,-1,-1};
  int Y[]={2,1,-1,-2,-1, 1};
  scanf("%d %d %d %d %d",&sx,&sy,&gx,&gy,&n);
  while(n--){
    scanf("%d %d",&x,&y);
    x+=100;
    y+=100;
    m[y*2+x%2][x]=-1;
  }
  scanf("%d %d",&lx,&ly);
  sx+=100;
  sy+=100;
  gy+=100;
  gx+=100;
  min=1;
  gmin=1000;
  n=abs(sx+sy-gx-gy);//printf("n%d\n",n);
  sy=sy*2+sx%2;
  gy=gy*2+gx%2;//printf("gy%d gx%d\n",gy,gx);
  t[sy][sx]=0;
  while(min<gmin){//printf("%d\n",min);
    if(gy==sy&&gx==sx&&gmin>min)gmin=min;
    if(t[sy][sx]==100)m[sy][sx]=-2;
    m[sy][sx]++;
    t[sy][sx]++;
    for(i=0;i<6;i++){
      //printf("%d %d\n",sx-100,(sy-sx%2-200)/2);
      if(i==abs((sx-100)*((sy-sx%2-200)/2)*t[sy][sx])%6)c=0;
      else c=1;
      nx=sx+X[i];
      ny=sy+Y[i];//printf("%d %d\n",i,c);
      if(abs(nx-100)>lx||abs(ny-200)>ly*2+1)continue;
      if(m[ny][nx]<0)continue;
      if(m[ny][nx]>min+c||m[ny][nx]==0){
	 m[ny][nx]=min+c;//printf("%d %d\n",ny,nx);
	 t[ny][nx]=t[sy][sx]+1;
      }
    }
    min=1000;
    for(i=200-ly-ly-1;i<ly+ly+200+1;i++){
      for(j=100-lx;j<lx+100;j++){//printf("%3d",m[i*2+j%2][j]); 
	if(m[i][j]<1)continue;
	if(min>m[i][j])min=m[sy=i][sx=j];
      }//printf("\n");
    }
    /*for(i=190;i<210;i++){
      for(j=90;j<110;j++){
	if     (gy==i&&gx==j)printf("%03d",t[i][j]);
	else if(sy==i&&sx==j)printf("**%d",t[i][j]);
	else                 printf("%3d" ,t[i][j]);
      }
      printf("\n");
      }printf("min%d %d %d\n",min,sy,sx);//*/
  }
  if(gmin==1000)printf("-1\n");
  else   printf("%d\n",gmin-1);
  return 0;
}
  