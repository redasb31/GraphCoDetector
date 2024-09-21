#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define LL long long
#define DB double
#define INF 1145141919810364364
#define PI 3.14159265358979
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define FOR(i,a,n) for(i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
#define MOD 1000000007
//#define MOD 998244353
#define ERR 0.00000001
#define NUM 200010

void swap(LL* a,LL* b){LL tmp=*a;*a=*b;*b=tmp;}
void YN(int a){if(a==1)printf("Yes\n");if(a==0)printf("No\n");}
LL lpow(LL a,LL n){LL ans=pow(a,n)*10;if(ans%10<5)return ans/10;return ans/10+1;}
LL dup(LL a,LL d){if(a%d==0)return a/d;else return a/d+1;}
LL GCD(LL a,LL b){LL c=1,tmp=MAX(a,b);b=MIN(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
LL LCM(LL a,LL b){return a*b/GCD(a,b);}
int lcmp(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return 1;if(*(LL*)a<*(LL*)b)return -1;return 0;}
int lcmpr(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return -1;if(*(LL*)a<*(LL*)b)return 1;return 0;}
int ccmp(const void* a,const void* b){return *(char*)a-*(char*)b;}
int ccmpr(const void* a,const void* b){return *(char*)b-*(char*)a;}
int scmp(const void* a,const void* b){return strcmp((char*)a,(char*)b);}
int scmpr(const void* a,const void* b){return strcmp((char*)b,(char*)a);}
LL mod(LL a,LL m){if(a<0)return a%m+m;else return a%m;}
LL DIV(LL a,LL d){LL m=MOD,x=1,y=0,k;while(m){k=d/m;d-=k*m;swap(&m,&d);x-=k*y;swap(&x,&y);}return mod(a*mod(x,MOD),MOD);}
LL FAC(LL a){LL i,ans=1;FOR(i,1,a+1){ans*=i;if(MOD>0&&ans>MOD)ans%=MOD;}return ans;}
LL POW(LL a,LL n){LL ans=1;while(n>0){if(n&1)ans=ans*a%MOD;a=a*a%MOD;n>>=1;}return ans;}
LL fact[NUM],finv[NUM],inv[NUM];
void comi(){LL i;fact[0]=fact[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,NUM){fact[i]=fact[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
LL com(LL n,LL k){if(n<k||n<0||k<0)return 0;return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;}

LL pid=0,pnum=0,rpid[NUM];LL co[NUM],cpid[NUM],que[NUM];
LL judge(LL a,LL b){if(pnum<b||b==1)return 0;return cpid[que[a]]>cpid[que[b]]?1:0;}
void push(LL a,LL n){LL i=++pid,j=++pnum;rpid[i]=n,cpid[i]=a,que[j]=i;while(judge(j/2,j))que[j]=que[j/2],que[j/=2]=i;}
LL pop(){LL ans=rpid[que[1]],i=1,j;LL n=que[pnum--];que[1]=n;while(judge(i,j=i*2+judge(i*2,i*2+1)))que[i]=que[j],que[i=j]=n;return ans;}

int main(){
  LL N,i,ver=1,red=1,blue=0,p=1,q=2,r=3;
  scanf("%lld",&N);
  LL a[N*2-2],b[N*2-2],last[N+1],pre[N*2-2],col[N+1],ans[N+1];
  rep(i,N-1)scanf("%lld%lld",&a[i],&b[i]);
  rep(i,N-1)a[N-1+i]=b[i],b[N-1+i]=a[i];
  FOR(i,1,N+1)last[i]=-1,col[i]=-1;
  FOR(i,0,N*2-2)pre[i]=last[a[i]],last[a[i]]=i;
  push(INF,INF);
  col[1]=0;
  while(ver<INF){
    for(i=last[ver];i+1;i=pre[i]){
      if(col[b[i]]==-1){
        push(b[i],b[i]);
        col[b[i]]=(col[a[i]]+1)%2;
        if(col[b[i]]==0)red++;
        else blue++;
      }
    }
    ver=pop();
  }
  if(red<=N/3){
    FOR(i,1,N+1)if(col[i]==0)ans[i]=r,r+=3;
    FOR(i,1,N+1){
      if(col[i]==1){
        if(p<=N)ans[i]=p,p+=3;
        else if(q<=N)ans[i]=q,q+=3;
        else ans[i]=r,r+=3;
      }
    }
  }
  else if(blue<=N/3){
    FOR(i,1,N+1)if(col[i]==1)ans[i]=r,r+=3;
    FOR(i,1,N+1){
      if(col[i]==0){
        if(p<=N)ans[i]=p,p+=3;
        else if(q<=N)ans[i]=q,q+=3;
        else ans[i]=r,r+=3;
      }
    }
  }
  else{
    FOR(i,1,N+1){
      if(col[i]==0){
        if(p<=N)ans[i]=p,p+=3;
        else ans[i]=r,r+=3;
      }
      else{
        if(q<=N)ans[i]=q,q+=3;
        else ans[i]=r,r+=3;
      }
    }
  }
  FOR(i,1,N+1)printf("%lld ",ans[i]);

  //printf("%lld\n",ans);
	return 0;
}
