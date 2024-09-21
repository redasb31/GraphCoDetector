#include<stdio.h>
#include<string.h>
#define ll long long
#define MOD 1000000007

//next_permutation
void nexp(ll*a,int cnt){
	int l=cnt-1,r=cnt-1;
	ll t;
	while(--l>=0&&a[l]>a[l+1]);
	if(l>=0){
		while(a[l]>a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)t=a[l],a[l]=a[r],a[r]=t;
}

ll a[10]={0,1,2,3,4,5,6,7,8,9};
char s[100010];
ll sum[10];
int main(){
	int r;
	scanf("%d%s",&r,s);
	int n=strlen(s);
	if(n==1&&r==0){
		puts("0");
		return 0;
	}

	ll p10=1;
	for(int i=n-1;i>=0;i--){
		int c=s[i]-'0';
		sum[c]=(sum[c]+p10)%MOD;
		p10=p10*10%MOD;
	}
	
	for(int i=0;i<3628800;nexp(a,10),i++)if(a[s[0]-'0']){
		ll ans=0;
		for(int k=0;k<10;k++)ans=(ans+sum[k]*a[k])%MOD;
		if(ans==r){
			for(int i=0;i<n;i++)printf("%d",a[s[i]-'0']);
			puts("");
			return 0;
		}
	}
	puts("-1");
}
