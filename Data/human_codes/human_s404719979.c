#include <stdio.h>
#include <string.h>

#define MAX 1000000

int coin[] = {1,5,10,50,100,500};
int c[6],dp[MAX*2][6];

int change(int money){
	int i;
	int res = 0;

	for(i=5;i>=0;i--){
		res += money / coin[i];
		money %= coin[i];
	}

	return res;
}

int solve(int rem,int idx){
	int i;
	int tmp,res=MAX;

	if(idx == 6){
		if(rem > 0) return MAX;
		return change(-rem);
	}
	if(dp[rem+MAX][idx] != -1) return dp[rem+MAX][idx];

	for(i=0;i<=c[idx] && i*coin[idx]<rem+coin[idx];i++){
		tmp = i + solve(rem-i*coin[idx],idx+1);
		if(tmp < res) res = tmp;
	}

	return dp[rem+MAX][idx] = res;
}

int main(void){
	int i;
	int p;

	while(scanf("%d",&p), p){
		memset(dp,-1,sizeof(dp));
		for(i=0;i<6;i++) scanf("%d",&c[i]);
		printf("%d\n",solve(p,0));
	}

	return 0;
}