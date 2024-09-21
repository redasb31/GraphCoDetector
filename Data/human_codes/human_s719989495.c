#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long int int64;

void sort(int *a,int n){
  if(n<=1) return;
  int p=rand()%n;
  int pivot=a[p];
  a[p]=a[0];
  int cnt=1;
  int index=0;
  int l=1;
  int r=n;
  while(l<r){
    if(a[l]==pivot){
      cnt++;
      l++;
    } else if(a[l]<pivot){
      a[index++]=a[l++];
    } else {
      int swap=a[l];
      a[l]=a[r-1];
      a[r-1]=swap;
      r--;
    }
  }
  sort(a,index);
  sort(a+l,n-l);
  while(cnt--) a[index++]=pivot;
}

void run(void){
  int w,h;
  scanf("%d%d",&w,&h);
  int *p=(int *)calloc(w,sizeof(int));
  int i;
  for(i=0;i<w;i++) scanf("%d",p+i);
  int *q=(int *)calloc(h,sizeof(int));
  for(i=0;i<h;i++) scanf("%d",q+i);
  srand((unsigned)time(NULL));
  sort(p,w);
  sort(q,h);
  int x=0;
  int y=0;
  int64 sum=0;
  while(x<w && y<h){
    if(p[x]<=q[y]){
      sum+=(int64)p[x++]*(h+1-y);
    } else {
      sum+=(int64)q[y++]*(w+1-x);
    }
  }
  while(x<w) sum+=p[x++];
  while(y<h) sum+=q[y++];
  printf("%lld\n",sum);
}

int main(void){
  run();
  return 0;
}
