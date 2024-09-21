//AWTF2019-D
#include<stdio.h>
#include<stdbool.h>
#define prime 10000000019

void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}
long long llsankaku(long long x){return ((1+x)*x)/2;}

long long calcul(long long p,long long q,long long z,long long *r,long long *b){
  long long f=0,cnt=0,w,i;
  (*r)=0;(*b)=0;
  if(p<q){f=1;llswap(&p,&q);}
  i=0;
  while(z>=0){
    w=z/q;
    cnt+=(w+1);
    (*r)+=i*(w+1);
    (*b)+=llsankaku(w);
    z-=p;
    i++;
  }
  if(f){llswap(r,b);}
  return cnt;
}

void calc(long long p,long long q,long long k,long long *r,long long *b){
  long long st,fi,te,c;
  st=0;fi=prime*4000;
  while(st<=fi){
    te=(st+fi)/2;
    c=calcul(p,q,te,r,b);
    if(c==k){break;}
    if(c<k){st=te+1;}
    if(c>k){fi=te-1;}
  }
}

bool ispossible(long long r,long long b,long long k){
  long long st,fi,te,zr,zb;
  st=1;fi=prime-1;
  while(st<=fi){
    te=(st+fi)/2;
    calc(te,prime-te,k,&zr,&zb);
    if(zr<=r && zb<=b){return true;}
    if(zr>r && zb>b){return false;}
    if(zr>r){st=te+1;}
    else{fi=te-1;}
  }
  return false;
}

long long solve(long long r,long long b){
  long long st=0,fi=4444444,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(ispossible(r,b,te)){st=te+1;}
    else{fi=te-1;}
  }
  return fi;
}

int main(){
  long long r,b;
  scanf("%lld%lld",&r,&b);
  printf("%lld\n",solve(r,b)-1);//-1 : empty box
  return 0;
}
