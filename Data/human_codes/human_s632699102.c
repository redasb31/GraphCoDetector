#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int main(){
	long n,i;
	long long a,s;
	long long ans;
	char op,f;
	scanf("%ld",&n);
	scanf("%lld",&a);
	f=0;
	ans=a;
	for(i=0;i<n-1;i++){
		scanf(" %c",&op);
		scanf("%lld",&a);
		if(f==0 && op=='-'){
			ans-=a;
			f=1;
			s=0;
		}else if(f==1 && op=='+'){
			s+=a;
		}else if(f==1 && op=='-'){
			a=max(s-a,a-s);
			ans+=a;
			s=0;
			f=2;
		}else{
			ans+=a;
		}
	}
	if(s>0){
		ans+=s;
	}
	printf("%lld\n",ans);
	return 0;
}
