#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void init(int *b){
  int n=b[0];
  int i;
  for(i=1;i<=n;i++) b[i]=0;
}

void add(int *b,int index,int v){
  int i;
  for(i=index;i<=b[0];i+=i&-i) b[i]+=v;
}

int sum(int *b,int index){
  int res=0;
  int i;
  for(i=index;i>0;i-=i&-i) res+=b[i];
  return res;
}

int *c=NULL;
int *bit=NULL;
int64 count(const int *a,const int n,const int v){
  c[0]=n+1;
  int i;
  for(i=1;i<=n;i++) c[i]=c[i-1]+(a[i-1]>=v?1:-1);
  init(bit);
  add(bit,c[0],1);
  int64 cnt=0;
  for(i=1;i<=n;i++){
    cnt+=sum(bit,c[i]);
    add(bit,c[i],1);
  }
  return cnt;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  c=(int *)malloc(sizeof(int)*(n+1));
  bit=(int *)malloc(sizeof(int)*(2*n+3));
  bit[0]=2*n+2;
  int64 t=(int64)n*(n+1)/2;
  int l=1;
  int r=1000000000+1;
  while(r-l>1){
    int m=(l+r)/2;
    int64 cnt=count(a,n,m);
    if(cnt>=t/2){
      l=m;
    } else {
      r=m;
    }
  }
  printf("%d\n",l);
  return;
}

int main(void){
  run();
  return 0;
}
