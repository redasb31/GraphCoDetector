#include<stdio.h>

long gcd(long a,long b){
	if(b>a){
long tmp =a;
a=b;
b=a;
}
long r=a%b;
while(r!=0){
a=b;
b=r;
r=a%b;
}
return b;
}

int main(){
	int n,m;
	char s[100001];
	char t[100001];
	scanf("%d%d%s%s",&n,&m,s,t);
	long long l,i,tmp;
	if(n>m)tmp=gcd(m,n);
	else tmp=gcd(n,m);
l=n*m/tmp;
	for(i=0;i<=n;i++){
				if(s[i*n/tmp]!=t[i*m/tmp]){
					puts("-1");
					return 0;
			}
	}
	printf("%lld\n",l);
	return 0;
}