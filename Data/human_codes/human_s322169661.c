#include<stdio.h>
int dynamic(int[][2][3], int, int, int, int, int);
int main(void)
{
	int f1, f2, f3, N, M, C, P, temp = 0, dp[301][2][3], out, max[3];
	char name[31];
	while(scanf("%d %d",&N, &M) != EOF){
		out = 0;
		for(f1 = 0; f1 < 2; f1++){
			for(f2 = 0; f2 <= M; f2++){
				for(f3 = 0; f3 < 3; f3++){
					dp[f2][f1][f3] = 0;
					max[f3] = 0;
				}
			}
		}
		for(f1 = 0; f1 < N; f1++){
			temp = 0;
			fflush(stdin);
			gets(name);
			fflush(stdin);
			scanf("%d",&C);
			for(f2 = 0; f2 < 3; f2++){
				scanf("%d",&P);
				temp = dynamic(dp, f1 % 2, C, P, M, f2);
				if(temp > max[f2])
					max[f2] = temp;
			}
		}
		for(f1 = 0; f1 < 3; f1++){
			if(out < max[f1])
				out = max[f1];
		}
		printf("%d\n",out);
	}
	return 0;
}
int dynamic(int dp[][2][3], int flag, int cost, int rank, int M, int u){
	int f1, cnt = 0, temp, max = 0;
	for(f1 = 0; f1 <= M; f1++){
		dp[f1][flag][u] = 0;
	}
	while(cnt * cost <= M){
		temp = rank * cnt;
		for(f1 = M - cnt * cost; f1 >= 0; f1--){
			if(dp[f1][!flag][u] + temp > dp[f1 + cnt * cost][flag][u])
				dp[f1 + cnt * cost][flag][u] = dp[f1][!flag][u] + temp;
			else
				dp[f1][flag][u] = dp[f1][flag][u];
		}
		cnt++;
	}
	for(f1 = 0; f1 <= M; f1++){ 
		if(dp[f1][flag][u] > max)
			max = dp[f1][flag][u];
	}
	return max;
}