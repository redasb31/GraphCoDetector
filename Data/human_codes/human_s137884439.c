#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)

//非再帰fft
void fft(ll*f,int n,ll g){
	ll p=7*(1<<26)+1;
	ll*x=f,*y=(ll*)malloc(n*sizeof(ll)),*temp;
	for(int t=1;n>>t;t++){
		ll s=1;
		ll gg=pom(g,n>>t,p);
		rep(k,0,1<<(t-1)){
			rep(j,0,n>>t){
				y[(j<<t)+k           ]= (x[(j<<(t-1))+k]+s*x[(j<<(t-1))+n/2+k])%p;
				y[(j<<t)+k+(1<<(t-1))]=((x[(j<<(t-1))+k]-s*x[(j<<(t-1))+n/2+k])%p+p)%p;
			}
			s=s*gg%p;
		}
		temp=x;x=y;y=temp;
	}
	if(x!=f){
		rep(i,0,n)f[i]=x[i];
		free(x);
	}else{
		free(y);
	}
}

ll*comb(ll*a,int n,ll*b,int m){
	//0詰め
	ll p=7*(1<<26)+1;
	int t=1;
	while(n+m-1>t)t*=2;
	if(t>(1<<26)){puts("error");exit(0);}
	ll*c=(ll*)calloc(t,sizeof(ll));
	memcpy(c,a,n*sizeof(ll));
	ll*d=(ll*)calloc(t,sizeof(ll));
	memcpy(d,b,m*sizeof(ll));
	//fft
	fft(c,t,pom(3,(p-1)/t,p));
	fft(d,t,pom(3,(p-1)/t,p));
	//掛け算
	rep(i,0,t)c[i]=c[i]*d[i]%p;
	free(d);
	//復元
	fft(c,t,pom(3,(p-1)-(p-1)/t,p));
	ll coef=invp(t,p);
	rep(i,0,t)c[i]=(c[i]*coef)%p;
	return c;
}

char s[200010],t[200010];
ll snum[200010],tnum[200010];
ll ans[400010];
int main(){
	scanf("%s %s",s,t);
    int sm=(s[0]=='-'),tm=(t[0]=='-');
    int sn=strlen(s+sm),tn=strlen(t+tm);
	for(int i=0;i<sn;i++)snum[i]=s[sn+sm-1-i]-'0';
	for(int i=0;i<tn;i++)tnum[i]+=t[tn+tm-1-i]-'0';
	ll*p=comb(snum,sn,tnum,tn);
	for(int i=0;i<sn+tn-1;i++)ans[i]=p[i];
	for(int i=0;i<400010;i++)ans[i+1]+=ans[i]/10,ans[i]%=10;
	int digit=0;
	for(int i=0;i<400010;i++)if(ans[i])digit=i;
	if((sm^tm)&&(digit>0||ans[0]!=0))printf("-");
	for(int i=digit;i>=0;i--)printf("%lld",ans[i]);
	puts("");
}
