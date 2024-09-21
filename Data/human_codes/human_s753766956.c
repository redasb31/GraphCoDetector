//set many funcs template
//Ver.20181228
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384
#define cval 250000000000000000

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int nHr(int a,int b){return nCr(a+b-1,b);}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}
int sankaku(int x){return ((1+x)*x)/2;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}
long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llsankaku(long long x){return ((1+x)*x)/2;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}
int chsortfncsj(const void *a,const void *b){if(*(char *)a>*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}
int chsortfnckj(const void *a,const void *b){if(*(char *)a<*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}

void prarr(long long arr[],long long n){
  long long i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%lld",arr[i]);
  }
  printf("\n");
  return;
}

//パスカルの三角形のfloor C 0~floor C limまでの黒マスカウント
//但し、mod3で分類
//lucasの定理に基づくアルゴリズム
void digdp(long long floor,long long lim,long long res[4]){
    if(floor<lim){lim=floor;}
    long long dp[64][4][2]={0},i,j,w;
    //dp[今上から何桁目まで埋めたか][3で割った余り][下のbitによってはlimを超えうるかどうか];
    dp[63][0][1]=1;
    for(i=62;i>=0;i--){
        if(i%2==0){w=1;}else{w=2;}
        for(j=0;j<3;j++){
            //末尾bitが0
            dp[i][j][0]+=dp[i+1][j][0];
            if((lim&(1ll<<i))!=0){
                dp[i][j][0]+=dp[i+1][j][1];
            }
            else{
                dp[i][j][1]+=dp[i+1][j][1];
            }
            //0C1が起きるなら黒点にならないので遷移なし、起きないなら遷移あり
            if((floor&(1ll<<i))!=0){
                //末尾bitが1
                dp[i][(j+w)%3][0]+=dp[i+1][j][0];
                if((lim&(1ll<<i))!=0){
                    dp[i][(j+w)%3][1]+=dp[i+1][j][1];
                }
            }
        }
    }
    res[0]=dp[0][0][0]+dp[0][0][1];
    res[1]=dp[0][1][0]+dp[0][1][1];
    res[2]=dp[0][2][0]+dp[0][2][1];
    //prarr(res,3);
    //printf("\n");
}

//floor C st ~ floor C fiまでのmod 3別黒点の数
void rgdigdp(long long floor,long long st,long long fi,long long res[4]){
  if(st<0){st=0;}
  if(fi>floor){fi=floor;}
  if(st>fi){
    res[0]=0;
    res[1]=0;
    res[2]=0;
    return;
  }
  long long sr[4]={0},fr[4]={0};
  if(st!=0){
    digdp(floor,st-1,sr);
  }
  digdp(floor,fi,fr);
  res[0]=fr[0]-sr[0];
  res[1]=fr[1]-sr[1];
  res[2]=fr[2]-sr[2];
}

//nCr mod2
//Find the color of Pascal's Triangle
//based on Lucas's Theorem(https://mathtrain.jp/lucastheorem)
long long nCrbit(long long n,long long r){
if(n<0 || r<0){return 0;}
if(n<r){return 0;}
if((n|r)!=n){return 0;}
return 1;
}

long long n,x[16384],y[16384];
long long findcol(long long a,long long b){
    long long i,r=0,p,q;
    for(i=0;i<n;i++){
        if(a-x[i]<0 || b-y[i]<0){continue;}
        p=(a-x[i])+(b-y[i]);
        q=(b-y[i]);
        r^=nCrbit(p,q);
    }
    return r;
}

int main(void){
    long long i,j,m,k,a,b,c,d,h,w,r,l,t;
    long long base=-(1ll<<59),bm,np;
    long long get[4]={0},tot[4]={0};
    long long bx,by,hs;
    long long lx,hx;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
      scanf("%lld%lld",&x[i],&y[i]);
    }
    for(i=0;i<n;i++){
      //基準点からのズレ
      w=(x[i]-base)%3;
      //三角形の何段目か
      l=cval-x[i]-y[i];
      digdp(l,llinf,get);
      tot[w]+=get[0];
      tot[w]%=2;
      tot[(w+1)%3]+=get[1];
      tot[(w+1)%3]%=2;
      tot[(w+2)%3]+=get[2];
      tot[(w+2)%3]%=2;
    }
    for(i=0;i<3;i++){
      if(tot[i]==1){
            //printf("<%lld>\n",i);
            bm=i;break;
      }
    }
    np=base;
    for(i=59;i>=0;i--){
      c=0;
      for(j=0;j<n;j++){
        w=(x[j]-base)%3;
        l=cval-x[j]-y[j];
        //[領域の始点,領域の終点]
        rgdigdp(l,np-x[j],np+(1ll<<i)-1-x[j],get);
        c+=get[(3+bm-w)%3];
        c%=2;
      }
      //printf("%lld:%lld %lld\n",i,c,d);
      if(c==0){
        np+=(1ll<<i);
      }
    }
    bx=np;by=cval-bx;
    if(findcol(bx,by)==0){
      printf("<%lld %lld>\n",bx,by);
      return -1;
    }
    lx=bx;
    hx=bx;
    for(i=60;i>=0;i--){
      w=(1ll<<i);
      if(findcol(lx-w,cval-(lx-w))==1){
        lx-=w;
      }
      if(findcol(hx+w,cval-(hx+w))==1){
        hx+=w;
      }
    }
    printf("%lld %lld\n",lx,cval-hx);
    return 0;
}
