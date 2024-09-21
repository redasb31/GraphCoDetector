#include <stdio.h>

#define INF 1000000001

int ruizyo(int n,int r) {
	long long nowmul=n;
	long long result=1;
	if(n>=INF)return INF;
	while(r>0) {
		if(r&1)result*=nowmul;
		if(result>=INF)return INF;
		nowmul*=nowmul;
		if(nowmul>INF)nowmul=INF;
		r>>=1;
	}
	return (int)result;
}

int main(void) {
	int n,T;
	char siki[1000]={};
	int i;
	int nowSteps=0;
	int parsing=0;
	scanf("%d%d",&n,&T);
	scanf("%s",siki);
	for(i=2;siki[i-1];i++) {
		if(isdigit(siki[i])) {
			if(parsing<1000000000)parsing=parsing*10+siki[i]-'0';
		} else {
			nowSteps+=ruizyo(n,parsing);
			if(nowSteps>INF)nowSteps=INF;
			parsing=0;
			i+=2;
		}
	}
	if((long long)nowSteps*T<=1000000000) {
		printf("%d\n",nowSteps*T);
	} else {
		puts("TLE");
	}
	return 0;
}