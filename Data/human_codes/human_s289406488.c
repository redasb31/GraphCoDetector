#include <stdio.h>
#include <string.h>

#define INF 100000000

int limit,n,m,x;
int sec_e[100],sec_s[100];
int e[100],s[100];

int memo[1001][100][101];

int tansaku(int nowmoney,int nowpos,int nowwaku) {
	int result;
	int nowresult;
	if(nowpos>=m || nowmoney<=0)return nowwaku<=0?0:-INF;
	if(memo[nowmoney][nowpos][nowwaku]!=0)return memo[nowmoney][nowpos][nowwaku]-1;

	result=tansaku(nowmoney,nowpos+1,nowwaku);
	if(nowmoney>=e[nowpos]) {
		nowresult=tansaku(nowmoney-e[nowpos],nowpos+1,nowwaku>0?nowwaku-1:nowwaku);
		nowresult+=s[nowpos];
		if(nowresult>result)result=nowresult;
	}

	memo[nowmoney][nowpos][nowwaku]=result+1;
	return result;
}

int main(void) {
	while(scanf("%d%d%d%d",&limit,&n,&m,&x)==4 && (limit|n|m|x)!=0) {
		int i,j;
		int maxscore;
		memset(memo,0,sizeof(memo));
		for(i=0;i<n;i++)scanf("%*s%d%d",&sec_e[i],&sec_s[i]);
		for(i=0;i<m;i++)scanf("%*s%d%d",&e[i],&s[i]);
		maxscore=0;
		for(i=0;i<n;i++) {
			for(j=i+1;j<=n;j++) {
				int nowscore,nowmoney;
				nowscore=sec_s[i];
				nowmoney=limit-sec_e[i];
				if(j<n) {
					nowscore+=sec_s[j];
					nowmoney-=sec_e[j];
				}
				if(nowmoney<0)continue;
				nowscore+=tansaku(nowmoney,0,x);
				if(nowscore>maxscore)maxscore=nowscore;
			}
		}
		printf("%d\n",maxscore);
	}
	return 0;
}