#include<stdio.h>
int main(){
  int n,m,i,x,y,dx=1,dy=1,t;
  int a[100010],b[100010],r=0;
  scanf("%d %d %d",&n,&x,&y);
  if(x<0){
    dx=-1;
    x=-x;
  }
  if(y<0){
    dy=-1;
    y=-y;
  }
  if((x+y+n)%2)goto END;
  m=(x+y)%n;
  m=(n-m)%n;//m=muda
  //printf("%d\n",m);
  if(n>(x+y)){
    if((m/2)>(x+y)){
      if((3*n-x-y)%2)goto END;
      t=(3*n-x-y)/2;printf("%d\n",t);
      printf("3\n");
      printf("%d 0\n",n*-1*dx);
      t=t-n;
      printf("%d %d\n",(t)*-1*dx,t*-1*dy);
      printf("%d %d\n",x*dx,y*dy);
      return 0;
    }
    else{
      printf("2\n");
      if((2*n-x-y)/2)goto END;
      t=(2*n-x-y)/2;//
      if(n>x+t){
	t=n-x-t;
	printf("%d %d\n",(n-t)*dx,t*dy);
	printf("%d %d\n",x*dx,y*dy);
	return 0;
      }
      else{
	printf("%d %d\n",(n-t)*dx,t*-1*dy);
	printf("%d %d\n",x*dx,y*dy);
      }
    }
  }
  else{
    if(m%2)goto END;
    //printf("%d\n",m);
    for(i=1;i*n<x;i++){
      a[r]=i*n;
      b[r++]=0;
    }
    
    t=b[r]=(i*n)-x-(m/2);
    t-=m/2;
    a[r++]=x+m/2;
    for(i=1;t+i*n<=y;i++){
      a[r]=x;
      b[r++]=t+n*i;
    }
    printf("%d\n",r);
    for(i=0;i<r;i++)printf("%d %d\n",a[i]*dx,b[i]*dy);
  }
  return 0;
 END:;
  printf("-1\n");
  return 0;
}
