#include<stdio.h>
#define mod 998244353

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

long long ssize=524288,vd=0;

void sinit(long long stree[],long long lazy[]){
    long long i,j;
    for(i=0;i<2*ssize;i++){
        stree[i]=0;
        lazy[i]=1;
    }
    return;
}

//lazy evaluation
void eval(long long k,long long stree[],long long lazy[]){
  if(lazy[k]!=1){
    stree[k]*=lazy[k];
    stree[k]%=mod;
    if(k<(ssize-1)){
      lazy[2*k+1]*=lazy[k];
      lazy[2*k+1]%=mod;
      lazy[2*k+2]*=lazy[k];
      lazy[2*k+2]%=mod;
    }
    lazy[k]=1;
  }
  return;
}

void upd(long long k,long long a,long long stree[],long long lazy[]){
    long long i,m,w,l,r;
    long long mem[128];
    long long ld,rd,md;
    k+=ssize-1;
    mem[0]=k;
    w=1;
    while(k>0){
        k=(k-1)/2;
        mem[w]=k;
        w++;
    }
    l=0;r=ssize;
    eval(0,stree,lazy);
    for(i=w-1;i>0;i--){
      eval((2*mem[i])+1,stree,lazy);
      eval((2*mem[i])+2,stree,lazy);
    }
    stree[mem[0]]=a;
    lazy[mem[0]]=1;
    for(i=1;i<w;i++){
        k=mem[i];
        ld=stree[2*k+1];
        rd=stree[2*k+2];
        md=ld+rd;
        md%=mod;
        stree[k]=md;
    }
    return;
}

//multiple *t [a,b)
//call:k=0,l=0,r=ssize
void multquery(long long a,long long b,long long t,long long k,long long l,long long r,long long stree[],long long lazy[]){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k,stree,lazy);
    if(r<=a || b<=l){return;}
    if(a<=l && r<=b){
        lazy[k]*=t;
        lazy[k]%=mod;
        eval(k,stree,lazy);
        return;
    }
    else{
        eval(k*2+1,stree,lazy);
        eval(k*2+2,stree,lazy);
        multquery(a,b,t,k*2+1,l,(l+r)/2,stree,lazy);
        multquery(a,b,t,k*2+2,(l+r)/2,r,stree,lazy);
        stree[k]=(stree[k*2+1]+stree[k*2+2])%mod;
        lazy[k]=1;
        return;
    }
}

//calc sum[a,b)
//call:k=0,l=0,r=ssize
long long sumquery(long long a,long long b,long long k,long long l,long long r,long long stree[],long long lazy[]){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k,stree,lazy);
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        ld=sumquery(a,b,k*2+1,l,(l+r)/2,stree,lazy);
        rd=sumquery(a,b,k*2+2,(l+r)/2,r,stree,lazy);
        lp=0;rp=0;
        md=ld+rd;
        md%=mod;
        return md;
    }
}

int main(){
  long long ms[1048576],ml[1048576];
  long long ks[1048576],kl[1048576];
  long long n,k,a[524288];
  scanf("%lld%lld",&n,&k);
  long long iv=k-1;
  iv*=modular_inverse(k);iv%=mod;
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
  }
  sinit(ms,ml);
  sinit(ks,kl);
  for(int i=1;i<=k;i++){
    upd(a[i],1,ms,ml);
    upd(a[i],a[i],ks,kl);
  }
  long long res=0;
  long long niv=modular_inverse(k);
  for(int i=k+1;i<=n;i++){
    long long v;
    v=sumquery((i-k),ssize,0,0,ssize,ks,kl);
    v+=mod;
    v-=(((i-k)*sumquery((i-k),ssize,0,0,ssize,ms,ml))%mod);
    v%=mod;
    //printf("<%lld>\n",v);
    v*=niv;v%=mod;
    res+=v;res%=mod;
    multquery(0,ssize,iv,0,0,ssize,ms,ml);
    multquery(0,ssize,iv,0,0,ssize,ks,kl);
    upd(a[i],1,ms,ml);
    upd(a[i],a[i],ks,kl);
  }
  long long vv=k;
  for(int i=n-k+1;i<=n;i++){
    long long nniv=modular_inverse(vv);
    long long v;
    v=sumquery(i,ssize,0,0,ssize,ks,kl);
    v+=mod;
    v-=((i*sumquery(i,ssize,0,0,ssize,ms,ml))%mod);
    v%=mod;
    v*=nniv;v%=mod;
    res+=v;res%=mod;
    nniv=vv-1;
    nniv*=modular_inverse(vv);
    nniv%=mod;
    multquery(0,ssize,nniv,0,0,ssize,ms,ml);
    multquery(0,ssize,nniv,0,0,ssize,ks,kl);
    vv--;
  }
  printf("%lld\n",res%mod);
  return 0;
}