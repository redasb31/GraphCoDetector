#include<stdio.h>
#include<math.h>

long long int N, P, F, ans, l, i, j, k;

int main(void){
	scanf("%lld%lld", &N, &P);
	if(N==1){printf("%lld\n", P);return 0;}
	if(P==1){printf("1\n");return 0;}
	ans=1;
	j=0;while(P%2==0){P/=2;j++;}if(j/N!=0){for(k=0; k<j/N; k++){ans*=2;}}
	j=0;while(P%3==0){P/=3;j++;}if(j/N!=0){for(k=0; k<j/N; k++){ans*=3;}}
	j=0;while(P%5==0){P/=5;j++;}if(j/N!=0){for(k=0; k<j/N; k++){ans*=5;}}
	for(i=5, l=sqrt(P)+1; i<l; i+=6){
		j=0;while(P%i==0){P/=i;j++;}if(j/N!=0){for(k=0; k<j/N; k++){ans*=i;}}
		j=0;while(P%(i+2)==0){P/=(i+2);j++;}if(j/N!=0){for(k=0; k<j/N; k++){ans*=(i+2);}}
	}
	printf("%lld\n", ans);
	return 0;
}
