#include<stdio.h>
long long N[2][400010],L[2][400010],T;
long long  hyouka(long long a,long long b){return a+b;}
long long MIN(lont lont a,lont lont b){return  a<b?a:b;}
void lsset(int n,int x){
  int i;
  for(T=1;T<n;T*=2);
  for(i=0;i<T;i++)N[x][T+i]=i<n?n-1:0;
  for(i=T-1;i;i--)N[x][i]=hyouka(N[x][i*2],N[x][i*2+1]);
}
void lasy(int i,int l,int r,int x){
  if(L[x][i]==0)return;
  N[x][i]=L[x][i];
  if(r-l>1){
    L[x][i*2  ]=L[x][i];
    L[x][i*2+1]=L[x][i];
  }
  L[x][i]=0;
}
void lsadd(int a,int b,int c,int i,int l,int r,int x){
  lasy(i,l,r,x);
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b){
    L[x][i]=MIN(c,L[x][i]);
    lasy(i,l,r,x);
  }
  else{
    lsadd(a,b,c,i*2  ,l,(l+r)/2,x);
    lsadd(a,b,c,i*2+1,(l+r)/2,r,x);
    N[x][i]=hyouka(N[x][i*2],N[x][i*2+1]);
  }
}
long long lsget(int a,int b,int i,int l,int r,int x){
  lasy(i,l,r,x);
  if(b<=l||r<=a)return 0;
  if(a<=l&&r<=b)return N[x][i];
  return hyouka(lsget(a,b,i*2,l,(l+r)/2,x),lsget(a,b,i*2+1,(l+r)/2,r,x));
}
int main(){
  long long n,m,ans=0,a,b,i,near;
  scanf("%lld %lld",&n,&m);
  lsset(n,0);
  lsset(n,1);
  ans=(n-2)*(n-2);//printf("%d\n",ans);
  for(i=0;i<n;i++)printf("%lld ",N[1][T+i]);printf("\n");
  for(i=0;i<m;i++){
    int j;
    //for(j=0;j<n;j++)printf("%lld ",lsget(j,j+1,1,0,T,0));printf("\n");
    //for(j=0;j<n;j++)printf("%lld ",lsget(j,j+1,1,0,T,1));printf("\n");
    scanf("%lld %lld",&a,&b);
    b--;
    if(b==0)continue;
    near=lsget(b,b+1,1,0,T,a-1);printf("%lld\n",near);
    ans-=near-1;
    lsadd(0,near,b,1,0,T,2-a);
  }
  printf("%lld\n",ans);
  return 0;
}
