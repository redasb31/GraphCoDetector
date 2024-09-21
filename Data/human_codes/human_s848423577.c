#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,x[1010],y[1010],i,j,xm,ym,xp=0,yp=0,c=0,xc=0,yc=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
  for(i=0;i<n;i++){
    xm|=abs(x[i]);
    ym|=abs(y[i]);
    c|=abs(x[i]+y[i])%2+1;
  }
  for(i=xm;i>1;i/=2)xc++;
  for(i=ym;i>1;i/=2)yc++;
  if(xc+yc+4-c>40||c==3){
    printf("-1\n");
    return 0;
  }
  c--;
  printf("%d\n",xc+yc+2-c+2);
  for(i=xc;i;i--)printf("%d ",1<<i);
  printf("1 ");
  if(c%2==0)printf("1 ");
  for(i=yc;i;i--)printf("%d ",i<<i);
  printf("1 1\n");
  for(i=0;i<n;i++){
    xp=yp=0;
    for(j=xc;j>-1;j--){
      if(xp<x[i]){
	printf("R");
	xp+=1<<j;
      }
      else{
	printf("L");
	xp-=1<<j;
      }
    }
    if(c%2==0){
      if(xp<x[i]){
	printf("R");
	xp--;
      }
      else{
	printf("L");
	xp++;
      }
    }
    for(j=yc;j>-1;j--){
      if(yp<y[i]){
	printf("U");
	yp+=1<<j;
      }
      else{
	printf("D");
	yp-=1<<j;
      }
    }
    if(c%2==0){
      if(yp<y[i]){
	printf("U");
	yp++;
      }
      else{
	printf("D");
	yp--;
      }
    }
    if(c%2){
      //printf("%d %d %d %d ",xp,yp,x[i],y[i]);
      if(xp+1==x[i])printf("L");
      if(xp-1==x[i])printf("R");
      if(yp+1==y[i])printf("U");
      if(yp-1==y[i])printf("D");
    }
    printf("\n");
  }
  
  return 0;
}
