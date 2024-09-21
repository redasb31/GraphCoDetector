//set many funcs template
//Ver.20190714
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

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
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}
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
void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
void dbswap(double *a,double *b){double c;c=(*a);(*a)=(*b);(*b)=c;}
void chswap(char *a,char *b){char c;c=(*a);(*a)=(*b);(*b)=c;}
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

void shuffledget(int x[],int n){
    srand(time(0));
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={-1,-1,-1,0,0,1,1,1};
int dy8[8]={-1,0,1,-1,1,-1,0,1};

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

typedef struct{
long long val;
long long node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

void coordinate_comp(long long a[],long long n){
  long long i,c=1;
  sd dat[524288];
  for(i=0;i<n;i++){
    dat[i].val=a[i];
    dat[i].node=i;
  }
  qsort(dat,n,sizeof(dat[0]),sdsortfnc);
  a[dat[0].node]=c;
  for(i=1;i<n;i++){
    if(dat[i-1].val!=dat[i].val){c++;}
    a[dat[i].node]=c;
  }
}

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

long long modular_inverse(long long n){
	return power(n, mod-2);
}

long long inv2;

long long ssize=524288;
long long stree[1048576],lazy[1048576],vd=0;

void sinit(){
    inv2=modular_inverse(2);
    long long i,j;
    for(i=0;i<2*ssize;i++){
        stree[i]=0;
        lazy[i]=0;
    }
    return;
}

//lazy evaluation
void eval(long long k){
  if(lazy[k]!=0){
    stree[k]+=lazy[k];
    stree[k]%=mod;
    if(k<(ssize-1)){
      lazy[2*k+1]+=((lazy[k])*inv2);
      lazy[2*k+1]%=mod;
      lazy[2*k+2]+=((lazy[k])*inv2);
      lazy[2*k+2]%=mod;
    }
    lazy[k]=0;
  }
  return;
}

void upd(long long k,long long a){
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
    eval(0);
    for(i=w-1;i>0;i--){
      eval((2*mem[i])+1);
      eval((2*mem[i])+2);
    }
    stree[mem[0]]=a;
    lazy[mem[0]]=0;
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

//add +t [a,b)
//call:k=0,l=0,r=ssize
void addquery(long long a,long long b,long long t,long long k,long long l,long long r){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k);
    if(r<=a || b<=l){return;}
    if(a<=l && r<=b){
        lazy[k]+=(t*(r-l));
        lazy[k]%=mod;
        eval(k);
        return;
    }
    else{
        eval(k*2+1);
        eval(k*2+2);
        addquery(a,b,t,k*2+1,l,(l+r)/2);
        addquery(a,b,t,k*2+2,(l+r)/2,r);
        stree[k]=(stree[k*2+1]+stree[k*2+2])%mod;
        lazy[k]=0;
        return;
    }
}

//calc sum[a,b)
//call:k=0,l=0,r=ssize
long long sumquery(long long a,long long b,long long k,long long l,long long r){
    long long ld,rd,md;
    long long i,lp,rp;
    eval(k);
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        ld=sumquery(a,b,k*2+1,l,(l+r)/2);
        rd=sumquery(a,b,k*2+2,(l+r)/2,r);
        lp=0;rp=0;
        md=ld+rd;
        md%=mod;
        return md;
    }
}

int main(void){
  sinit();
  long long i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  long long x[524288],v[524288],sv[524288];
  long long bfa[524288],fsl[524288];
  sd dat[524288];
  scanf("%lld",&n);
  for(i=1;i<=n;i++){
    scanf("%lld%lld",&x[i],&v[i]);
  }
  coordinate_comp(&x[1],n);
  coordinate_comp(&v[1],n);
  for(i=1;i<=n;i++){
    sv[x[i]]=v[i];
  }
  bfa[1]=sv[1];
  for(i=2;i<=n;i++){
    bfa[i]=llmax(bfa[i-1],sv[i]);
  }
  fsl[n]=sv[n];
  for(i=n-1;i>=1;i--){
    fsl[i]=llmin(fsl[i+1],sv[i]);
  }
  for(i=1;i<=n;i++){
    dat[i].val=fsl[i];
    dat[i].node=bfa[i];
  }
  qsort(&dat[1],n,sizeof(sd[1]),sdsortfnc);
  addquery(0,1,1,0,0,ssize);
  for(i=1;i<=n;i++){
    w=sumquery(dat[i].val-1,dat[i].node+1,0,0,ssize);
    addquery(dat[i].node,dat[i].node+1,w,0,0,ssize);
  }
  printf("%lld\n",sumquery(n,n+1,0,0,ssize));
  return 0;
}
