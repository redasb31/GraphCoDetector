#include<stdio.h>
#define M 1000000
int MIN(int a,int b){return a<b?a:b;}
int n,r=1,x[M],y[M],z[M],bv[M],gx,gy,gz,min,m[M]={0};
int f(int a,int b,int c,int d,int e){
  x[r]=a;
  y[r]=b;
  z[r]=c;
  bv[r]=d;
  m[r]=e;
  r++;
  //printf("%d %d %d %d\n",a,b,c,m[r-1]);
  //l=abs(a-gx)+abs(b-gy)+abs(c-gz);
  min=MIN(min,m[r-1]+abs(a-gx)+abs(b-gy)+abs(c-gz));
}
int main(){
  int t;
  scanf("%d",&n);
  scanf("%d %d %d %d %d %d",&x[0],&y[0],&z[0],&gx,&gy,&gz);
  bv[0]=9;
  m[0]=0;
  min=abs(x[0]-gx)+abs(y[0]-gy)+abs(z[0]-gz);//printf("min:%d\n",min);
  if(x[0]<n-1)f(x[0]+1,y[0]  ,z[0]  ,9,1);
  if(x[0]>0  )f(x[0]-1,y[0]  ,z[0]  ,9,1);
  if(y[0]<n-1)f(x[0]  ,y[0]+1,z[0]  ,9,1);
  if(y[0]>0  )f(x[0]  ,y[0]-1,z[0]  ,9,1);
  if(z[0]<n-1)f(x[0]  ,y[0]  ,z[0]+1,9,1);
  if(z[0]>0  )f(x[0]  ,y[0]  ,z[0]-1,9,1);
  for(t=0;r<M-10;t++){
    if(bv[t]-0&&gx-x[t])f(    x[t],    z[t],n-1-y[t],0,m[t]+1);//xto
    if(bv[t]-1&&gx-x[t])f(    x[t],n-1-z[t],    y[t],1,m[t]+1);//xhan
    if(bv[t]-2&&gx-x[t])f(    x[t],n-1-z[t],n-1-y[t],2,m[t]+2);//xw
    if(bv[t]-3&&gy-y[t])f(    z[t],    y[t],n-1-x[t],3,m[t]+1);//yto
    if(bv[t]-4&&gy-y[t])f(n-1-x[t],    y[t],    x[t],4,m[t]+1);//yhan
    if(bv[t]-5&&gy-y[t])f(n-1-x[t],    y[t],n-1-y[t],5,m[t]+2);//yw
    if(bv[t]-6&&gz-z[t])f(    y[t],n-1-x[t],    z[t],6,m[t]+1);//zto
    if(bv[t]-7&&gz-z[t])f(n-1-y[t],    x[t],    z[t],7,m[t]+1);//zhan
    if(bv[t]-8&&gz-z[t])f(n-1-y[t],n-1-x[t],    z[t],8,m[t]+2);//zw
  }
  printf("%d\n",min);
  return 0;
}