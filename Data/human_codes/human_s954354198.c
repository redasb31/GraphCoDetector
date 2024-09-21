#include<stdio.h>
#define mod 1000000007
int main(){
	int i,c=0;
	long long n,k,ans=1,yak[1000];
	scanf("%lld%lld",&n,&k);
	for(i=1;i*i<=n;i++){
		if(n%i==0)yak[c++]=i;
	}
	if(n!=yak[c-1]*yak[c-1]){
		for(i=0;i<c;i++){
		yak[c+i]=n/yak[c-1-i];
		}c*=2;
	}
	else{
		for(i=0;i<c-1;i++){
			yak[c+i]=n/yak[c-2-i];
		}c=c*2-1;
	}
	long long ans2=1;
	for(i=0;i<k;i++){
		ans2*=n;
		ans2%=mod;
		ans*=n;
		ans%=mod;
	}
	for(i=c-1;i>0;i--){
		long long tmp=(yak[i]-yak[i-1])*((n-n/yak[i])%mod);
		tmp%=mod;
		tmp=(tmp*(k-1))%mod;
		ans-=tmp;
		ans%=mod;
		if(ans<0)ans+=mod;
	}
	long long ans3=(-1+ans2-ans+mod)%mod;
	printf("%lld\n",ans3);
	return 0;
}