#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=998244353;

int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&0x01) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

int *fact=NULL;
int *iFact=NULL;
void init(int n){
  fact=(int *)calloc(n+1,sizeof(int));
  iFact=(int *)calloc(n+1,sizeof(int));
  fact[0]=1;
  int i;
  for(i=1;i<=n;i++) fact[i]=(int64)i*fact[i-1]%mod;
  iFact[n]=modPow(fact[n],mod-2);
  for(i=n-1;i>=0;i--) iFact[i]=(int64)(i+1)*iFact[i+1]%mod;
  return;
}

int comb(int n,int k){
  if(!(0<=k && k<=n)) return 0;
  return (int64)fact[n]*iFact[k]%mod*iFact[n-k]%mod;
}

void run(void){
  int k,n;
  scanf("%d%d",&k,&n);
  init(2*(n+k));
  int i;
  for(i=2;i<=2*k;i++){
    int64 ans=0;
    if(i%2!=0){
      int p=0;
      for(int j=1,l=i-1;j<=l;j++,l--) if(j<=k && l<=k) p++;
      for(int q=0;q<=p;q++){
	ans+=(int64)comb(p,q)*modPow(2,q)%mod*comb(n-q+(k-(2*p-q))-1,k-(2*p-q)-1)%mod;
	ans%=mod;
      }
    } else {
      int p=0;
      for(int j=1,l=i-1;j<l;j++,l--) if(j<=k && l<=k) p++;
      for(int q=0;q<=p;q++){
	ans+=(int64)comb(p,q)*modPow(2,q)%mod*comb(n-q+(k-1-(2*p-q))-1,k-1-(2*p-q)-1)%mod;
	ans%=mod;
	ans+=(int64)comb(p,q)*modPow(2,q)%mod*comb(n-1-q+(k-1-(2*p-q))-1,k-1-(2*p-q)-1)%mod;
	ans%=mod;
      }
    }
    printf("%lld\n",ans);
  }
}

int main(void){
  run();
  return 0;
}
