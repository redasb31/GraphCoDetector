#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p-q<0?-1:1;
}

void run(void){
  int n,p;
  scanf("%d%d",&n,&p);
  int64 *d=(int64 *)calloc(n,sizeof(int64));
  int64 sumW=0;
  int64 sum=0;
  int i;
  for(i=0;i<n;i++){
    int64 w,b;
    scanf("%lld%lld",&w,&b);
    sumW+=(100-p)*w;
    d[i]=(100-p)*w+p*b;
    sum+=d[i];
  }
  qsort(d,n,sizeof(int64),cmp);
  int k=0;
  while(sum>sumW){
    sum-=d[n-1-k++];
  }
  printf("%d\n",k);
}

int main(void){
  run();
  return 0;
}
