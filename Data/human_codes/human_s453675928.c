//AWTF2019-E
//Thanks to:
//http://kazune-lab.net/contest/2019/02/24/wtf19-open/#e---e

#include<stdio.h>
#define mod 1000000007

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b%2){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b/=2;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

long long inv[1024];

void invcalc(){
  long long i;
  for(i=0;i<1024;i++){
    inv[i]=modular_inverse(i);
  }
}

void indefinite_integral(long long f[1024]){
  long long i;
  for(i=1022;i>=0;i--){
    f[i+1]=inv[i+1]*f[i];
    f[i+1]%=mod;
  }
  f[0]=0;
}

long long fcalc(long long f[1024],long long x){
  long long i,r=0;
  if(x==0){
    return f[0];
  }
  if(x==1){
    for(i=0;i<1024;i++){
      r+=f[i];
      r%=mod;
    }
    return r;
  }
}

typedef struct{
  long long p[1024];
  long long q[1024];
  long long c;
}func;

void integral_ztx(func *a,func *b){
  long long w,i;

  //func_add
  for(i=0;i<1024;i++){
    (((func*)a)->p[i])+=(((func*)b)->p[i]);
    (((func*)a)->p[i])%=mod;
    (((func*)a)->q[i])+=(((func*)b)->q[i]);
    (((func*)a)->q[i])%=mod;
  }
  (((func*)a)->c)+=(((func*)b)->c);
  (((func*)a)->c)%=mod;

  w=fcalc(((func*)b)->p,0);
  (((func*)a)->p[0])+=mod;
  (((func*)a)->p[0])-=w;
  (((func*)a)->p[0])%=mod;

  w=fcalc(((func*)b)->q,0);
  (((func*)a)->q[0])+=mod;
  (((func*)a)->q[0])-=w;
  (((func*)a)->q[0])%=mod;

  w=((func*)b)->c;
  (((func*)a)->p[0])+=mod;
  (((func*)a)->p[0])-=w;
  (((func*)a)->p[0])%=mod;
}

void integral_xto(func *a,func *b){
  long long w,i;

  //func_dec
  for(i=0;i<1024;i++){
    (((func*)a)->p[i])+=mod;
    (((func*)a)->p[i])-=(((func*)b)->p[i]);
    (((func*)a)->p[i])%=mod;
    (((func*)a)->q[i])+=mod;
    (((func*)a)->q[i])-=(((func*)b)->q[i]);
    (((func*)a)->q[i])%=mod;
  }
  (((func*)a)->c)+=mod;
  (((func*)a)->c)-=(((func*)b)->c);
  (((func*)a)->c)%=mod;

  w=fcalc(((func*)b)->p,1);
  (((func*)a)->p[0])+=w;
  (((func*)a)->p[0])%=mod;

  w=fcalc(((func*)b)->q,1);
  (((func*)a)->q[0])+=w;
  (((func*)a)->q[0])%=mod;

  w=((func*)b)->c;
  (((func*)a)->q[0])+=w;
  (((func*)a)->q[0])%=mod;
}

void funcprint(func a){
  long long i;
  printf("p: ");
  for(i=0;i<1024;i++){
    if(a.p[i]!=0){
      printf("%lld x^%lld ",a.p[i],i);
    }
  }
  printf("\nq:(1/e)* ");
  for(i=0;i<1024;i++){
    if(a.q[i]!=0){
      printf("%lld x^%lld ",a.q[i],i);
    }
  }
  printf("\nc:%lld\n",a.c);
}

int main(){
  invcalc();
  long long n,i,j,k,l,m,t,w,v;
  long long a,b,c;
  char s[1024];
  func dp[1024][2][2][2];

  scanf("%lld%s",&n,s);

  for(i=0;i<1024;i++){
    for(j=0;j<2;j++){
      for(k=0;k<2;k++){
        for(l=0;l<2;l++){
          for(m=0;m<1024;m++){
            dp[i][j][k][l].p[m]=0;
            dp[i][j][k][l].q[m]=0;
          }
          dp[i][j][k][l].c=0;
        }
      }
    }
  }

  if(s[0]=='X'){
    dp[0][0][1][0].c=1;
  }
  else{
    dp[0][0][0][1].c=1;
    dp[0][1][1][1].p[0]=1;
    dp[0][1][1][1].c=mod-1;
  }

  for(i=1;i<n;i++){
    for(j=0;j<2;j++){
      for(k=0;k<2;k++){
        for(l=0;l<2;l++){
          indefinite_integral(dp[i-1][j][k][l].p);
          indefinite_integral(dp[i-1][j][k][l].q);
          dp[i-1][j][k][l].c=mod-dp[i-1][j][k][l].c;
          dp[i-1][j][k][l].c%=mod;
        }
      }
    }

    if(s[i]=='X'){
      //X_i-1<X_i
      integral_ztx(&dp[i][0][1][0],&dp[i-1][1][1][0]);
      integral_ztx(&dp[i][0][1][0],&dp[i-1][1][1][1]);
      //X_i-1>X_i
      integral_xto(&dp[i][0][1][0],&dp[i-1][0][0][1]);
      integral_xto(&dp[i][0][1][0],&dp[i-1][0][1][1]);
      integral_xto(&dp[i][0][1][0],&dp[i-1][1][0][1]);
      integral_xto(&dp[i][0][1][0],&dp[i-1][1][1][1]);
    }
    else{
      //X_i-1<X_i
      integral_ztx(&dp[i][1][1][1],&dp[i-1][0][1][0]);
      integral_ztx(&dp[i][1][1][1],&dp[i-1][0][1][1]);

      integral_ztx(&dp[i][0][0][1],&dp[i-1][1][1][0]);
      integral_ztx(&dp[i][0][0][1],&dp[i-1][1][1][1]);

      //X_i-1>X_i
      integral_xto(&dp[i][0][0][1],&dp[i-1][0][1][0]);
      integral_xto(&dp[i][0][0][1],&dp[i-1][0][1][1]);
      integral_xto(&dp[i][0][0][1],&dp[i-1][1][1][0]);
      integral_xto(&dp[i][0][0][1],&dp[i-1][1][1][1]);
    }
    //for(j=0;j<2;j++){
    //  for(k=0;k<2;k++){
    //    for(l=0;l<2;l++){
    //      printf("%d[%d,%d,%d]\n",i,j,k,l);
    //      funcprint(dp[i][j][k][l]);
    //    }
    //  }
    //}
  }

  a=0;b=0;c=0;

  for(i=0;i<2;i++){
    t=0;m=1;
    for(j=0;j<1024;j++){
      t+=modular_inverse(m);
      t%=mod;
      v=(m*t)%mod;
      v=(v*(mod-1))%mod;

      w=(m*dp[n-1][i][1][0].p[j])%mod;
      a+=w;
      a%=mod;
      w=(v*dp[n-1][i][1][0].p[j])%mod;
      b+=w;
      b%=mod;

      w=(m*dp[n-1][i][1][0].q[j])%mod;
      b+=w;
      b%=mod;
      w=(v*dp[n-1][i][1][0].q[j])%mod;
      c+=w;
      c%=mod;

      m*=(j+1);
      m%=mod;
    }
    w=(inv[2]*dp[n-1][i][1][0].c)%mod;
    c+=mod;
    c-=w;
    c%=mod;
    a+=w;
    a%=mod;
  }

  for(i=0;i<2;i++){
    t=0;m=1;
    for(j=0;j<1024;j++){
      t+=modular_inverse(m);
      t%=mod;
      v=(m*t)%mod;
      v=(v*(mod-1))%mod;

      w=(m*dp[n-1][i][0][1].p[j])%mod;
      w=(w*(mod-1))%mod;
      a+=w;
      a%=mod;
      w=(v*dp[n-1][i][0][1].p[j])%mod;
      w=(w*(mod-1))%mod;
      b+=w;
      b%=mod;

      w=(m*dp[n-1][i][0][1].q[j])%mod;
      w=(w*(mod-1))%mod;
      b+=w;
      b%=mod;
      w=(v*dp[n-1][i][0][1].q[j])%mod;
      w=(w*(mod-1))%mod;
      c+=w;
      c%=mod;

      m*=(j+1);
      m%=mod;
    }
    w=(inv[2]*dp[n-1][i][0][1].c)%mod;
    a+=mod;
    a-=w;
    a%=mod;
    c+=w;
    c%=mod;
  }

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      indefinite_integral(dp[n-1][i][j][1].p);
      a+=mod;
      a+=fcalc(dp[n-1][i][j][1].p,1);
      a-=fcalc(dp[n-1][i][j][1].p,0);
      a%=mod;

      indefinite_integral(dp[n-1][i][j][1].q);
      b+=mod;
      b+=fcalc(dp[n-1][i][j][1].q,1);
      b-=fcalc(dp[n-1][i][j][1].q,0);
      b%=mod;

      a+=dp[n-1][i][j][1].c;
      a%=mod;
      b+=mod;
      b-=dp[n-1][i][j][1].c;
      b%=mod;
    }
  }

  printf("%lld %lld %lld\n",a,b,c);
  return 0;
}
