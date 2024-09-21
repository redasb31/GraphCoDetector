#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
typedef long long ll;
typedef long double ld;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF (1LL<<60)
#define MOD1 1000000007
#define MAX_N (1 << 17)


void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a=c;}
ll max2(ll a,ll b){return a>=b?a:b;}
ll min2(ll a,ll b){return a>=b?b:a;}
ll minn(ll n, ll a[n]){ll b=INF;rep(i,0,n) b=min2(b,a[i]);return b;}
ll maxn(ll n, ll a[n]){ll b=-INF;rep(i,0,n) b=max2(b,a[i]);return b;}
ll ABS(ll a){return a>=0?a:(-a);}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

typedef struct{
    ll aa;
    ll bb;
}frequent;

int main(void){
    // char ;
    ll n,ans=0;
    scanf("%lld",&n);
    ll a[n],sum[n+1];
    sum[0]=0;
    rep(i,0,n){
        scanf("%lld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    sortup(sum,n+1);
    ll q=1;
    rep(i,0,n){
        if(sum[i]==sum[i+1]){
            q++;
        }else{
            ans+=q*(q-1)/2;
            q=1;
        }
    }
    ans+=q*(q-1)/2;
    // ll sum;
    // rep(i,0,n){
    //     sum=a[i];
    //     if(sum==0){
    //         ans++;
    //     }
    //     rep(j,i+1,n){
    //         sum+=a[j];
    //         if(sum==0) ans++;
    //     }
    // }
    printf("%lld\n",ans);
    return 0;
}
