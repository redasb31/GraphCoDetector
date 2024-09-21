#include<stdio.h>
#define rep(i,m) for(long long i=0; i<m; i++)
#define per(i,m) for(long long i=m-1; i>=0; i--)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define ROF(i,n,m) for(long long i=m-1; i>=n; i--)
#define SORT(v,n) do{sort(v,v+n);reverse(v,v+n);}while(0)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;

ll kaikai[11000]={};
ll KAI(ll m)
{
  if(kaikai[m])return kaikai[m];
  if(m<0) return 0;
  if(m==0) return 1;
  kaikai[m]=m*KAI(m-1)%MOD;
  return kaikai[m];
}

ll extGCD(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    *y -= a / b * *x;
    return d;
}

 
ll modinv(ll a) {
    ll x, y;
    extGCD(a, MOD, &x, &y);
    return (x % MOD + MOD) % MOD;
}


int main()
{
  ll n,a,ans=0,co[5100]={};
  scanf("%lld%lld",&n,&a);
  ll dp[5005][5005][3]={};
  co[0]=1;
  rep(i,5050)co[i+1]=co[i]*(n-a-1-i)%MOD*modinv(i+1)%MOD;
  dp[a][0][0]=1;
  ROF(i,1,a+1){
    rep(j,a+2){
      rep(k,3){
        if(k==0){
          dp[i-1][j][1]+=dp[i][j][k]*(i-1)%MOD;
          dp[i-1][j][1]%=MOD;
          dp[i][j+1][2]+=dp[i][j][k];
          dp[i][j+1][2]%=MOD;
        }
        else if(k==1){
          dp[i-1][j][0]+=dp[i][j][k]%MOD;
          dp[i-1][j][0]%=MOD;
          dp[i-1][j][1]+=dp[i][j][k]*(i-1)%MOD;
          dp[i-1][j][1]%=MOD;
          dp[i][j+1][2]+=dp[i][j][k]%MOD;
          dp[i][j+1][2]%=MOD;
        }
        else{
          dp[i-1][j][0]+=dp[i][j][k]%MOD;
          dp[i-1][j][0]%=MOD;
          dp[i-1][j][1]+=dp[i][j][k]*(i-1)%MOD;
          dp[i-1][j][1]%=MOD;
        }
      }
    }
  }
  rep(i,a+1){
    FOR(j,1,a+2){
      if(j>n-a)continue;
      ans+=dp[i][j][2]*KAI(i)%MOD*co[j-1]%MOD;
      ans%=MOD;
    }
  }
  rep(i,n-a){
    ans*=(i+1);
    ans%=MOD;
  }
  printf("%lld",ans);
}